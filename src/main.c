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
    //part 1) create a socket for the server and check if it was created successfully.

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
    
    //TO BE DONE

    //part 2) bind the socket to a specific address and port number.
    struct sockaddr_in server_address; //struct that holds the address and port number of the server
    //the server_address struct is defined in <netinet/in.h> and it has the following fields:
    //sin_family: specifies the address family, in this case, it is AF_INET for IPv4. sin stands for "socket internet" and it is a prefix used to indicate that the field is related to the internet protocol.
    server_address.sin_family = AF_INET;
    //sin_port: specifies the port number, it is a 16-bit unsigned integer, and it needs to be converted to network byte order using the htons function.
    server_address.sin_port = htons(8080); 
    //sin_addr: specifies the IP address, it is a struct that holds the IP address in network byte order
    //.s_addr is a field of the sin_addr struct that holds the IP address as a 32-bit unsigned integer in network byte order.
    //hotnl is a function that converts a 32-bit unsigned integer from host byte order to network byte order. It is defined in <arpa/inet.h>.
    //server_address.sin_addr.s_addr = hotnl(INADDR_ANY); //INADDR_ANY is a constant that allows the server to accept connections from any IP address.
    return 0;
}