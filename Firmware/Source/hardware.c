#include <xc.h>
#include <pic16f1454.h>
#include "hardware.h"


void init(void) {
    interrupt_disable();

    // Oscillator
    OSCCONbits.IRCF = 0b1111;  // 16 MHz or 48 MHz HF
    OSCCONbits.SPLLMULT = 1;  // 3x PLL is enabled
    OSCCONbits.SPLLEN = 1;  // PLL is enabled
    ACTCONbits.ACTSRC = 1;  // The HFINTOSC oscillator is tuned using Fll-speed USB events
    ACTCONbits.ACTEN = 1;  // ACT is enabled, updates to OSCTUNE are exclusive to the ACT

    // IO * A5:led  A4:led2  A1:d-  A0:d+   C5:rx  C4:tx
    LATA = 0b00000000;  // A5:off  A4:off
    LATC = 0b00000000;
    TRISA = 0b00110000;  // A5:input  A4:input
    TRISC = 0b00100000;  // C5:rx  C4:tx

    interrupt_enable();
}

void wait_short(void) {
    __delay_ms(150);
}
