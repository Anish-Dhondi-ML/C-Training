#include <iostream>
#include <string>
#include <vector>
#include <winsock.h>

#include "..\Server\mystructure.h"

using namespace std;

#pragma pack(1)


void receive_Employee_vector(int nSocket){

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


void receive_Course_vector(int nSocket){

int vectorSize;
recv(nSocket, (char*)&vectorSize, sizeof(vectorSize), 0);
vector<ApprovalStatus> requests(vectorSize);
if (vectorSize > 0) {
    recv(nSocket, (char*)requests.data(), vectorSize * sizeof(ApprovalStatus), 0);
    for (ApprovalStatus a : requests) {
        cout << "Emp Id: " << a.employee_Id <<endl;
        cout << "RM ID: " << a.RM_Id << endl;
        cout << "Course Name: " << a.CourseName << endl;
    }
} else {
    cout << "No requests" << endl;
    // or exit the function/program gracefully
}

}
void TM(int nSocket){
     
        //Keep sending the messages 
        char rBuff[37] = { 0, };

        recv(nSocket, rBuff, 37, 0);
        std::cout << std::endl << rBuff << std::endl;

        RegisterRequest tc;
        tc.type = TRAINING_MANAGER;
        tc.ID = 5;

        const char* request_buffer = reinterpret_cast<const char*>(&tc);
        send(nSocket, request_buffer, sizeof(RegisterRequest), 0);
        int choice = 0;

        while (1)
        {
            getchar();
            Sleep(2000);
            printf("\nSending Data..?\n");
            std::cout << "Enter '1' TM_EMPLOYEE APPROVAL\n"
                      << "'2' TM COURSE APPROVAL\n"
                      << "'3' RETRIEVE EMPLOYEE REQUEST\n"
                      << "'4' RETRIEVE RM REQUEST\n";
            cin >> choice;
            MessageType mgs;
            if (choice == 1) {
                mgs = MessageType::TM_EMPLOYEE_APPROVAL;
            }
            if (choice == 2) {
                mgs = MessageType::TM_COURSE_APPROVAL;
            }
            if (choice == 3) {
                mgs = MessageType::RETRIEVE_EMPLOYEE_REQUEST;
            }
            if (choice == 4) {
                mgs = MessageType::RETRIEVE_RM_REQUEST;
            }

            switch (mgs)
            {
                case MessageType::TM_EMPLOYEE_APPROVAL:
                {
                    TM_EmpCourse_Approval emp_course_approval;
                    emp_course_approval.mgs = TM_EMPLOYEE_APPROVAL;
                    cout<<"Enter CourseId: "<<endl;
                    cin>>emp_course_approval.CourseId;
                    cout<<"Enter Employee Id: "<<endl;
                    cin>>emp_course_approval.Emp_Id;
                    cout<<"Enter Acceptance Status (0: Reject, 1: Approve): "<<endl;
                    cin>>emp_course_approval.Acceptance;
                    
                    if(emp_course_approval.Acceptance == 0){
                       cout << "Enter Your Rejection reason: ";
                       char rejection_reason[100]; 
                       cin.getline(rejection_reason, 100); 
                       strcpy(emp_course_approval.Rejection, rejection_reason);
                    }
                    
                    const char* emp_course_approval_buffer = reinterpret_cast<const char*>(&emp_course_approval);
                    send(nSocket, emp_course_approval_buffer, sizeof(TM_EmpCourse_Approval), 0);
	                
                    recv(nSocket, rBuff, sizeof(Responce), 0);
                    Responce res;
                    memcpy(&res, rBuff, sizeof(Responce));
                    std::cout << res.responce << std::endl;

                    break;
                }

                case MessageType::TM_COURSE_APPROVAL:
                {
                    
                    TM_NewCourse_Approval new_course_approval;
                    new_course_approval.mgs = TM_COURSE_APPROVAL;

                    cout << "Enter Course Name: "<<endl;
                    char Course_Name[100]; 
                    cin.ignore();
                    cin.getline(Course_Name, 100); 
                    strcpy(new_course_approval.CourseName, Course_Name);

cout<< "Enter Acceptance(0:Reject, 1:Accept): "<<endl;
cin>>new_course_approval.Acceptance;

cout << "Enter RM Id: "<<endl;
cin.ignore(); // add this line to flush the input buffer
cin>>new_course_approval.RM_Id;



                    if(new_course_approval.Acceptance == 0){
                       cout << "Enter Your Rejection reason: ";
                       char rejection_reason[100]; 
                       cin.getline(rejection_reason, 100); 
                       strcpy(new_course_approval.Rejection, rejection_reason);
                    }

                    const char* new_course_approval_buffer = reinterpret_cast<const char*>(&new_course_approval);
                    send(nSocket, new_course_approval_buffer, sizeof(TM_NewCourse_Approval), 0);
                    cout<<"Message sent";
                    break; 
                }

                case MessageType::RETRIEVE_EMPLOYEE_REQUEST:
                {
                    MessageType mgs = MessageType::RETRIEVE_EMPLOYEE_REQUEST;
                    send(nSocket, (char*)&mgs, sizeof(mgs), 0);
                    receive_Employee_vector(nSocket);
                    break;
                }

                case MessageType::RETRIEVE_RM_REQUEST:
                {
                    MessageType mgs = MessageType::RETRIEVE_RM_REQUEST;
                    send(nSocket, (char*)&mgs, sizeof(mgs), 0);
                    receive_Course_vector(nSocket);
                    break;
                }

                case MessageType::CREATE_COURSE:
                {
                    
                    New_Course n;
                    n.mgs = MessageType::CREATE_COURSE;
                    n.CourseId = 6;
                    strncpy(n.CourseName,"C++",sizeof(n.CourseName));
                    strncpy(n.TrainerName,"Annapoorna",sizeof(n.CourseName));
                    strncpy(n.Descripsion,"Requires for UCSM",sizeof(n.CourseName));
                    send(nSocket, (char*)&n, sizeof(n), 0);
                    break;
                }

                default:
                    break;
            }
        }
        


}
