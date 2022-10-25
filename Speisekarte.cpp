#include <iostream>
#include <string>
#include <vector>
#include "Speisekarte.h"
#include "C:\SQLite\sqlite-amalgamation-3390400\sqlite3.h"

int main()
{
	sqlite3* DB;
	string sqlCreate = "CREATE TABLE MENU("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "BESCHREIBUNG   TEXT    NOT NULL, "
                      "PREIS          REAL    );";
	char* messaggeError;
    int exit = sqlite3_open("menu.db", &DB);
	exit = sqlite3_exec(DB, sqlCreate.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK)
    {
        std::cerr << "Error creating table: "<< messaggeError << "\n";
        sqlite3_free(messaggeError);
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
  
    exit = sqlite3_exec(DB, sqlInsert.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK)
    {
        std::cerr << "Error inserting values: "<< messaggeError << "\n";
        sqlite3_free(messaggeError);
    }
    else cout << "Values created successfully!" << std::endl;
  
    sqlite3_close(DB);
	return 0;
}