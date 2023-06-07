#include <iostream>
 #include "mysql_connection.h"
 #include <cppconn/driver.h>
 #include <cppconn/exception.h>
 #include <cppconn/resultset.h>
 #include <cppconn/statement.h>


 

using namespace std;

int main() {
 try {
        sql::Driver* driver;
        sql::Connection* con;

        // Create a MySQL Connector/C++ driver object
        driver = get_driver_instance();

        // Establish a connection to a MySQL server
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");

        if (con->isValid()) {
             cout << "yes" << endl;
        }

        // Clean up
        delete con;

    } catch (sql::SQLException& e) {
        // Handle any errors that occurred during the connection attempt
        cout << "Error connecting to MySQL: " << e.what() << endl;
    }

    return 0;
}