#include<iostream>
#include<winsock.h>
#include<vector>
#include<sstream>
#include<map>

#include "mystructure.h"
#include "Enums.h"
#include "globals.h"
using namespace std;

class RM {

    int nRMSocket;
    int Id;
    char RMbuff[1024] = { 0, };
    int nRet;

    MessageType mgs;
    struct Training_calender T_Cal;
    struct RM_Nominate rm_nominate;
    struct RM_NewCourse_Request new_course;
    struct RM_Approval rm_approval;

public:

    void ProcessNewMessage(std::map<int, std::pair<enum Emp, void*>>);
    void setRMSocketId(int, int);

    template<typename T>
    void respond_As_Structure(T);

    template<typename V>
    void respond_As_Vector(V);
};

void RM::setRMSocketId(int nRMSocket,int Id) {
    this->nRMSocket = nRMSocket;
    this->Id = Id;
}

template<typename T>
void RM::respond_As_Structure(T res){
            send(nRMSocket,(char*)&res,sizeof(T),0);
}

template<typename V>
void RM::respond_As_Vector(V res){
int vector_size = res.size();
send(nRMSocket,(char*)&vector_size,sizeof(vector_size),0);
cout<<"sent"<<endl;
send(nRMSocket,(char*)res.data(),vector_size*sizeof(ApprovalStatus),0);
cout<<"sent"<<endl;
}


void RM::ProcessNewMessage(std::map<int,std::pair<enum Emp,void*>>){

std::cout<<endl<<"New request received from the socket for RM: "<<nRMSocket<<endl;
nRet = recv(nRMSocket, RMbuff, 1024, 0);

if(nRet < 0){
    /*
        Before closing the connection the connection state machine 
        should be updated to the data base
    */
    std::cout << endl << "Something wrong happened..closing the connection for Employee";
    closesocket(nRMSocket);
    emp_sock_id.erase(nRMSocket);

}

else{

memcpy(&mgs,RMbuff,sizeof(mgs));

switch (mgs){

        case REQUEST_TRAINING_CALENDER:
        {

            //  for(){
            //     T_Cal.course_Id = 1;
            //     strncpy(T_Cal.course_name,"C++",sizeof(T_Cal));
            //     T_Cal.duration = 3;

            //     requests.push_back(T_Cal);
            //  
            // }
            
            /*
                Training Calender should be retrieved from data base 
                and sent to an TM
            */

           break;
        }

        case RM_APPROVAL_STATE:
        {
            memcpy(&rm_approval,RMbuff,sizeof(RM_Approval));
            std::cout<<"Approval: "<<rm_approval.acceptance<<endl;
            for(auto it=state.begin();it!=state.end();++it){
                if(it->RM_Id==this->Id && it->employee_Id==rm_approval.empId && it->courseId==rm_approval.CourseId && it->Emp_state==EMPLOYEE_ACCEPTED){
                    if(rm_approval.acceptance=1){
                        it->RM_state=RM_ACCEPTED;
                    }
                    else if(rm_approval.acceptance=0){ 
                        strncpy(it->Rejection_Reason,rm_approval.rejection,sizeof(rm_approval.CourseId));
                        it->RM_state=RM_REJECTED;
                    }
                }
            }
            break;
        }

        case RM_NOMINATE_EMPLOYEES:
        {
            ApprovalStatus temp;
            memcpy(&rm_nominate,RMbuff,sizeof(RM_Nominate));
            std::cout<<"Course Id: "<<rm_nominate.CourseID<<endl;
            for(int i = 0; i < sizeof(rm_nominate.EmpIds) / sizeof(rm_nominate.EmpIds[0]); i++){
                if(rm_nominate.EmpIds[i] > 0){
                    std::cout<<rm_nominate.EmpIds[i]<<endl;
                    temp.employee_Id=rm_nominate.EmpIds[i];
                    temp.courseId=rm_nominate.CourseID;
                    temp.RM_Id=this->Id;
                    temp.Emp_state=EMPLOYEE_WITH_HELD;
                    temp.RM_state=RM_ACCEPTED;
                    temp.TM_state=TM_WITH_HELD;
                    state.push_back(temp);
                }
            }
            break;
        }

        case RM_ACTIVE_REQUEST:
        {
            vector<ApprovalStatus> active_requests;
            for(ApprovalStatus r: state){
                if((r.Emp_state==EMPLOYEE_ACCEPTED && r.RM_state==RM_WITH_HELD)&&(r.RM_Id==this->Id)){
                    active_requests.push_back(r);
                }
            }
            respond_As_Vector(active_requests);

            break;
        }
        
        case RM_PENDING_REQUEST:
        {
           vector<ApprovalStatus> tm_pending_requests;
           for(ApprovalStatus r: state){
              if(r.RM_Id==this->Id && (r.RM_state==RM_NEW_COURSE && r.TM_state==TM_WITH_HELD)){
                tm_pending_requests.push_back(r);
              }  
           }
           respond_As_Vector(tm_pending_requests);

           break;
        }

        case RM_NEW_COURSE_REQUEST:
        {
            ApprovalStatus temp;
            memcpy(&new_course,RMbuff,sizeof(RM_NewCourse_Request));
            //update in db
            for(int i = 0; i < sizeof(new_course.Ids) / sizeof(new_course.Ids[0]); i++){
                if(new_course.Ids[i] > 0){
                    std::cout<<new_course.Ids[i] <<endl;
                    strncpy(temp.CourseName,new_course.CourseName,sizeof(new_course.CourseName));
                    temp.Emp_state=EMPLOYEE_WITH_HELD;
                    temp.employee_Id=new_course.Ids[i];
                    temp.RM_Id=this->Id;
                    temp.RM_state=RM_NEW_COURSE;
                    temp.TM_state=TM_WITH_HELD;
                    state.push_back(temp);
                }
            }

            break;
        }

        default:
            std::cout<<"INVALID REQUEST"<<endl;
            break;
    }
    std::cout << endl << "***********";   

}
}