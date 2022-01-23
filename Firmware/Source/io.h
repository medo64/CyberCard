#ifndef IO_H
#define IO_H

#include <xc.h>


#define io_activity_led_on()   LATA4 = 1
#define io_activity_led_off()  LATA4 = 0

void io_init(void);
void io_splash(void);

#endif
