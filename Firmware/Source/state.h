#ifndef STATE_H
#define	STATE_H


// UART receive ring buffer
#define UART_READ_BUFFER_MAX  240
uint8_t UartReadBuffer[UART_READ_BUFFER_MAX];
uint8_t UartReadBufferStart = 0;
uint8_t UartReadBufferEnd = 0;
uint8_t UartReadBufferCount = 0;

// UART transmit ring buffer
#define UART_WRITE_BUFFER_MAX  240
uint8_t UartWriteBuffer[UART_WRITE_BUFFER_MAX];
uint8_t UartWriteBufferStart = 0;
uint8_t UartWriteBufferEnd = 0;
uint8_t UartWriteBufferCount = 0;

// USB read buffer
#define USB_READ_BUFFER_MAX  32
uint8_t UsbReadBuffer[USB_READ_BUFFER_MAX];

// USB write buffer
#define USB_WRITE_BUFFER_MAX  32
uint8_t UsbWriteBuffer[USB_WRITE_BUFFER_MAX];


#endif	/* STATE_H */
