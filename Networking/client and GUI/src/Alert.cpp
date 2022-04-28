#include "Alert.h"

int         counter             = 0;
int         counter2            = 0;
bool        back_color          = false;
bool        aler_color          = true;
ImVec4      alert_color         = ImVec4(1.00f, 0, 0, 1.00f);
ImVec4      background_color    = ImVec4(0, 0, 0, 1.00f);

void Alert_color() {
    counter++;
    if(counter ==  10) {
        if(aler_color) {
            glClearColor(alert_color.x, alert_color.y, alert_color.z, alert_color.w);
            counter2++;
            if(counter2 == 2){
                back_color = true;
                aler_color = false;
            }         
        }           
        if(back_color) {
            glClearColor(background_color.x, background_color.y, background_color.z, background_color.w);
            counter2 = 0;
            aler_color = true;
            back_color = false;
        } 
        counter = 0;        
    }
}