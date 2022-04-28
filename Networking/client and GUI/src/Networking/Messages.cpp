#include "Messages.h"

bool calibration_signal;
bool disconnect_signal;
bool recalibrated_signal;
bool alert_system;

bool get_calibration_signal() {
    return calibration_signal;
}
void set_calibration_signal(bool flag) {
    calibration_signal = flag;
}
bool get_disconnect_signal() {
    return disconnect_signal;
}
void set_disconnect_signal(bool flag) {
    disconnect_signal = flag;
}
bool get_reset_signal() {
    return recalibrated_signal;
}
void set_reset_signal(bool flag) {
    recalibrated_signal = flag;
}
bool get_alert_system() {
    return alert_system;
}
void set_alert_system(bool flag) {
    alert_system = flag;
}


