### CyberCard ###

There are three board variants that can be made using the same PCB and varying
parts.


### TTL UART ####

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
|  2 | R 3.3K 0.125W (0805)                      | R7-R8   | RMCF0805FT3K30CT-ND |
|  1 | U Si8621AB-B-IS‎ (SOIC-8)                  | U2      | SI8621AB-B-IS-ND    |
|  1 | VR L78L05ACD13TR (SO-8)                   | VR1     | 497-1180-1-ND       |
