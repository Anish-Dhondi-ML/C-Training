#include <iostream>
#include <winsock2.h>
#include "Employee_1.h"
#include "Employee_2.h"
#include "Employee_3.h"
#include "Employee_6.h"
#include "Employee_7.h"

#include "TM.h"
#include "RM.h"
#include <winerror.h>
using namespace std;

int main()
{
    // Initialize Winsock
    WSADATA WSAData;
    int nResult = WSAStartup(MAKEWORD(2, 2), &WSAData);

    if (nResult != NO_ERROR)
    {
        cerr << "WSAStartup failed with error: " << nResult << endl;
        return 1;
    }

    // Create socket
    int nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (nSocket == INVALID_SOCKET)
    {
        cerr << "Socket creation failed with error: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    // Connect to server
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(9909);
    nResult = connect(nSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress));
    if (nResult == SOCKET_ERROR)
    {
        cerr << "Socket connection failed with error: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    cout << "Connected to server" << endl;

    // Main loop
    while (1)
    {
        int choice;
        cout << "Enter 1 for Employee, 2 for Training Manager, 3 for Reporting Manager, or 0 to exit: ";
        cin >> choice;

        switch (choice)
        {
        case(1):{

            int n=0;
            cout<<"Enter employee no: "<<endl;
            cin>>n;
            if(n == 1){
                employee1(nSocket);
            }
            if(n == 2){
                employee2(nSocket);
            }
            if(n == 3){
                employee3(nSocket);
            }
            if(n == 6){
                employee6(nSocket);
            }
            if(n == 7){
                employee7(nSocket);
            }
            break;

        }
            

        case(2):
            TM(nSocket);
            break;

        case(3):
            rm(nSocket);
            break;

        case(0):
            cout << "Exiting program" << endl;
            closesocket(nSocket);
            WSACleanup();
            return 0;

        default:
            cout << "Invalid choice, please try again" << endl;
        }
    }
}
