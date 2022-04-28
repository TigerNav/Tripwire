#pragma once

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h> 
#include "Messages.h"
#include "../Alert.h"


#define PORT 5000

void        connect();
void        error_check();
void        *connection_loop(void *ptr);


