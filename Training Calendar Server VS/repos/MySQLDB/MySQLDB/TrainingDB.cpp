#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


using namespace std;

int db_connection(string server, string username, string password, string database)
{   

    cout << endl;



    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;
    sql::PreparedStatement* pstmt;

    /* Create a connection */
    driver = get_driver_instance();
    con = driver->connect(server, username, password);

    if (con->isValid())
        cout << "\t HURRAY!!!!! Database connected \n \n " << endl;
    else {
        cout << "No" << endl;
        exit(1);
    }
    
    /* Connect to the MySQL test database */
    con->setSchema(database);

    //******* INSERTING INTO TABLE  ***********

    std::string query = "INSERT INTO emp_detail (empid, empname, deptid, rmid) VALUES (?, ?, ?, ?)";
    pstmt = con->prepareStatement(query);

    cout << "Do you want insert into the database(y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        
        pstmt->setInt(1, 10);
        pstmt->setString(2, "John");
        pstmt->setInt(3, 4);
        pstmt->setInt(4, 6);
        pstmt->execute();
        con->commit();
    }
    
    

    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM  emp_detail");

    int count = 0;
    while (res->next()) {
        
        cout << "Row Index: " << ++count << endl;
        cout << "\t... MySQL EMP_ID: ";
        cout << res->getInt(1) << endl;
        cout << "\t... MySQL EMP_NAME: ";
        cout << res->getString(2) << endl;
        cout << "\t... MySQL DEPT_ID: ";
        cout << res->getInt(3) << endl;
        cout << "\t... MySQL RM_ID: ";
        cout << res->getInt(4) << endl;

        cout << endl;
        
    }
    delete res;
    delete stmt;
    delete con;
    delete pstmt;



    cout << endl;

    return 0;
}