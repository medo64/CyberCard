### CyberCard ###

There are three board variants that can be made using the same PCB and varying
parts.


#### USB-to-Serial ####

This is a basic variant and provides USB serial port directly connected to UPS'
serial output.

##### Input (USB) #####

Voltage: 5 V
Current: 100 mA

##### Parts #####

|  # | Part                                      | RefDes  | Part Number         |
|---:|-------------------------------------------|---------|---------------------|
|  4 | C 100nF 25V X7R (0805)                    | C1-C4   | 399-1170-1-ND       |
|  3 | C 470nF 25V X7R (0805)                    | C5-C7   | 1276-6480-1-ND      |
|  4 | DS LED (0805)                             | DS1-DS4 | 475-1415-1-ND       |
|  1 | J USB B, horizontal                       | J1      | ED2983-ND           |
|  1 | L Ferrite 1A 40Ohm (0805)                 | L1      | 445-2201-1-ND       |
|  4 | R 100 0.125W (0805)                       | R1-R4   | RMCF0805FT100RCT-ND |
|  4 | R 3.3K 0.125W (0805)                      | R5-R8   | RMCF0805FT3K30CT-ND |
|  1 | U MCP2221A-I/SL (SOIC-14)                 | U1      | MCP2221A-I/SL-ND    |
|  1 | U Si8621AB-B-IS‎ (SOIC-8)                  | U2      | SI8621AB-B-IS-ND    |
|  1 | VR L78L05ACD13TR (SO-8)                   | VR1     | 497-1180-1-ND       |


#### Flexible USB-to-Serial ####

In the case you want a bit more flexibility, you can use PIC16F1454 in the place
of MCP2221A with the custom firmware. Microcontroller will serve as a buffer and
convert any bitrate to `2400,N,8,1` UPS needs.

##### Input (USB) #####

Voltage: 5 V
Current: 100 mA

##### Parts #####

|  # | Part                                      | RefDes  | Part Number         |
|---:|-------------------------------------------|---------|---------------------|
|  4 | C 100nF 25V X7R (0805)                    | C1-C4   | 399-1170-1-ND       |
|  3 | C 470nF 25V X7R (0805)                    | C5-C7   | 1276-6480-1-ND      |
|  4 | DS LED (0805)                             | DS1-DS4 | 475-1415-1-ND       |
|  1 | J USB B, horizontal                       | J1      | ED2983-ND           |
|  1 | L Ferrite 1A 40Ohm (0805)                 | L1      | 445-2201-1-ND       |
|  4 | R 100 0.125W (0805)                       | R1-R4   | RMCF0805FT100RCT-ND |
|  4 | R 3.3K 0.125W (0805)                      | R5-R8   | RMCF0805FT3K30CT-ND |
|  1 | U PIC16F1454-I/SL (SOIC-14)               | U1      | PIC16F1454-I/SL-ND  |
|  1 | U Si8621AB-B-IS‎ (SOIC-8)                  | U2      | SI8621AB-B-IS-ND    |
|  1 | VR L78L05ACD13TR (SO-8)                   | VR1     | 497-1180-1-ND       |


#### TTL UART ####

In case you don't want USB but just isolated TTL UART connection, you can remove
quite a few parts and connect to isolated RX/TX lines. While this is useful for
troubleshooting, it's not a recommended interface.

##### Input #####

Voltage: 5 V ±10%
Current: 50 mA

##### Parts #####

|  # | Part                                      | RefDes  | Part Number         |
|---:|-------------------------------------------|---------|---------------------|
|  3 | C 100nF 25V X7R (0805)                    | C2-C4   | 399-1170-1-ND       |
|  2 | C 470nF 25V X7R (0805)                    | C5,C7   | 1276-6480-1-ND      |
|  1 | D 100mA 30V CC (SOT23-3)                  | D1      | TBAT54CLMCT-ND      |
|  2 | DS LED (0805)                             | DS3-DS4 | 475-1415-1-ND       |
|  1 | J Header (4w)                             | J2      | S9016E-04-ND        |
|  1 | L Ferrite 1A 40Ohm (0805)                 | L1      | 445-2201-1-ND       |
|  4 | R 100 0.125W (0805)                       | R1-R4   | RMCF0805FT100RCT-ND |
|  4 | R 3.3K 0.125W (0805)                      | R7-R8   | RMCF0805FT3K30CT-ND |
|  1 | U Si8621AB-B-IS‎ (SOIC-8)                  | U2      | SI8621AB-B-IS-ND    |
|  1 | VR L78L05ACD13TR (SO-8)                   | VR1     | 497-1180-1-ND       |
