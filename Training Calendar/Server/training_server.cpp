#include<iostream>
#include<cstring>
#include<sys/time.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<map>

#define PORT 8888
#define MAX_CLIENT 100

using namespace std;

int main()
{
	int server_fd, new_socket, valread, client_socket[MAX_CLIENT], sd, max_sd, activity ;
	map<int , int> cshock_emp_id;
	int bufsize =1024;
	char buffer[bufsize]={0};
	int opt =1;
	char * hello = "Hello from server side";
	
	struct sockaddr_in server_address;
	int addrlen =sizeof(server_address);
	
	fd_set readfds;
	// initialize all client socket to 0 (untouched)
	for (int i = 0; i < MAX_CLIENT; i++)  
    	{  
        	client_socket[i] = 0;  
    	}  
	
	// Creating socket file descriptor
	// the function prototype is int s_fd = (domain. type, protocol);
	//domain int type values can be AF_LOCAL for process on same host system
	//AF_INET for IPv4 and AF_INET6 for IPv6 connection for process on diffrent host
	// type is for communication type
	// SOCK_STREAM: TCP
	// SOCK_DGRAM: UDP
	// protocol value, usually it is 0
	
	if( (server_fd = socket (AF_INET, SOCK_STREAM, 0)) <0 ) 
	{
		cerr<<"Socket failed"<<endl;
		exit(EXIT_FAILURE);
	}
	
	// Optional configration to make sure dont get problem in future
	
	//prototype int setsockopt(int socket_fd, int level , int optname , const char* optvalue, int optlen);
	// socket_fd : descriptor to identify socket
	// level : at which level the option is defined
	// optname like SO_BROADCAST etc
	// optval a pointer to a buffer in which the value for the requested option
	// optlen the size in bytes of buffer pointed by the optval
	
	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT , &opt, sizeof(server_address)) <0)
	{	
		// return 0 i=on success else return any error number
		cerr<<"setsockopt";
		exit(EXIT_FAILURE);
	}
	
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY; // for local host
	server_address.sin_port = htons(PORT);	     // host port 

	// binding socket to server_address and the port 8080
	if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address))< 0) 
	{
		cerr<<"bind failed";
		exit(EXIT_FAILURE);
	}
	
	cout<<"\n\n Listner on port :"<<PORT<<endl;
	
	if (listen(server_fd, 3) < 0) 
	{
		cerr<<"listen error";
		exit(EXIT_FAILURE);
	}
	
	cout<<"\n\n Waiting for new connection \n\n";
	struct timeval timeout;
    
    timeout.tv_sec = 10.0;
	timeout.tv_usec=0;
//-------------------------------------------------------------------------------------------------------//	
	//Daemonizing

	int pid = fork();
	cout<<"Daemonizing \n"<<std::endl;
	if(pid<0)
		cout<<" Fatal error \n";
	if(pid>0){
		cout<<"I am parent with id : "<<getppid(pid)<<endl<<system("ps")<<endl;
		exit(0);
		}
	if(pid==0){
		cout<<"I am child with id : "<<pid<<endl<<system("ps")<<std::endl;
		setsid();
		
		cout<<"New Parent id of child : "<<getppid(pid)<<endl;
		cout<<" Child Id is "<<getpid()<<endl;


//-------------------------------------------------------------------------------//
	while(true)  
  	  {  
  	  	//cout<<"Hello i am in loop \n";
        	//clear the socket set 
        	FD_ZERO(&readfds);  
     
        	//add master socket to set 
        	FD_SET(server_fd, &readfds);  
        	max_sd = server_fd;  
             
        	//add child sockets to set 
        	for (int i = 0 ; i < MAX_CLIENT ; i++)  
        	{  
        		//socket descriptor 
        	 	sd = client_socket[i];  
                 
            		//if valid socket descriptor then add to read list 
            		if(sd > 0)  
                	FD_SET( sd , &readfds);  
                 
            		//highest file descriptor number, need it for the select function 
           		(sd > max_sd) ; 
                	max_sd = sd;  
        	} 
        	//check select
        	activity = select( max_sd + 1 , &readfds , NULL , NULL , &timeout);  
       
        	if ((activity < 0) && (errno!=EINTR))  
        	{  
            		cerr<<"select error";  
        	} 
        	timeout.tv_sec+=10.0;
        	cout<<activity<<endl;
             
        	//If something happened on the master socket , 
        	//then its an incoming connection 
        	if (FD_ISSET(server_fd, &readfds))  
       		{  
            		if ((new_socket = accept(server_fd, (struct sockaddr *)&server_address, (socklen_t*)&addrlen))<0)  
            		{  
                		cerr<<"Error accept";  
                		exit(EXIT_FAILURE);  
            		}  
             
            		//inform user of socket number - used in send and receive commands 
            		cout<<"New connection , socket fd is: "<<new_socket<<" \n  ip  is:"<<inet_ntoa(server_address.sin_addr)<<"\n Port: "<<ntohs(server_address.sin_port)<<endl;  

					cshock_emp_id.insert(pair<int,int>(new_socket,read()))
					
            		//send new connection greeting message 
            		if( send(new_socket, hello, strlen(hello), 0) != strlen(hello) )  
            		{  
                		cerr<<"Error send"<<endl;  
            		}  
                 
            		cout<<"Welcome message sent successfully";
                 
            		//add new socket to array of sockets 
            		for (int i = 0; i < MAX_CLIENT; i++)  
           			 {  
                			//if position is empty 
                			if( client_socket[i] == 0 )  
                			{  
                    				client_socket[i] = new_socket;  
                    				cout<<"Adding to list of sockets as: " << i<<endl;                         
                    				
                    				break;  
                			}  
            			}  
        	} 
             
        //else its some IO operation on some other socket
        for (int i = 0; i < MAX_CLIENT; i++)  
        {  
            sd = client_socket[i];  
                 
            if (FD_ISSET( sd , &readfds))  
            {  
                //Check if it was for closing , and also read the 
                //incoming message 
                if ((valread = read( sd , buffer, 1024)) == 0)  
                {  
                    
					
					//Somebody disconnected , get his details and print 
                    getpeername(sd , (struct sockaddr*)&server_address , (socklen_t*)&addrlen);  
                    cout<<"Host disconnected , ip: "<<inet_ntoa(server_address.sin_addr)<<"   port: " <<ntohs(server_address.sin_port)<<endl;  
                         
                    //Close the socket and mark as 0 in list for reuse 
                    close( sd );  
                    client_socket[i] = 0;  
                }  
                     
                //Echo back the message that came in 
                
                else 
                {  
                    //set the string terminating NULL byte on the end 
                    //of the data read 
                    buffer[valread] = '\0';  
                    send(sd , buffer , strlen(buffer) , 0 );  
                }  
            }
        }
     } 

	}       	
	return 0;
}