#include<iostream>
#include<winsock.h>
#include<vector>
#include<sstream>
#include<map>

#include "mystructure.h"
#include "globals.h"

#include "RMClass.h"

using namespace std;

void RM::setRMSocketId(int nRMSocket, int Id) {
    this->nRMSocket = nRMSocket;
    this->Id = Id;
}

template<typename T>
void RM::respond_As_Structure(T res) {
    send(nRMSocket, (char*)&res, sizeof(T), 0);
}

template<typename V>
void RM::respond_As_Vector(V res) {
    int vector_size = res.size();
    send(nRMSocket, (char*)&vector_size, sizeof(vector_size), 0);
    send(nRMSocket, (char*)res.data(), vector_size * sizeof(ApprovalStatus), 0);
}


void RM::ProcessNewMessage(std::map<int, std::pair<enum Emp, void*>>) {

    cout << endl << "New request received from the socket for RM: " << nRMSocket << endl;
    nRet = recv(nRMSocket, RMbuff, 1024, 0);

    if (nRet < 0) {
        /*
            Before closing the connection the connection state machine
            should be updated to the data base
        */
        cout << endl << "Something wrong happened..closing the connection for Employee";
        closesocket(nRMSocket);
        emp_sock_id.erase(nRMSocket);

    }
    else {

        memcpy(&mgs, RMbuff, sizeof(mgs));

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

        case RM_APPROVAL_STATE:
        {
            /*
               RM should Approve or Reject the course request
               from the employee
            */
            break;
        }

        case RM_NOMINATE_EMPLOYEES:
        {
            /*
                RM should able to nominate list of employees
                for a course listed in an Training calender.

                Nomination requests should be added to the state
                machines for all the employees to whom nomination
                request is sent
            */

            break;
        }

        case RM_ACTIVE_REQUEST:
        {
            /*
                RM should able to retrieve all the requests
                received from employees
            */
            break;
        }

        case RM_PENDING_REQUEST:
        {
            /*
                RM should able to retrieve all the new course
                requests sent to TM
            */
        }

        case RM_NEW_COURSE_REQUEST:
        {

            /*
                Should not add course Id

                Add RM_state = RM_NEW_COURSE (So that new course requests will be isolated from
                Employee requests)
            */
        }

        default:

            break;
        }
        cout << endl << "*******************************";

    }
}