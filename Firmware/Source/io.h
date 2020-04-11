#ifndef IO_H
#define IO_H

#include <xc.h>


#define io_led_on()              TRISA5 = 0
#define io_led_off()             TRISA5 = 1

#define io_led_default()         TRISA5 = 0
#define io_led_active()          TRISA5 = 1

#endif
