#pragma once

#include <GLFW/glfw3.h>
#include "imgui.h"
#include <iostream>
#include <AL/al.h>
#include <AL/alc.h>
#include <irrKlang/irrKlang.h>

extern ImVec4      alert_color;
extern ImVec4      background_color;


void Alert_color();

void alert_noise();

void alert();

void reset_alert_sounds();