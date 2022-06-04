#pragma once
#include "imgui.h"
#include <pthread.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../Networking/Connection.h"
#include "../Networking/Messages.h"
#include "../Alert.h"

class TripwireUI {

private:

int             my_image_width          = 40;
int             my_image_height         = 40;
GLuint          my_image_texture        = 0;
bool            ret;

void    calibration();


public:


        TripwireUI();
void    render();
        ~TripwireUI();

};