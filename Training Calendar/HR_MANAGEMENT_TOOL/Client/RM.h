#include <iostream>
#include <string>
#include <vector>
#include <winsock.h>

#include "..\Server\mystructure.h"

using namespace std;

#pragma pack(1)


void receive_RM_vector(int nSocket){

int vectorSize;
recv(nSocket, (char*)&vectorSize, sizeof(vectorSize), 0);
vector<ApprovalStatus> requests(vectorSize);
if (vectorSize > 0) {
    recv(nSocket, (char*)requests.data(), vectorSize * sizeof(ApprovalStatus), 0);
    for (ApprovalStatus a : requests) {
        cout << "Employee ID: " << a.employee_Id << endl;
        cout << "Course ID: " << a.courseId << endl;
        cout << "Employee Status: " <<EmployeeStrings[a.Emp_state] << endl;
        cout << "RM Status: "<<RMStrings[a.RM_state] << endl;
        cout << "TM Status: "<<TMStrings[a.TM_state] << endl;
    }
} else {
    cout << "No requests" << endl;
    // or exit the function/program gracefully
}

}

void rm(int nSocket){
     
    //Keep sending the messages 
    char rBuff[37] = { 0, };

    recv(nSocket, rBuff, 37, 0);
    cout << endl << rBuff << endl;

    RegisterRequest tc;
    tc.type = REPORTING_MANAGER;
    tc.ID = 4;

    int choice = 0;

    const char* request_buffer = reinterpret_cast<const char*>(&tc);
    send(nSocket, request_buffer, sizeof(RegisterRequest), 0);

        while (1)
        {
            getchar();
            Sleep(2000);
            printf("\nSending Data..?\n");
            std::cout << "Enter '1' RM PENDING REQUEST\n"
                      << "'2' RM ACTIVE REQUEST\n"
                      << "'3' RM NOMINATE EMPLOYEES\n"
                      << "'4' RM APPROVAL STATE\n"
                      << "'5' RM NEW COURSE REQUEST\n";

            cin >> choice;
            MessageType mgs;
            if (choice == 1) {
                mgs = MessageType::RM_PENDING_REQUEST;
            }
            if (choice == 2) {
                mgs = MessageType::RM_ACTIVE_REQUEST;
            }
            if (choice == 3) {
                mgs = MessageType::RM_NOMINATE_EMPLOYEES;
            }
            if (choice == 4) {
                mgs = MessageType::RM_APPROVAL_STATE;
            }
            if (choice == 5) {
                mgs = MessageType::RM_NEW_COURSE_REQUEST;
            }

            switch (mgs)
            {
                case MessageType::RM_PENDING_REQUEST:
                {
                    MessageType mgs = RM_PENDING_REQUEST;
                    //should have a recieve msg from employee to see the what are the pending req. so that it can be rejected later
                    send(nSocket, (char*)&mgs, sizeof(mgs), 0);
                    receive_RM_vector(nSocket);
                    break;
                }

                case MessageType::RM_ACTIVE_REQUEST:
                {
                   
                    MessageType mgs = RM_ACTIVE_REQUEST;
                    send(nSocket, (char*)&mgs, sizeof(mgs), 0);
                    receive_RM_vector(nSocket);
                    break; 
                }

                case MessageType::RM_NOMINATE_EMPLOYEES:
                {
                    RM_Nominate rm_new;
                    rm_new.mgs = RM_NOMINATE_EMPLOYEES;
                    rm_new.CourseID = 11;
                    rm_new.EmpIds[0] = 2; // Add a for loop to add a list of employees
                    rm_new.EmpIds[1] = 3;
                    send(nSocket, (char*)&rm_new, sizeof(rm_new), 0);
                    break;
                }

                case MessageType::RM_APPROVAL_STATE:
                {

                    RM_Approval req;
                    req.CourseId = 10;
                    req.empId = 1;
                    req.mgs = RM_APPROVAL_STATE;
                    req.acceptance = 1;
                    //strncpy(req.Rejection,"Already course completed",sizeof(req.Rejection));
                    send(nSocket, (char*)&req, sizeof(Employee_Approval), 0);
                    break;
                }

                case MessageType::RM_NEW_COURSE_REQUEST:
                {
                    RM_NewCourse_Request n;
                    n.mgs = RM_NEW_COURSE_REQUEST;
                    strncpy(n.CourseName,"C++",sizeof(n.CourseName));
                    strncpy(n.Reason,"Required for UCSM Project",sizeof(n.Reason));
                    n.Ids[0] = 6;
                    n.Ids[1] = 7;
                    // Serialize and send the new course request
                    send(nSocket, (char*)&n, sizeof(n), 0);
                    break;
                }

                default:
                    break;
            }
        }
        


}
