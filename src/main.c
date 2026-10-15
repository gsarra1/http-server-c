//all the includes are explained in the Documentation of the project.
//default includes of the C23 language standard version.
#include <stdio.h>
#include <stdlib.h> //provides other functions like malloc (dinamically allocated memory).

//includes for the socket programming.
#include <unistd.h> //provides access to the POSIX operating system API like read, write, close.
#include <sys/socket.h> //provides the socket functions like socket, bind, listen, accept.
#include <netinet/in.h> //IPv4 and IPv6 specific structures and functions like sockaddr_in.
#include <arpa/inet.h> //provides functions for IP address manipulation like inet_addr, inet_ntoa.

int main() {
    //fd stands for file descriptor, it is an integer that uniquely identifies an open file in a computer's operating system. It's -1 if failed
    //In this case, it is used to identify the socket that will be created for the server.
    //AF_INET STANDS FOR Address Family Internet, it is used to specify that the socket will use the IPv4 protocol.
    //to use IPv6, we would use AF_INET6 instead of AF_INET.
    //to use the socket, we need to create it first, and then bind it to a specific address and port number.
    int fd_server = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM is the socket type for TCP, and 0 is the protocol (0 means default protocol for the given socket type).
    
    if (fd_server == -1) { //if the socket creation fails, it returns -1.
        perror("socket"); //defined in <stdio.h>, it prints the error message labeled with the string "socket".
        //it's written EXIT_FAILURE even tho you can also use 1, but EXIT_FAILURE is more readable and portable.
        return EXIT_FAILURE; //It's a constant defined in <stdlib.h> that indicates the program failed to execute successfully.
    }

    printf("Server socket created successfully.\n");
    printf("Server socket file descriptor: %d\n", fd_server); //the number should be 3 because 0, 1, and 2 are reserved for standard input, output, and error respectively.
    
    return 0;
}