#pragma once
#include <string>

#include "TrainingDB.cpp"
using namespace std;

int db_connection(string server, string username, string password, string database);
    
    //std::string server = "tcp://127.0.0.1:3306";
    //std::string username = "root";
    //std::string password = "root1234";
    //std::string database = "training";
