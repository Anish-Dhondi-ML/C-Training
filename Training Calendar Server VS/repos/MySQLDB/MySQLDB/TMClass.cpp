
#include<iostream>
#include<winsock.h>
#include<vector>
#include<sstream>
#include<map>

#include "globals.h"
#include "mystructure.h"


#include "TMClass.h"


using namespace std;



void TM::setTMSocketId(int nTMSocket, int Id) {
    this->nTMSocket = nTMSocket;
    this->Id = Id;
}

template<typename T>
void TM::respond_As_Structure(T res) {
    send(nTMSocket, (char*)&res, sizeof(T), 0);
}

template<typename V>
void TM::respond_As_Vector(V res) {
    int vector_size = res.size();

    send(nTMSocket, (char*)&vector_size, sizeof(vector_size), 0);
    send(nTMSocket, (char*)res.data(), vector_size * sizeof(ApprovalStatus), 0);
}

void TM::ProcessNewMessage(std::map<int, std::pair<enum Emp, void*>>) {

    cout << endl << "New request received from the socket for TM: " << nTMSocket << endl;
    nRet = recv(nTMSocket, TMbuff, 1024, 0);

    if (nRet < 0) {
        /*
            Before closing the connection the connection state machine
            should be updated to the data base
        */
        cout << endl << "Something wrong happened..closing the connection for Employee";
        closesocket(nTMSocket);
        emp_sock_id.erase(nTMSocket);

    }
    else {

        memcpy(&mgs, TMbuff, sizeof(mgs));

        switch (mgs) {

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

        case RETRIEVE_EMPLOYEE_REQUEST:
        {
            vector<ApprovalStatus> requests;
            for (ApprovalStatus req : state) {
                if (req.RM_state == RM_ACCEPTED && req.Emp_state == EMPLOYEE_ACCEPTED) {
                    requests.push_back(req);
                }
            }

            // RESPONDING BACK TO TM
            respond_As_Vector(requests);
            break;
        }

        case RETRIEVE_RM_REQUEST:
        {

            vector<ApprovalStatus> requests;
            for (ApprovalStatus req : state) {
                if (req.RM_state == RM_NEW_COURSE) {
                    requests.push_back(req);
                }
            }

            // RESPONDING BACK TO TM
            respond_As_Vector(requests);
            break;

        }

        case CREATE_COURSE:
        {
            memcpy(&new_c, TMbuff, sizeof(New_Course));
            /*
                New course should be added to the data base.
            */
            break;
        }

        case TM_EMPLOYEE_APPROVAL:
        {
            memcpy(&TM_emp_apv, TMbuff, sizeof(TM_EmpCourse_Approval));
            std::vector<ApprovalStatus>::iterator it;
            for (it = state.begin(); it != state.end(); ++it) {

                if (it->employee_Id == TM_emp_apv.Emp_Id && it->courseId == TM_emp_apv.CourseId) {

                    if (TM_emp_apv.Acceptance == 0) {

                        it->TM_state = TM_REJECTED;
                        strncpy_s(it->Rejection_Reason, TM_emp_apv.Rejection, sizeof(TM_emp_apv.Rejection));
                        /*
                            Update in the database before deleting from the state
                            machine
                        */
                        state.erase(it);
                    }
                    else {

                        it->TM_state = TM_ACCEPTED;
                        /*
                            Once TM approved then the state should be updated in an
                            database
                        */

                    }

                }
            }

            break;
        }

        case TM_COURSE_APPROVAL:
        {

            memcpy(&TM_new_apv, TMbuff, sizeof(TM_EmpCourse_Approval));
            std::vector<ApprovalStatus>::iterator it;
            for (it = state.begin(); it != state.end(); ++it) {

                if (it->RM_Id == TM_new_apv.RM_Id && it->RM_state == RM_NEW_COURSE && it->CourseName == TM_new_apv.CourseName) {

                    if (TM_new_apv.Acceptance == 0) {

                        it->TM_state = TM_REJECTED;
                        strncpy_s(it->Rejection_Reason, TM_new_apv.Rejection, sizeof(TM_new_apv.Rejection));
                        /*
                            Update in the database before deleting from the state
                            machine
                        */
                        state.erase(it);
                    }
                    else {
                        it->TM_state = TM_ACCEPTED;

                        /*
                            New course should be added be added to the data base.
                        */

                    }
                }
            }

        }

        default:

            break;
        }
        cout << endl << "*******************************";
    }
}