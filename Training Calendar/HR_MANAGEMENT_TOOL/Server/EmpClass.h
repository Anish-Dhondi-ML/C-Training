#include<iostream>
#include<winsock.h>
#include<vector>
#include<sstream>
#include<map>

#include "globals.h"
#include "mystructure.h"

using namespace std;

class Employee{

private:
    int nEmployeeSocket;
    int Id;
    char Empbuff[256+1] = {0,};
    int nRet;

    MessageType mgs;

    struct Training_calender T_Cal;

    struct NominateRequest Nominate_req;
    struct Responce r;
    struct Employee_Approval Employee_apv;

public:

void ProcessNewMessage(std::map<int,std::pair<enum Emp,void*>>);
void setEmpSocketId(int,int);


void handleNominate();
void getActiveRequest();
void getPendingRequest();
void updateApproval();

template<typename T>
void respond_As_Structure(T);

template<typename V>
void respond_As_Vector(V);

};


void Employee::setEmpSocketId(int nEmployeeSocket,int Id) {
    this->nEmployeeSocket = nEmployeeSocket;
    this->Id = Id;
}

void Employee::ProcessNewMessage(std::map<int,std::pair<enum Emp,void*>> emp_sock_id){

std::cout<<std::endl<<"New request received from the socket for Employee: "<<nEmployeeSocket<<std::endl;
nRet = recv(nEmployeeSocket, Empbuff, 1024, 0);

void (Employee::*ptr[4])() = {handleNominate,getActiveRequest,getPendingRequest,updateApproval};

if(nRet < 0){
    /*
        Before closing the connection the connection state machine 
        should be updated to the data base
    */
    std::cout << std::endl << "Something wrong happened..closing the connection for Employee";
    closesocket(nEmployeeSocket);
    emp_sock_id.erase(nEmployeeSocket);
}else{

// ApprovalStatus s;
// s.courseId = 001;
// s.employee_Id = Id;
// s.RM_Id = 1;  // RM Id can be retrieved from Data base
// s.Emp_state = EMPLOYEE_ACCEPTED;
// s.RM_state = RM_WITH_HELD;
// s.TM_state = TM_WITH_HELD;
// state.push_back(s);

memcpy(&mgs,Empbuff,sizeof(mgs));
std::cout<<mgs<<std::endl;

switch (mgs){

        case REQUEST_TRAINING_CALENDER:
        {
         
         vector<Training_calender> requests;

         //  for(){
         //     T_Cal.course_Id = 1;
         //     strncpy(T_Cal.course_name,"C++",sizeof(T_Cal));
         //     T_Cal.duration = 3;

         //     requests.push_back(T_Cal);
         //  
         // }

         // respond_As_Vector(requests);
        
         /*
            Training Calender should be retrieved from data base 
            and sent to an TM
        */
            
            break;
        }
        
        case NOMINATE_REQUEST:
        { 
            (this->*ptr[0])();
            break;
        }


        case EMPLOYEE_ACTIVE_REQUEST:{
            (this->*ptr[1])();
            break;
        }

        case EMPLOYEE_PENDING_REQUEST:{
            (this->*ptr[2])();
            break;          
        }

        case EMPLOYEE_APPROVAL_STATE:{
            (this->*ptr[3])();
            break;         
        }

        default:
            cout<<"INVALID REQUEST"<<endl;
            break;

    }
    std::cout << std::endl << "*******************************";
}
}


template<typename T>
void Employee::respond_As_Structure(T res){
            send(nEmployeeSocket,(char*)&res,sizeof(T),0);
}

template<typename V>
void Employee::respond_As_Vector(V res){

int vector_size = res.size();
cout<<"Vector Size: "<<vector_size<<endl;
send(nEmployeeSocket,(char*)&vector_size,sizeof(vector_size),0);
cout<<"Sent"<<endl;
send(nEmployeeSocket,(char*)res.data(),vector_size*sizeof(ApprovalStatus),0);
}

void Employee::handleNominate(){
            
            memcpy(&Nominate_req,Empbuff,sizeof(NominateRequest));
            
            int flag = 0;

            for(int i=0;i<state.size();i++)
            {
                if(state[i].employee_Id==Id && state[i].courseId==Nominate_req.trainingID)
                {
                    strncpy(r.responce,"Already registered",sizeof(r));
                    respond_As_Structure(r);
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0){

                ApprovalStatus s;
                s.courseId = Nominate_req.trainingID;
                s.employee_Id = Id;
                s.RM_Id = 4;  // RM Id can be retrieved from Data base
                s.Emp_state = EMPLOYEE_ACCEPTED;
                s.RM_state = RM_WITH_HELD;
                s.TM_state = TM_WITH_HELD;

                state.push_back(s);

                strncpy(r.responce,"Successfully registered",sizeof(r));
                respond_As_Structure(r);

            }
}

void Employee::getActiveRequest(){

    vector<ApprovalStatus> requests;
            for(ApprovalStatus req : state){
                if(req.employee_Id == Id && (req.RM_state == RM_ACCEPTED) && req.Emp_state == EMPLOYEE_WITH_HELD){
                    requests.push_back(req);
                }
            }
            
    respond_As_Vector(requests);
}

void Employee::getPendingRequest(){

            vector<ApprovalStatus> requests;
            for(ApprovalStatus req : state){
                if(req.employee_Id == Id && req.Emp_state == EMPLOYEE_ACCEPTED){
                    cout<<"Pushed"<<endl;
                    requests.push_back(req);
                }
            }
            respond_As_Vector(requests);

}

void Employee::updateApproval(){

    memcpy(&Employee_apv,Empbuff,sizeof(Employee_Approval));
    
    std::vector<ApprovalStatus>::iterator it;
    for (it = state.begin(); it != state.end(); ++it){

                if(it->employee_Id == Id && it->courseId == Employee_apv.CourseId){

                    if(Employee_apv.Acceptance == 0){

                        it->Emp_state = EMPLOYEE_REJECTED;
                        strncpy(it->Rejection_Reason, Employee_apv.Rejection,sizeof(Employee_apv.Rejection));
                        state.erase(it);

                    }else{

                        it->Emp_state = EMPLOYEE_ACCEPTED;

                    }

                }
    }
}