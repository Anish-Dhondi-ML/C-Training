#include<iostream>
#include<winsock.h>
#include<vector>
#include<sstream>
#include<map>

#include "mystructure.h"
#include "RMClass.h"
#include "TMClass.h"
#include "EmpClass.h"

using namespace std;

#define PORT 8808

std::map<int, std::pair<enum Emp, void*>> emp_sock_id;
std::vector<ApprovalStatus> state;

std::ostream& operator<<(std::ostream& os, const void*& obj) {
    // define how MyClass objects should be printed to an output stream
    return os;
}

class Training {
private:
    int nRet = 0;
    int nOptVal;
    int nOptLen = 0;
    struct sockaddr_in srv;
    char buff[sizeof(RegisterRequest)] = { 0, };

public:
    int nSocket;
    int nMaxFd;
    struct timeval tv;

    fd_set fr, fw, fe;

    void ProcessTheNewRequest();

    Training() {
        // Initialize the WSA variable
        WSADATA ws;
        if (WSAStartup(MAKEWORD(2, 2), &ws) < 0) {
            cout << endl << "WSA failed to initilize";
        }
        else {
            cout << endl << "WSA Initialized";
        }

        nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (nSocket < 0) {
            cout << endl << "The socket not opened";
            WSACleanup();
            exit(EXIT_FAILURE);
        }
        else {
            cout << endl << "The socket opened successfully";
        }

        //Initialize the enviroinment for sockaddr structure
        srv.sin_family = AF_INET;
        srv.sin_port = htons(PORT);
        srv.sin_addr.s_addr = INADDR_ANY;
        memset(&(srv.sin_zero), 0, 8);

        nOptVal = 0;
        nOptLen = sizeof(nOptVal);

        //setSocket
        nRet = setsockopt(nSocket, SOL_SOCKET, SO_REUSEADDR, (const char*)&nOptVal, nOptLen);
        if (!nRet) {
            cout << endl << "The setsockopt call successful";
        }
        else {
            cout << endl << "The setsocketopt call failed";
            WSACleanup();
            exit(EXIT_FAILURE);
        }

        //Bind the socket to the local port
        nRet = bind(nSocket, (sockaddr*)&srv, sizeof(sockaddr));

        if (nRet < 0) {
            cout << endl << "Fail to bind to local port";
            WSACleanup();
            exit(EXIT_FAILURE);
        }
        else {
            cout << endl << "Successfully bind to local port";
        }

        //Listen the request from Training (queues the requests)
        nRet = listen(nSocket, 5);
        if (nRet < 0) {
            cout << endl << "Fail to start to the local port";
            WSACleanup();
            exit(EXIT_FAILURE);
        }
        else {
            cout << endl << "Started listeming to the local port";
        }

        nMaxFd = nSocket;
        tv.tv_sec = 1;
        tv.tv_usec = 0;
    }
};

void Training::ProcessTheNewRequest() {

    if (FD_ISSET(nSocket, &fr)) {

        int nLen = sizeof(struct sockaddr);
        int temp = accept(nSocket, NULL, &nLen);

        send(temp, "Got the connection done successfully", 37, 0);

        recv(temp, buff, sizeof(RegisterRequest), 0);

        RegisterRequest reg_req;

        memcpy(&reg_req, buff, sizeof(reg_req));

        if (temp > 0) {

            if (reg_req.type == EMPLOYEE) {
                Employee* c = new Employee();
                emp_sock_id[temp] = std::make_pair(EMPLOYEE, c);
                c->setEmpSocketId(temp, reg_req.ID);
            }
            if (reg_req.type == REPORTING_MANAGER) {
                RM* c = new RM();
                emp_sock_id[temp] = std::make_pair(REPORTING_MANAGER, c);
                c->setRMSocketId(temp, reg_req.ID);
            }
            if (reg_req.type == TRAINING_MANAGER) {

                TM* c = new TM();
                emp_sock_id[temp] = std::make_pair(TRAINING_MANAGER, c);
                c->setTMSocketId(temp, reg_req.ID);
            }
        }
    }
    else {
        for (auto& it : emp_sock_id) {

            if (FD_ISSET(it.first, &fr)) {
                //Got the new message from the Employee
                //Just recv new message
                //Just queue that for new workes of your server to fulfil the req
                void* objPtr = it.second.second;

                if (it.second.first == EMPLOYEE) {

                    Employee* aPtr = static_cast<Employee*>(objPtr);
                    aPtr->ProcessNewMessage(emp_sock_id);

                }
                else if (it.second.first == REPORTING_MANAGER) {

                    RM* bPtr = static_cast<RM*>(objPtr);
                    bPtr->ProcessNewMessage(emp_sock_id);

                }
                else if (it.second.first == TRAINING_MANAGER) {

                    TM* cPtr = static_cast<TM*>(objPtr);
                    cPtr->ProcessNewMessage(emp_sock_id);

                }
                else {
                    cout << "Unknown object type" << endl;
                }
            }
        }
    }
}

int main() {

    Training* emp = new Training();

    while (1) {

        FD_ZERO(&emp->fr);
        FD_ZERO(&emp->fw);
        FD_ZERO(&emp->fe);

        FD_SET(emp->nSocket, &emp->fr);
        FD_SET(emp->nSocket, &emp->fe);

        for (auto& it : emp_sock_id) {
            FD_SET(it.first, &emp->fr);
            FD_SET(it.first, &emp->fe);
        }

        int nRet = select(emp->nMaxFd + 1, &emp->fr, &emp->fw, &emp->fe, &emp->tv);

        if (nRet > 0) {
            // When someone connects or communicate with a message over a dedicatde 
            // connection
            cout << endl << "Data on port....Processing now...";
            emp->ProcessTheNewRequest();

        }
        else if (nRet == 0) {
            // No connection or any communication request made or you
            // say that none of the socket descriptors are ready
        }
        else {
            // It failed and your application should show some useful message
            WSACleanup();
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
