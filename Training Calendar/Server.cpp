#include<iostream>
#include<winsock.h>
#include<vector>
#include<sstream>
#include<map>

using namespace std;
#define PORT 9909

//map to store data
map<int, int> emp_sock_id;

enum MessageType{
    NOMINATE_REQUEST, 
    REGISTER_REQUEST,
};

struct FindRequest
{
    int ID;
    MessageType mgs;
};

struct RegisterRequest
{
    MessageType msg;
    int ID;
    char role[20];
};

struct RegisterResponse
{
    char nominatedTrainings[30];
    char completedTrainings[30];
    char rejectedTrainings[30];
};

struct NominateRequest
{
    char trainingName[20];
    int trainingID;
    MessageType msg;
};

struct sockaddr_in srv;
fd_set fr, fw, fe;
int nMaxFd;
int nSocket;
int nArrClient[5];

template<typename T>
void respond_to_client(int tc, T res){
 // This will map emp to socket
 for (std::map<int,int>::iterator it = emp_sock_id.begin(); it!=emp_sock_id.end(); ++it){
    if(it->second == tc){
            const char* responce = reinterpret_cast<const char*>(&res);
            send(it->first, responce ,sizeof(T), 0);
            break;
    }
 } 
}

void handleRegister(){

}

void handleNominate(){

}

void CheckIdAdded(int nClientSocket,int ID){
    if(emp_sock_id[nClientSocket] == 0){
         emp_sock_id[nClientSocket] = ID;
    }
}

void ProcessNewMessage(int nClientSocket){

cout<< endl << "Processing the new message for client socket: " << nClientSocket;
char rbuff[256+1] = {0,};

int nRet = recv(nClientSocket, rbuff, sizeof(RegisterRequest), 0);

if(nRet < 0){
    cout << endl << "Something wrong happened..closing the connection for client";
    closesocket(nClientSocket);
    emp_sock_id.erase(nClientSocket);
}
else{ 

    MessageType msg_type;
    memcpy(&msg_type,rbuff,sizeof(MessageType));

    switch (msg_type) {

        case REGISTER_REQUEST:

            RegisterRequest req;
            memcpy(&req,rbuff,sizeof(RegisterRequest));

            // Check if the Employee is mapped with Socket Id or not 
            CheckIdAdded(nClientSocket,req.ID);

            RegisterResponse res;
            strncpy(res.completedTrainings,"DBMS",sizeof(res.completedTrainings));
            strncpy(res.nominatedTrainings,"C",sizeof(res.nominatedTrainings));
            strncpy(res.rejectedTrainings,"PYTHON",sizeof(res.rejectedTrainings));
            
            respond_to_client(req.ID, res);
            break;

        case NOMINATE_REQUEST:
            cout<<endl<<"Nominate Request"<<endl;
            handleNominate();
            break;
        
        default:
            break;

    }
    
    // for (char* training : tc->role)
	//     std::cout << training << "\n";
    //Message send back to client  
    cout << endl << "*******************************";
}
}

void ProcessTheNewRequest(){

if(FD_ISSET(nSocket, &fr)){

    int nLen = sizeof(struct sockaddr);
  
    int nClientSocket = accept(nSocket, NULL, &nLen);

    if(nClientSocket > 0){
        //Put it into the client fd_set.
        emp_sock_id[nClientSocket];
        //send(nClientSocket, "Got the connection done successfully", 1024, 0);
    }
}

else{
    for (std::map<int,int>::iterator it=emp_sock_id.begin(); it!=emp_sock_id.end(); ++it){
       if(FD_ISSET(it->first, &fr)){
            //Got the new message from the client
            //Just recv new message
            //Just queue that for new workes of your server to fulfil the req
            ProcessNewMessage(it->first);
        }
    }  
}
}

int main(){
                                                                             
    int nRet = 0;
    // Initialize the WSA variable
    WSADATA ws;
    if(WSAStartup(MAKEWORD(2,2), &ws) < 0){
        cout<<endl<<"WSA failed to initilize";
    }else{
        cout<<endl<<"WSA Initialized";
    }
   // Initialize the socket
nSocket = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);
if(nSocket <0){
    cout<<endl << "The socket not opened";
    WSACleanup ();
    exit(EXIT_FAILURE);
}
else{
    cout<<endl<<"The socket opened successfully";
}

//Initialize the enviroinment for sockaddr structure
   srv.sin_family = AF_INET;
   srv.sin_port = htons(PORT);
   srv.sin_addr.s_addr = INADDR_ANY;
   memset(&(srv.sin_zero),0,8);

//About the Blocking vs Non Blocking sockets 
//optval = 0 means blocking and !=0 means non bloacking
  
// u_long optval = 1;
// nRet = ioctlsocket(nSocket, FIONBIO, &optval);
// if(nRet != 0){
//     cout<< endl << "ioctlsocket call failed";
// }else{
//     cout<< endl << "ioctlsocket call passed";
// }

int nOptVal = 0;
int nOptLen = sizeof(nOptVal);

//setSocket
    nRet = setsockopt(nSocket, SOL_SOCKET, SO_REUSEADDR, (const char*)&nOptVal, nOptLen);
    if(!nRet){
        cout<< endl << "The setsockopt call successful";
    }else{
        cout<< endl << "The setsocketopt call failed";
        WSACleanup ();
        exit(EXIT_FAILURE);
    }

   //Bind the socket to the local port
   nRet = bind(nSocket, (sockaddr*) &srv, sizeof(sockaddr));
   
   if(nRet < 0){
     cout<<endl<< "Fail to bind to local port";
     WSACleanup ();
     exit(EXIT_FAILURE);
   }else{
        cout<< endl<< "Successfully bind to local port";
   }

   //Listen the request from client (queues the requests)
   nRet = listen(nSocket, 5);
   if( nRet < 0){
        cout<<endl<< "Fail to start to the local port";
        WSACleanup ();
        exit(EXIT_FAILURE);
   }else{
       cout<< endl<<"Started listeming to the local port";
   }

   nMaxFd = nSocket;
   struct timeval tv;
   tv.tv_sec = 1;
   tv.tv_usec = 0;

while(true){

   FD_ZERO(&fr);
   FD_ZERO(&fw);
   FD_ZERO(&fe);

   FD_SET(nSocket, &fr);
   FD_SET(nSocket, &fe);

  for (std::map<int,int>::iterator it=emp_sock_id.begin(); it!=emp_sock_id.end(); ++it){
            FD_SET(it->first, &fr);
            FD_SET(it->first, &fe);
   }

   // cout<< endl <<"Before select call: "<<fr.fd_array;
   // keep waiting for new request and

   nRet = select(nMaxFd+1, &fr, &fw, &fe, &tv);

   if(nRet > 0){
      // When someone connects or communicate with a message over a dedicatde 
      // connection
      cout<<endl<<"Data on port....Processing now...";
      ProcessTheNewRequest();

   }else if(nRet == 0){
      // No connection or any communication request made or you
      // say that none of the socket descriptors are ready
   }
   else{
      // It failed and your application should show some useful message
      WSACleanup ();
      exit(EXIT_FAILURE);
   }

//    cout<<endl<<"After the select call:" << fr.fd_count;
//    Sleep(2000);
   
}
return 0;
}
