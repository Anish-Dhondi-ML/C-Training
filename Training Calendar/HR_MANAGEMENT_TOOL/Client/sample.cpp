#ifndef RM_FUNCTIONS_H
#define RM_FUNCTIONS_H

#include <iostream>
#include <winsock.h>
#include <string>
#include <vector>
#include "..\Server\mystructure.h"

using namespace std;


void receive_RM_vector(int nSocket){

int vectorSize;
recv(nSocket, (char*)&vectorSize,sizeof(vectorSize), 0);

vector<ApprovalStatus> requests(vectorSize);
recv(nSocket,(char*)requests.data(),vectorSize * sizeof(ApprovalStatus),0);
for(ApprovalStatus a: requests){
    cout<<a.courseId<<endl;
    cout<< EmployeeStrings[a.Emp_state]<<endl;
    cout<< RMStrings[a.RM_state]<<endl;
    cout<< TMStrings[a.TM_state]<<endl;
}

}
// Function to receive vector of ApprovalStatus object

// Function to handle requests from RM
void rm(int nSocket) {
    //Keep sending the messages 
    char rBuff[37] = { 0, };

    recv(nSocket, rBuff, 37, 0);
    cout << endl << rBuff << endl;

    RegisterRequest tc;
    tc.type = REPORTING_MANAGER;
    tc.ID = 4;

    const char* request_buffer = reinterpret_cast<const char*>(&tc);
    send(nSocket, request_buffer, sizeof(RegisterRequest), 0);

    while (1)
    {
        getchar();
        Sleep(2000);
        printf("\nSending Data..?\n");
        int choice;
        cout << "enter 1 to send the pending request to TM" << endl << "enter 2 to foward the request from employee to add in the calender" << endl << "enter 3 to nominate employees for the project" << endl << "enter 4 to approve the request" << endl << "enter 5 to chhose a 'new' course for the employees" << endl;
        cin >> choice;
        switch (choice) {
        case(1):
        {
            MessageType mgs = RM_PENDING_REQUEST;
            //should have a recieve msg from employee to see the what are the pending req. so that it can be rejected later
            send(nSocket, (char*)&mgs, sizeof(mgs), 0);
            receive_RM_vector(nSocket);
            break;
        }
        case(2):
        {
            MessageType mgs = RM_ACTIVE_REQUEST;
            send(nSocket, (char*)&mgs, sizeof(mgs), 0);
            receive_RM_vector(nSocket);
            break;
        }
        case(3):
        {
            RM_Nominate rm_new;
            rm_new.mgs = RM_NOMINATE_EMPLOYEES;
            rm_new.CourseID = 1;
            rm_new.EmpIds[0] = 2; // Add a for loop to add a list of employees
            send(nSocket, (char*)&rm_new, sizeof(rm_new), 0);
            break;
        }
        case(4):    
        {
            RM_Approval req;
            req.CourseId = 1;
            req.empId = 2;
            req.mgs = RM_APPROVAL_STATE;
            req.acceptance = 1;
            //strncpy(req.Rejection,"Already course completed",sizeof(req.Rejection));
            send(nSocket, (char*)&req, sizeof(Employee_Approval), 0);
            break;
        }
        case(5):
        {
            RM_NewCourse_Request n;
            n.mgs = RM_NEW_COURSE_REQUEST;
            strncpy(n.CourseName,"C++",sizeof(n.CourseName));
            strncpy(n.Reason,"Required for UCSM Project",sizeof(n.Reason));
            n.Ids[0] = 2;
            // Serialize and send the new course request
            send(nSocket, (char*)&n, sizeof(n), 0);
            break;
        }
      }
  }
}
    
#endif
