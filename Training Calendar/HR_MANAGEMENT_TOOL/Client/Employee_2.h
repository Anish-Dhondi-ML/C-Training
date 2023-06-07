#ifndef EMPLOYEE_2_H
#define EMPLOYEE_2_H

#include <iostream>
#include <string>
#include <vector>
#include <winsock.h>

#include "..\Server\mystructure.h"

using namespace std;

#pragma pack(1)

void receive_Employee2_vector(int nSocket){

int vectorSize;
recv(nSocket, (char*)&vectorSize, sizeof(vectorSize), 0);
vector<ApprovalStatus> requests(vectorSize);
if (vectorSize > 0) {
    recv(nSocket, (char*)requests.data(), vectorSize * sizeof(ApprovalStatus), 0);
    for (ApprovalStatus a : requests) {
        cout<< a.employee_Id <<endl;
        cout << a.courseId << endl;
        cout << EmployeeStrings[a.Emp_state] << endl;
        cout << RMStrings[a.RM_state] << endl;
        cout << TMStrings[a.TM_state] << endl;
    }
} else {
    cout << "No requests" << endl;
    // or exit the function/program gracefully
}


}

void employee2(int nSocket){
     
        //Keep sending the messages 
        char rBuff[37] = { 0, };

        recv(nSocket, rBuff, 37, 0);
        std::cout << std::endl << rBuff << std::endl;

        RegisterRequest tc;
        tc.type = EMPLOYEE;
        tc.ID = 2;
        
        const char* request_buffer = reinterpret_cast<const char*>(&tc);
        send(nSocket, request_buffer, sizeof(RegisterRequest), 0);
        int choice = 0;

        while (1)
        {
            getchar();
            Sleep(2000);
            printf("\nSending Data..?\n");
            std::cout << "Enter '1' NOMINATE REQUEST\n"
                      << "'2' RETRIEVE PENDING REQUEST\n"
                      << "'3' RETRIEVE ACTIVE REQUEST\n"
                      << "'4' EMPLOYEE APPROVAL STATE\n";
            cin >> choice;
            MessageType mgs;
            if (choice == 1) {
                mgs = MessageType::NOMINATE_REQUEST;
            }
            if (choice == 2) {
                mgs = MessageType::EMPLOYEE_PENDING_REQUEST;
            }
            if (choice == 3) {
                mgs = MessageType::EMPLOYEE_ACTIVE_REQUEST;
            }
            if (choice == 4) {
                mgs = MessageType::EMPLOYEE_APPROVAL_STATE;
            }

            switch (mgs)
            {
                case MessageType::NOMINATE_REQUEST:
                {
                    NominateRequest n;
                    n.mgs = MessageType::NOMINATE_REQUEST;
                    n.trainingID = 10;
                    send(nSocket, (char*)&n, sizeof(NominateRequest), 0);
                    recv(nSocket, rBuff, sizeof(Responce), 0);
                    Responce res;
                    memcpy(&res, rBuff, sizeof(Responce));
                    std::cout << res.responce << std::endl;
                    break;
                }

                case MessageType::EMPLOYEE_PENDING_REQUEST:
                {
                    MessageType mgs = MessageType::EMPLOYEE_PENDING_REQUEST;
                    send(nSocket, (char*)&mgs, sizeof(mgs), 0);
                    receive_Employee2_vector(nSocket);
                    break;
                }

                case MessageType::EMPLOYEE_ACTIVE_REQUEST:
                {
                    MessageType mgs = MessageType::EMPLOYEE_ACTIVE_REQUEST;
                    send(nSocket, (char*)&mgs, sizeof(mgs), 0);
                    receive_Employee2_vector(nSocket);
                    break;
                }

                case MessageType::EMPLOYEE_APPROVAL_STATE:
                {
                    Employee_Approval req;
                    cout<<"Enter Course Id: "<<endl;
                    cin>>req.CourseId;
                    req.mgs = MessageType::EMPLOYEE_APPROVAL_STATE;
                    cout<<"Enter Acceptance: "<<endl;
                    cin>>req.Acceptance;
                    send(nSocket, (char*)&req, sizeof(Employee_Approval), 0);
                    break;
                }

                default:
                    break;
            }
        }
        


}

#endif