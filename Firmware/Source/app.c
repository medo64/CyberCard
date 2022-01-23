#include <stdint.h>
#include "hardware.h"
#include "io.h"
#include "state.h"
#include "uart.h"

#include "Microchip/usb.h"
#include "Microchip/usb_device.h"
#include "Microchip/usb_device_cdc.h"

#define LED_TIMEOUT       2000
#define LED_TIMEOUT_NONE  65535
uint16_t LedTimeout = LED_TIMEOUT_NONE;

void main(void) {
    init();
    io_init();

    io_splash();

    uart_init();
    uart_setup(2400);

    USBDeviceInit();
    USBDeviceAttach();

    io_activity_led_off();

    while(true) {
        if (LedTimeout != LED_TIMEOUT_NONE) {
            if (LedTimeout == 0) {
                io_activity_led_off();
                LedTimeout = LED_TIMEOUT_NONE;
            } else {
                LedTimeout--;
            }
        }

        if (USBGetDeviceState() < CONFIGURED_STATE) { continue; }
        if (USBIsDeviceSuspended() == true) { continue; }


        // UART receive
        while ((UartReadBufferCount < UART_READ_BUFFER_MAX) && uart_tryReadByte(&UartReadBuffer[UartReadBufferEnd])) {
            io_activity_led_on();
            LedTimeout = LED_TIMEOUT;

            UartReadBufferEnd = (UartReadBufferEnd + 1) % UART_READ_BUFFER_MAX;
            UartReadBufferCount++;
        }

        // UART send
        if ((UartWriteBufferCount > 0) && uart_tryWriteByte(UartWriteBuffer[UartWriteBufferStart])) {
            io_activity_led_on();
            LedTimeout = LED_TIMEOUT;

            UartWriteBufferStart = (UartWriteBufferStart + 1) % UART_WRITE_BUFFER_MAX;
            UartWriteBufferCount--;
        }

        // USB receive
        uint8_t usbCount = getsUSBUSART(UsbReadBuffer, USB_READ_BUFFER_MAX); //until the buffer is free.
        if (usbCount > 0) {
            io_activity_led_on();
            LedTimeout = LED_TIMEOUT;

            //copy buffer
            for (int i=0; i<usbCount; i++) {
                UartWriteBuffer[UartWriteBufferEnd] = UsbReadBuffer[i];
                if (UartWriteBufferCount < UART_WRITE_BUFFER_MAX) {
                    UartWriteBufferEnd = (UartWriteBufferEnd + 1) % UART_WRITE_BUFFER_MAX;
                    UartWriteBufferCount++;
                }
            }
        }

        // USB send
        if(UartReadBufferCount > 0) {
            io_activity_led_on();
            LedTimeout = LED_TIMEOUT;

            uint8_t usbCount = 0;
            for (int i=0; i<USB_WRITE_BUFFER_MAX; i++) {
                if (UartReadBufferCount > 0) {
                    UsbWriteBuffer[i] = UartReadBuffer[UartReadBufferStart];
                    UartReadBufferStart = (UartReadBufferStart + 1) % UART_READ_BUFFER_MAX;
                    UartReadBufferCount--;
                    usbCount++;
                } else {
                    break;
                }
            }

            putUSBUSART(&UsbWriteBuffer[0], usbCount);
        }

        CDCTxService();
    }
}


void interrupt SYS_InterruptHigh(void) {
    USBDeviceTasks();
}
