### CyberCard Parts ###

|  # | Part                                      | RefDes  | Part Number                 | Alternate                   |
|---:|-------------------------------------------|---------|-----------------------------|-----------------------------|
|  2 | C 100nF X7R 16V (0805)                    | C4-C5   | 1276-1003-1-ND              | 1276-2444-1-ND              |
|  2 | C 470nF X7R 16V (0805)                    | C4-C5   | 1276-1074-1-ND              | 1276-1199-1-ND              |
|  2 | DS LED (0805)                             | DS1-DS2 | 475-1278-1-ND               | L171L-LWC-TR                |
|  1 | J USB B, horizontal                       | J1      | ED2982-ND                   | ED2983-ND                   |
|  6 | R 1.0K 0.125W (0805)                      | R1-R6   | RMCF0805FT1K00CT-ND         | RMCF0805JT1K00CT-ND         |
|  1 | U PIC16F1454-I/SL (SOIC-14)               | U1      | PIC16F1454-I/SL-ND          | PIC16F1454T-I/SLCT-ND       |
|  2 | U PC817C (SMD-4)                          | U2-U3   | 732-140817143200CT-ND       | ISP817CXSMCT-ND             |
|  1 | VR L78L05ACD13TR (SO-8)                   | VR1     | 497-1180-1-ND               | MC78L05ACDR2GOSCT-ND        |


#### Board Size ####

|       |      Dimensions | Area    | Thickness |
|-------|-----------------|---------|-----------|
| PCB   |  75.0 x 42.5 mm | 5.0 in² |    1.6 mm |
| Panel |  54.0 x 36.5 mm | 3.1 in² |    1.6 mm |


#### TTL UART Board ####

If only TTL UART access is required, the following components should be omitted:
  * C1
  * C3
  * DS1
  * J1
  * R3
  * U1

Instead of the components used, 4-pin male right-angle header should be placed
with a standard 5V USB to TTL serial cable connected to it. While 5V TTL cable
is preferred, the device should work with 3.3V TTL cable too.

A dab of hot glue is suggested on the connection to prevent accidental unplug.

On the computer side, serial port should be accessed using the following serial
port parameters: 2400,8,N,1.


#### Power ####

| Property | Value  |
|----------|-------:|
| Voltage  |    5 V |
| Current  | 100 mA |
