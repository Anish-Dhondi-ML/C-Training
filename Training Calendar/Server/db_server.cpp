#include <iostream>

#include "mysql\mysql.h"

using namespace std;

int main() {
    std::cout << "code compiled"<<endl;

    MYSQL* conn;  // pointer to MySQL connection object

    conn = mysql_init(NULL);  // initialize connection object

    if (conn == NULL) {

    std::cerr << "Error: Failed to initialize MySQL connection object" << std::endl;

      exit(1);

    }

  // connect to MySQL database

  if (mysql_real_connect(conn, "127.0.0.1:3306", "root", "Karthickftw@2", "TrainingDB1", 0, NULL, 0) == NULL) {
    
    std::cerr << "Error: Failed to connect to MySQL database" << std::endl;

    exit(1);

}

  std::cout << "Connection successful" << std::endl;

  mysql_close(conn);  // close MySQL connection

  return 0;

}