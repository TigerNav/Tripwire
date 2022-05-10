#include "Gui.h"

Gui::Gui() {

    if(!glfwInit()) 
        perror("Glfw failed to initilizize");
    window = glfwCreateWindow(1280, 720, "Tripwire Control Panel    |   Version : ALPHA", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    
    connect();

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplOpenGL3_Init();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    
}

void
Gui::window_loop() {
    
    
    
    while(!glfwWindowShouldClose(window)) {
        
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        
        ImGui::NewFrame(); 
        
        settingUi.render();

        error_check();

        tripwireui.render();
 
        pthread_create(&network_thread, NULL, &connection_loop,NULL);
        
        

        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0,0,display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);

    }
    
    set_disconnect_signal(true);
    connection_loop(NULL);
    
}

Gui::~Gui() {
    
}