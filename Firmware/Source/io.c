#include <xc.h>
#include <stdint.h>
#include "hardware.h"
#include "io.h"

void io_init(void) {
    // Activity
    LATA4 = 0;   // default to off
    TRISA4 = 0;  // enable output
}

void io_splash(void) {
    io_activity_led_on(); wait_short(); io_activity_led_off(); wait_short();
    io_activity_led_on(); wait_short(); io_activity_led_off(); wait_short();
    io_activity_led_on(); wait_short(); io_activity_led_off();
}
