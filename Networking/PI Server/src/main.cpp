#include <iostream>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>
#include <wiringSerial.h>

#define PORT 5000

int socket_desc, client_sock, client_size;

char message_recived[50];
char message_sent[50];

struct sockaddr_in Server_Address;
struct sockaddr_in Client_Address;

pthread_t thread;
pthread_t other_thread;

bool calibration_initilization;

int serialDeviceID = 0;

void *messages(void *ptr) {
    while(1) {
        if(recv(client_sock, message_recived, sizeof(message_recived), 0) <  0) {
            perror("go fuck yourself");
            exit(0);
        }else {
            if(strchr(message_recived, '1') != NULL && calibration_initilization) {
                std::cout << message_recived << std::endl;
                unsigned char serial_message = 'c';
                serialPutchar(serialDeviceID, serial_message);
                
                calibration_initilization = false;
            }

            if(strchr(message_recived, 'r') != NULL) {
                unsigned char serial_message = 'r';
                serialPutchar(serialDeviceID, serial_message);
            }

            if(strchr(message_recived, 'e') != NULL) {
                std::cout << "the client has left" << std::endl; 
                unsigned char exit_message = 'e';
                serialPutchar(serialDeviceID, exit_message);
                break;
            }
        }

// TODO         make new thread to read incoming serial data on time

        
    }
} 

void *get_arduino_char(void *ptr) {

    while(1) {
        int value = serialGetchar(serialDeviceID);
        putchar(value);
        fflush(stdout);
        if(value == 'i') {
            strcpy(message_sent, "i");
            if (send(client_sock, message_sent, sizeof(message_sent), 0) < 0)
            {
                std::cout << "shit\n";
            }
                
        }

    }
}


int main() {

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    serialDeviceID = serialOpen("/dev/ttyACM0", 9600);

    if(serialDeviceID == -1) {
        std::cout << "shit bruh\n";
    }

    if(socket_desc < 0) {
        printf("\n shit fuck \n");
        exit(1);
    }

    

    // Defines Connection outside machine
    Server_Address.sin_family       = AF_INET;
    // Opening Port
    Server_Address.sin_port         = htons(PORT);
    // IP
    Server_Address.sin_addr.s_addr  = inet_addr("192.168.1.140");


    // Binds server to port and IP

    if((bind(socket_desc, (struct sockaddr*) &Server_Address, sizeof(Server_Address))) < 0) {
        perror("Error while trying to bind");
        exit(1);
    }
    
    // Find any clients that are trying to join
    if((listen(socket_desc, 1)) < 0) {
        printf("\n Could not find any clients \n");
    }

    
// TODO work on differnt types of messages being recived

    while(1) {

        client_size = sizeof(Client_Address);
        if((client_sock = accept(socket_desc, (struct sockaddr*) &Client_Address, (socklen_t*) &client_size)) < 0)
            std::cout << "error with accepting connection" << std::endl;
        std::cout << "found client" << std::endl;
        calibration_initilization = true;

        pthread_create(&thread, NULL, &messages, NULL);

        pthread_create(&other_thread, NULL, &get_arduino_char, NULL);

        std::cout << "reset loop" << std::endl;
        

    }

}