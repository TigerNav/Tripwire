#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#include <pthread.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "SettingsUI.h"
#include "TripwireUI.h"
#include "../Alert.h"
#include "../Networking/Connection.h"
#include "../Networking/Messages.h"


class Gui {

private:
GLFWwindow*    window;
bool           show_demo_window         = true; 
bool           show_another_window      = false;
SettingsUi     settingUi;
TripwireUI     tripwireui;
pthread_t      network_thread;

public:

               Gui();
void           window_loop();
               ~Gui();

};