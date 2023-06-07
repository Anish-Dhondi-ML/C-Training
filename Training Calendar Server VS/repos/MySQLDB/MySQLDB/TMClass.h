#pragma once

#ifndef TM_H
#define TM_H

class TM {

    int nTMSocket;
    int Id;
    char TMbuff[256 + 1] = { 0, };
    int nRet;

    MessageType mgs;

    struct Training_calender T_Cal;

    struct TM_EmpCourse_Approval TM_emp_apv;
    struct TM_NewCourse_Approval TM_new_apv;
    struct New_Course new_c;

public:

    void ProcessNewMessage(std::map<int, std::pair<enum Emp, void*>>);
    void setTMSocketId(int, int);

    template<typename T>
    void respond_As_Structure(T);

    template<typename V>
    void respond_As_Vector(V);
};


#endif TM_H