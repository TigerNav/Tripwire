#include "Connection.h"

int socket_desc;
int server_connection;
struct sockaddr_in server_addr;
char message_recived[50];
char message_send[50];

void connect()
{
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.140");
    server_connection = connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr));
}

void error_check()
{
    if (socket_desc < 0)
    {
        std::cout << "socket description not working" << std::endl;
    }
    if (server_connection < 0)
    {
        std::cout << "server not connection for some reason" << std::endl;
    }
}

// TODO work on disconnect signal

void *
connection_loop(void *ptr)
{

    while (true)
    {

        if (get_calibration_signal())
        {
            strcpy(message_send, "1");
            if (send(socket_desc, message_send, sizeof(message_send), 0) < 0)
            {
                std::cout << "error with sending message\n";
            }

            strcpy(message_send, "");
            set_calibration_signal(false);
        }

        if (get_reset_signal())
        {
            strcpy(message_send, "r");
            if (send(socket_desc, message_send, sizeof(message_send), 0) < 0)
            {
                std::cout << "error with sending message\n";
            }

            strcpy(message_send, "");
            set_reset_signal(false);
        }

        if (get_disconnect_signal())
        {
            strcpy(message_send, "e");
            if (send(socket_desc, message_send, sizeof(message_send), 0) < 0)
            {
                std::cout << "error with sending message\n";
            }
            std::cout << message_send << std::endl;
            strcpy(message_send, "");

            break;
        }

        if (recv(socket_desc, message_recived, sizeof(message_recived), 0) < 0)
        {
            std::cout << "shit niggasasda\n";
        }
        else
        {
             
            if (strchr(message_recived, 'i') != NULL)
            {
                std::cout << "shit\n";
                set_alert_system(true);
            }
        }
    }
}
