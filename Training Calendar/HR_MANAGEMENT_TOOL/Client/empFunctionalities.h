#ifndef MYHEADER_H
#define MYHEADER_H

#include <iostream>
#include <winsock.h>
#include <string>
#include <vector>

#define PORT 9909

#pragma pack(1)

enum MessageType {
    NOMINATE_REQUEST,
    EMPLOYEE_PENDING_REQUEST,
    EMPLOYEE_ACTIVE_REQUEST,
    EMPLOYEE_APPROVAL_STATE
};

enum EmployeeType {
    EMPLOYEE,
    RM,
    TM
};

struct RegisterRequest {
    MessageType type;
    int ID;
};

struct NominateRequest {
    MessageType mgs;
    int trainingID;
};

struct NominateResponce {
    int nominatedTrainings;
};

struct ApprovalStatus {
    int courseId;
    EmployeeType Emp_state;
    EmployeeType RM_state;
    EmployeeType TM_state;
};

struct Employee_Approval {
    MessageType mgs;
    int CourseId;
    int Acceptance;
    char Rejection[50];
};

using namespace std;

int establish_connection();

void receive_vector(int nSocket);

void handle_request(int nSocket, MessageType mgs);

void send_employee_approval(int nSocket);

void send_nominate_request(int nSocket);

#endif
