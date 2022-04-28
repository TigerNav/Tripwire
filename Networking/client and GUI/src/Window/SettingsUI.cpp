#include "SettingsUI.h"

SettingsUi::SettingsUi() {

}

void
SettingsUi::color_settings() {
    if(ImGui::CollapsingHeader("Color")) {
        ImGui::Text("Warning : You should keep your background color and your alert color different.");
        ImGui::ColorEdit3("Alert Colour", (float*)&alert_color);
        ImGui::ColorEdit3("Background Color", (float*)&background_color);
        ImGui::Checkbox("Test Color Alert", &test_alert);

        if(test_alert) {
            Alert_color();
            
        }else{
            glClearColor(background_color.x, background_color.y, background_color.z, background_color.w);
        }
    }
}

void
SettingsUi::window_options() {

    if(ImGui::CollapsingHeader("Window Options")) {
        if(ImGui::BeginTable("split", 3)) {
            ImGui::TableNextColumn(); ImGui::Checkbox("No move", &no_move);
            ImGui::TableNextColumn(); ImGui::Checkbox("No resize", &no_resize);
            ImGui::TableNextColumn(); ImGui::Checkbox("No collapse", &no_collapse);
            ImGui::TableNextColumn(); ImGui::Checkbox("No close", &no_close);
            ImGui::TableNextColumn(); ImGui::Checkbox("No background", &no_background);
            ImGui::TableNextColumn(); ImGui::Checkbox("No bring to front", &no_bring_to_front);
            ImGui::EndTable();
        }
    }
    

}

void
SettingsUi::render() {

    ImGuiWindowFlags        window_flags  = 0;
    if (no_move)            window_flags |= ImGuiWindowFlags_NoMove;
    if (no_resize)          window_flags |= ImGuiWindowFlags_NoResize;
    if (no_collapse)        window_flags |= ImGuiWindowFlags_NoCollapse;
    if (no_background)      window_flags |= ImGuiWindowFlags_NoBackground;
    if (no_bring_to_front)  window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
    
    ImGui::Begin("GUI Settings", &open_ptr, window_flags);  

    color_settings();
    window_options();

    
    ImGui::End();            
    

}

SettingsUi::~SettingsUi() {

}