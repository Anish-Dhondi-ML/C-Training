#pragma once
#ifndef MYSTRUCTURE_H
#define MYSTRUCTURE_H

#include "Enums.h"

struct ApprovalStatus {
    int employee_Id;
    int courseId;
    int RM_Id;

    char CourseName[30];
    char Rejection_Reason[50];
    Employee_Status Emp_state;
    RM_Status RM_state;
    TM_Status TM_state;
};

struct RegisterRequest
{
    Emp type;
    int ID;
};

struct Training_calender
{

    int course_Id;
    char course_name[30];
    int duration;

};


// EMPLOYEE STRUCTURE LIST

struct NominateRequest
{
    MessageType mgs;
    int trainingID;
};

struct NominateResponce {
    char nominatedTrainings[30];
};

struct Employee_Request_Retrieve {

    MessageType mgs;

};

struct Employee_Approval {

    MessageType mgs;
    int CourseId;
    int Acceptance; // '0: REJECTED' '1: APPROVED' 
    char Rejection[50];
};


// RM Structure List

struct RM_NewCourse_Request {

    MessageType mgs;
    char CourseName[30];
    int EmpIds[10];
    char Reason[30];

};

struct RM_Nominate {

    MessageType mgs;
    int CourseID;
    int EmpIds[10];

};

struct RM_Approval {

    MessageType mgs;
    int CourseId;
    int Acceptance; // '0: REJECTED' '1: APPROVED' 
    char Rejection[50];

};

// TM Structure List

struct TM_EmpCourse_Approval {

    MessageType mgs;
    int CourseId;
    int Emp_Id;
    int Acceptance; // '0: REJECTED' '1: APPROVED' 
    char Rejection[50];

};

struct TM_NewCourse_Approval {

    MessageType mgs;
    char CourseName[30];
    int RM_Id;
    int Acceptance; // '0: REJECTED' '1: APPROVED' 
    char Rejection[50];

};

struct New_Course {

    MessageType mgs;
    int CourseId;
    char CourseName[30];
    char TrainerName[30];
    char ProjectName[30];

};

#endif