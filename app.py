from asyncio.windows_events import NULL
from flask import Flask, render_template, url_for, request, redirect
from flask_sqlalchemy import SQLAlchemy
from flask import send_file
from flask import send_from_directory
from datetime import date, datetime
import numpy as np
import pandas as pd
import sqlite3
from reportlab.pdfgen import canvas
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib import colors
import datetime

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///instance/menu.db'
db = SQLAlchemy(app)
conn = sqlite3.connect('instance/menu.db')
c = conn.cursor()
c.execute("create table if not exists Choice(id INTEGER primary key autoincrement, nr Integer, name varchar(40), ingridient varchar(80), prize REAL)")
selection = pd.read_sql_query("Select * from MENU", conn)
selection2 = pd.read_sql_query("Select * from choice", conn)

class Choice(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    nr = db.Column(db.Integer, nullable=False)
    name = db.Column(db.String(50), nullable=False)
    ingridient = db.Column(db.String(150), nullable=False)
    prize = db.Column(db.Float, nullable=False)
    def __repr__(self):
        return '<Task %r>' % self.id

@app.route('/', methods=("POST", "GET"))
def Html_table():
    conn = sqlite3.connect('instance/menu.db')
    c = conn.cursor()
    selection2 = pd.read_sql_query("Select * from choice", conn)
    c.execute("select sum(prize) from choice")
    for row in c.fetchall():
        summe = row[0]
        if summe == None:            
            summe = ''
    return render_template("index.html", column_names=['Name', 'Bezeichnung', 'Preis', 'Aktion'],
                            row_data=list(selection.values.tolist()),
                            row_data2=list(selection2.values.tolist()),
                            row_data3=summe, zip=zip)

#add
@app.route('/add/<int:id>', methods=['POST', 'GET'])
def add(id):
    print(request.method)
    if request.method == 'GET':
        print(request.method)
        conn = sqlite3.connect('instance/menu.db')
        c = conn.cursor()
        c.execute("create table if not exists Choice(id INTEGER primary key autoincrement, nr Integer, name varchar(40), ingridient varchar(80), prize REAL)")
        c.execute('select * from menu where id = ' + str(id))
        for row in c.fetchall():
            new_task = Choice(nr=row[0], name=row[1], ingridient=row[2], prize=row[3])
        try:
            db.session.add(new_task)
            db.session.commit()
            return redirect('/')
        except:
            print("There was an issue adding your task")
            return 'There was an issue adding your task'

#add + Beilage
@app.route('/beilage/<int:id>', methods=['POST', 'GET'])
def Test(id):
    global new_task
    conn = sqlite3.connect('instance/menu.db')
    c = conn.cursor()
    c.execute("create table if not exists Choice(id INTEGER primary key autoincrement, nr Integer, name varchar(40), ingridient varchar(80), prize REAL)")
    if request.method == 'POST':
        print("post")
        new_task.name = new_task.name + ', Beilage: '+ request.form['beilage']        
        print("beilage gewählt")
        try:            
            db.session.add(new_task)
            db.session.commit()
            return redirect('/')
        except:
            print("There was an issue adding your task (Beilage)")
            return 'There was an issue adding your task'
    else:
        c.execute('select * from menu where id = ' + str(id))
        print('id: '+ str(id))
        for row in c.fetchall():
            new_task = Choice(nr=row[0], name=row[1], ingridient=row[2], prize=row[3])     
        print('beilage wählen')
        return render_template("beilage.html", task = new_task)

#delete 
@app.route('/delete/<int:id>')
def Delete(id):
    task_to_delete = Choice.query.get_or_404(id)
    try:
        db.session.delete(task_to_delete)
        db.session.commit()
        return redirect('/')
    except:
        return "there was a problem deleting that task"

#finish order    
@app.route('/clear/', methods=['POST', 'GET'])
def ClearTable():
    print("creating pdf file")
    CreatePdf()
    print("droping table choice")
    conn = sqlite3.connect('instance/menu.db')
    c = conn.cursor()
    c.execute('drop table choice')
    c.execute("create table if not exists Choice(id INTEGER primary key autoincrement, nr Integer, name varchar(40), ingridient varchar(80), prize REAL)")
    return redirect('/')

#PDF
def CreatePdf():
    conn = sqlite3.connect('instance/menu.db')
    c = conn.cursor()
    c.execute('select * from choice')
    y = 640

    pdf = canvas.Canvas('Bestellung_' + str(datetime.date.today()) + '.pdf')
    filename = 'Bestellung_' + str(datetime.date.today()) + '.pdf'
    path = "C:\\Users\\Empfang\\Documents\\Eigene Dokumente\\Abschlussprojekt\\"
    print(path + filename)
    pdf.setTitle('Bestellung')
    pdf.setFont("Courier", 12)
    pdf.drawString(30, 800, 'PRIOKOM Informationstechnik GmbH')
    pdf.drawString(30, 780, 'Im Lehrer Feld 8')
    pdf.drawString(30, 760, '89081 Ulm')
    pdf.drawString(500, 800, str(datetime.datetime.now().strftime('%d.%m.%Y')))
    pdf.drawString(500, 780, str(datetime.datetime.now().strftime('%H:%M:%S')))
    pdf.line(30, 745, 570, 745)
    pdf.drawString(30, 700, 'Sehr geehrtes Team der Pizzeria Marco Polo,')
    pdf.drawString(30, 680, 'wir würden gerne folgende Bestellung aufgeben:')
    pdf.setFont("Courier", 10)
    for row in c.fetchall():
        pdf.drawString(30, y, '- ' + row[2])
        y -= 20
        pdf.drawString(40, y, '(' +  row[3] + ')')
        y -= 20
    pdf.setFont("Courier", 12)
    pdf.drawString(30, y-20, 'Mit freundlichen Grüßen')
    pdf.drawString(30, y-40, 'PRIOKOM Informationstechnik GmbH')
    pdf.save()

    return send_from_directory(path, filename, as_attachment=True)
    #return send_file(path, as_attachment=True)

if __name__== "__main__":
    app.run(debug=True)