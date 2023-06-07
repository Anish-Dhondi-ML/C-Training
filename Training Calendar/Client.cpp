#include<iostream>
#include <stdio.h>
#include <winsock.h>
#include <string>
#define PORT 9909

#pragma pack(1)
using namespace std;

enum MessageType{
            NOMINATE_REQUEST,
            REGISTER_REQUEST,
};

struct RegisterRequest
{
    MessageType mgs;
    int ID;
    char role[20];
};

struct RegisterResponse
{
   char nominatedTrainings[30];
   char completedTrainings[30];
   char rejectedTrainings[30];
};

struct NominateRequest
{
    int id;
    char trainingName[20];
    int trainingID;
    int msg;
};

int main()
{
    //Initiate the Socket environment
    WSADATA w;
    int nRet = 0;

    sockaddr_in srv;

    RegisterResponse* res;

    nRet = WSAStartup(MAKEWORD(2, 2), &w);
    if (nRet < 0)
    {
        printf("\nCannot Initialize socket lib");
        return -1;
    }

    //Open a socket - listener
    int nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (nSocket < 0)
    {
        //errno is a system global variable which gets updated
        //with the last API call return value/result.
        printf("\nCannot Initialize listener socket:%d", errno);;
        return -1;
    }

    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = inet_addr("127.0.0.1");
    srv.sin_port = htons(PORT);
    memset(&(srv.sin_zero), 0, 8);

    nRet = connect(nSocket, (struct sockaddr*)&srv, sizeof(srv));
    if (nRet < 0)
    {
        printf("\nCannot connect to server:%d", errno);;
        return -1;
    }

    //Keep sending the messages 
    char sBuff[1024] = { 0, };
    char rBuff[sizeof(RegisterResponse)] = {0,};

while (1)
{

getchar();
Sleep(2000);
printf("\nSending Data..?\n");
RegisterRequest tc;

tc.mgs = REGISTER_REQUEST;
tc.ID = 1;
strncpy(tc.role,"Manager",sizeof(tc.role));

const char* request_buffer = reinterpret_cast<const char*>(&tc);
send(nSocket, request_buffer, sizeof(RegisterRequest), 0);    

int nRet = recv(nSocket, rBuff, sizeof(RegisterResponse), 0);
cout << "Received from server" << endl;

RegisterResponse res;
memcpy(&res, rBuff, sizeof(res));

cout << "Nominated Trainings: " << res.nominatedTrainings << endl;
cout << "Completed Trainings: " << res.completedTrainings << endl;
cout << "Rejected Trainings: " << res.rejectedTrainings << endl;

}
 closesocket(nSocket);
}
