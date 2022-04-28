#pragma once
#include "imgui.h"
#include <GLFW/glfw3.h>
#include "../Alert.h"
#include <iostream>
#include <unistd.h>
#include <math.h>

class SettingsUi {
    
private:


bool        open_ptr            = true;
bool        test_alert          = false;
bool        no_move             = false;
bool        no_resize           = false;
bool        no_collapse         = false;
bool        no_close            = false;
bool        no_background       = false;
bool        no_bring_to_front   = false;

void        color_settings();
void        window_options();

public:

            SettingsUi();
void        render();   
            ~SettingsUi();

};