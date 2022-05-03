cmake_minimum_required(VERSION 3.10)

# set the project name
project(GUI)

# add the executable
include_directories(${PROJECT_SOURCE_DIR}/include)
target_link_libraries(/usr/lib/libGL.so)
add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp 
                ${PROJECT_SOURCE_DIR}/src/image.cpp 
                ${PROJECT_SOURCE_DIR}/src/Alert.cpp
                ${PROJECT_SOURCE_DIR}/src/Networking/Connection.cpp
                ${PROJECT_SOURCE_DIR}/src/Networking/Messages.cpp
                ${PROJECT_SOURCE_DIR}/src/Window/Gui.cpp
                ${PROJECT_SOURCE_DIR}/src/Window/SettingsUI.cpp
                ${PROJECT_SOURCE_DIR}/src/Window/TripwireUI.cpp
                ${PROJECT_SOURCE_DIR}/include/imgui_demo.cpp
                ${PROJECT_SOURCE_DIR}/include/imgui_draw.cpp
                ${PROJECT_SOURCE_DIR}/include/imgui_impl_glfw.cpp
                ${PROJECT_SOURCE_DIR}/include/imgui_impl_opengl3.cpp
                ${PROJECT_SOURCE_DIR}/include/imgui_tables.cpp
                ${PROJECT_SOURCE_DIR}/include/imgui_widgets.cpp
                ${PROJECT_SOURCE_DIR}/include/imgui.cpp)
                
                