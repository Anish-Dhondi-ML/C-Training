#pragma once

#ifndef RM_H
#define RM_H
class RM {

    int nRMSocket;
    int Id;
    char RMbuff[256 + 1] = { 0, };
    int nRet;

    MessageType mgs;
    struct Training_calender T_Cal;

public:

    void ProcessNewMessage(std::map<int, std::pair<enum Emp, void*>>);
    void setRMSocketId(int, int);

    template<typename T>
    void respond_As_Structure(T);

    template<typename V>
    void respond_As_Vector(V);
};
#endif