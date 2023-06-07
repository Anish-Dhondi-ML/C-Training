#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {

private:
    int nEmployeeSocket;
    int Id;
    char Empbuff[256 + 1] = { 0, };
    int nRet;

    MessageType mgs;

    struct Training_calender T_Cal;

    struct NominateRequest Nominate_req;
    struct NominateResponce Nominate_res;
    struct Employee_Approval Employee_apv;

public:

    void ProcessNewMessage(std::map<int, std::pair<enum Emp, void*>>);
    void setEmpSocketId(int, int);


    void handleNominate();
    void getActiveRequest();
    void getPendingRequest();
    void updateApproval();

    template<typename T>
    void respond_As_Structure(T);

    template<typename V>
    void respond_As_Vector(V);

};
#endif