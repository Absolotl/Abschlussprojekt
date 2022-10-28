#include <iostream>
#include <string>
#include <vector>
#include "createDatabase.h"
#include "C:/SQLite/sqlite-amalgamation-3390400/sqlite3.h"
#include <sqlite3.h>

//compile with:
//g++ createDatabase.cpp -l sqlite3 -o createDatabase.exe

int main()
{
	sqlite3 *DB;
	string sqlCreate = "CREATE TABLE MENU("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "BESCHREIBUNG   TEXT    NOT NULL, "
                      "PREIS          REAL    );";
	char *messageError;
	int exit = sqlite3_open("instance/menu.db", &DB);
	exit = sqlite3_exec(DB, sqlCreate.c_str(), NULL, 0, &messageError);
  
	if (exit != SQLITE_OK)
	{
		std::cerr << "Error creating table: "<< messageError << "\n";
		sqlite3_free(messageError);
		return 1;
	}
	else cout << "Table created successfully!" << std::endl;

	string sqlInsert;
	for (const auto &arr : menu)
	{
		sqlInsert.append("INSERT INTO MENU VALUES(");
		sqlInsert.append(std::to_string(arr.ID));
		sqlInsert.append(", '");
		sqlInsert.append(arr.Bezeichnung);
		sqlInsert.append("', '");
		sqlInsert.append(arr.Beschreibung);
		sqlInsert.append("', ");
		sqlInsert.append(std::to_string(arr.Preis));
		sqlInsert.append(");\n");
	}
	//cout << sqlInsert << std::endl;
  
	exit = sqlite3_exec(DB, sqlInsert.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		std::cerr << "Error inserting values: "<< messageError << "\n";
		sqlite3_free(messageError);
		return 1;
	}
	else cout << "Values inserted successfully!" << std::endl;
  
	sqlite3_close(DB);
	return 0;
}
