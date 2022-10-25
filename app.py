from flask import Flask, render_template, url_for, request, redirect
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime
import numpy as np
import pandas as pd
import sqlite3

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///instance/menu.db'
db = SQLAlchemy(app)

conn = sqlite3.connect('instance/menu.db')
c = conn.cursor()
c.execute("create table if not exists Choice(id INTEGER primary key, Name TEXT, Zutat Text, Preis REAL)")
df = pd.read_sql_query("Select * from MENU", conn)
row_data=list(df.values.tolist())
localID = 0

class Choice(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    Name = db.Column(db.String(50), nullable=False)
    Zutat = db.Column(db.String(150), nullable=False)
    Preis = db.Column(db.Float, nullable=False)
    def __repr__(self):
        return '<Task %r>' % self.id


@app.route('/', methods=("POST", "GET"))
def Html_table():
    return render_template("index.html", column_names=['name', 'zutat', 'preis', 'aktion'],
                            row_data=list(df.values.tolist()), zip=zip)


@app.route('/add/<int:id>', methods=['POST', 'GET'])
def Test(id):
    if request.method == 'GET':
        global localID
        print("get")
        conn = sqlite3.connect('instance/menu.db')
        c = conn.cursor()
        c.execute('select * from menu where id = ' + str(id))
        for row in c.fetchall():
            new_task = Choice(id=localID, Name=row[1], Zutat=row[2], Preis=row[3])
            localID += 1

        df = pd.read_sql_query("Select * from Choice", conn)

        try:
            db.session.add(new_task)
            db.session.commit()
            print("hallo")
            #return redirect('/')
            return render_template("index.html", row_data2=list(df.values.tolist()), zip=zip)
        except:
            print("There was an issue adding your task")
            return 'There was an issue adding your task'
    elif request.method == 'POST':
        print("post")
        return redirect('/')
    else:
        print("no post, no get")
        tasks = Choice.query.order_by(Choice.id).all()
        return render_template("index.html", row_data2=list(df.values.tolist()), zip=zip)
    
#delete Task 
@app.route('/delete/<int:id>')
def Delete(id):
    task_to_delete = Choice.query.get_or_404(id)

    try:
        db.session.delete(task_to_delete)
        db.session.commit()
        return redirect('/')
    except:
        return "there was a problem deleting that task"

if __name__== "__main__":
    app.run(debug=True)