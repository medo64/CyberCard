### CyberCard ###


#### Input ####

Voltage: 5 V ±10%
Current: 100 mA


#### Parts ####

|  # | Part                                      | RefDes  | Part Number         |
|---:|-------------------------------------------|---------|---------------------|
|  4 | C 100nF 25V X7R (0805)                    | C1-C4   | 399-1170-1-ND       |
|  3 | C 470nF 25V X7R (0805)                    | C5-C7   | 1276-6480-1-ND      |
|  2 | DS LED (0805)                             | DS1-DS2 | 475-1415-1-ND       |
|  1 | F 50mA 60V (1206)                         | F1      | 507-1793-1-ND       |
|  1 | J USB B, horizontal                       | J1      | ED2983-ND           |
|  1 | L Ferrite 1A 40Ohm (0805)                 | L1      | 445-2201-1-ND       |
|  3 | R 3.3K 0.125W (0805)                      | R1-R2   | RMCF0805FT3K30CT-ND |
|  1 | U MCP2221A-I/SL (SOIC-14)                 | U1¹     | MCP2221A-I/SL-ND    |
|  1 | U Si8421 (SOIC-8)                         | U2      | 336-1755-5-ND       |
|  1 | VR L78L05ACD13TR (SO-8)                   | VR1     | 497-1180-1-ND       |


#### Other Parts ####

In the case you want a bit more flexibility, you can use PIC16F1454 in the place
of MCP2221A with the custom firmware. This will give you a bit more flexibility
as it supports any bit rate toward UPS instead of `2400,N,8,1`.

|  # | Part                                      | RefDes  | Part Number         |
|---:|-------------------------------------------|---------|---------------------|
|  1 | U PIC16F1454-I/SL (SOIC-14)               | U1¹     | PIC16F1454-I/SL-ND  |
