[CyberCard Protocol](https://medo64.com/cybercard/)
===================================================


## Commands

Each command must be terminated with `<CR>`. Response will be start with `#`
(hash) character and will end with `<CR>`. Invalid commands will result in
`#-3<CR>` response.


### Current information (D)

This command will retrieve current UPS input/output information.

| Send           | Response (example)                                                   |
|----------------|----------------------------------------------------------------------|
| `D<CR>`        | `#I121.0O121.0L000B088F060.1R073S<0x80><0x84><0x90><0x80><0x80><CR>` |

Response will be a single line with the following fields.

| Field              | Example  | Description                           |
|--------------------|----------|---------------------------------------|
| Input voltage (V)  | `I121.0` | Current input voltage                 |
| Output voltage (V) | `O121.0` | Current output voltage                |
| Load (%)           | `L000`   | Load as compared to maximum UPS power |
| Battery (%)        | `B088`   | Battery charge status                 |
| Frequency (Hz)     | `F060.1` | Measured line frequency               |
| Run time (minutes) | `R073`   | Estimated runtime upon power loss     |
| Status bits        |          | See table below                       |

The following are known status bits.

| Byte | Bit | Meaning (0:no 1:yes) |
|-----:|----:|----------------------|
|    1 |   2 | Power-up pending     |
|    1 |   3 | Shutdown pending     |
|    1 |   4 | Test in progress     |
|    1 |   5 | Currently beeping    |
|    1 |   6 | Battery capacity low |
|    1 |   7 | Battery in-use       |
|    2 |   4 | External power on    |
|    3 |   5 | Battery charging     |
|    3 |   7 | Battery full         |
|    5 |   7 | Shutdown             |


### Buzzer

This command will change buzzer status on/off.

| Send           | Response (example) | Description                            |
|----------------|--------------------|----------------------------------------|
| `C7:0<CR>`     | `#0<CR>`           | Buzzer is set to off                   |
| `C7:1<CR>`     | `#0<CR>`           | Buzzer is set to on                    |


### Model Information

These commands will output UPS model information.

| Send           | Response (example)                                      | Description                                                           |
|----------------|---------------------------------------------------------|-----------------------------------------------------------------------|
| `P1<CR>`       | `#12,140,90,10,300<CR>`                                 | Unknown, Voltage(max), Voltage(min), VoltageRange(%), Unknown         |
| `P2<CR>`       | `#0700,0400,120,057,063<CR>`                            | Power(VA), Power(W), Voltage(nominal), Frequency(min), Frequency(max) |
| `P3<CR>`       | `#06.0,2x1,009.0,00<CR>`                                | BatteryVoltage(nominal), Battery(layout), BatteryVA(nominal), Unknown |
| `P4<CR>`       | `#OR700LCDRM1U,BFE7103_8S1,000000000000,CyberPower<CR>` | Product name, Firmware, SerialNumber, Manufacturer                    |
| `P5<CR>`       | `#120<CR>`                                              | Voltage(nominal)                                                      |
| `P6<CR>`       | `#140<CR>`                                              | Voltage(max)                                                          |
| `P7<CR>`       | `#90<CR>`                                               | Voltage(min)                                                          |
| `P8<CR>`       | `#10,20,30,40,50,60,70,80,90<CR>`                       | Unknown                                                               |
| `P9<CR>`       | `#<0xC3><0x87><0xE0><CR>`                               | Unknown                                                               |


### Power Control

These commands will control UPS power state.

| Send               | Response | Description                                                  |
|--------------------|----------|--------------------------------------------------------------|
| `S<CR>`            | `#0<CR>` | Immediate shutdown                                           |
| `S(NN)<CR>`        | `#0<CR>` | Shutdown after `(NN)` minutes                                |
| `S00R0000<CR>`     | `#0<CR>` | Immediate reboot                                             |
| `S(NN)R(MMMM)<CR>` | `#0<CR>` | Shutdown after `(NN)` minutes, reboot after `(MMMM)` minutes |
| `W<CR>`            | `#0<CR>` | Power on                                                     |
| `C<CR>`            | `#0<CR>` | Cancel shutdown                                              |


## Battery Test

These commands will control battery test.

| Send           | Response | Description                                      |
|----------------|----------|--------------------------------------------------|
| `T<CR>`        | `#0<CR>` | Quick test (switch to battery for a few seconds) |
| `TL<CR>`       | `#0<CR>` | Start deep battery test                          |
| `CT<CR>`       | `#0<CR>` | Cancel deep battery test                         |


## Physical Connection

Internal communication is routed over 10-pin connector at 2400,8,N,1 RS-232 at
5V TTL levels. Only 4 wires are fully connected to USP board. Middle two pins
are connected to internal connector but without any wires.

| Pin | Location | Description   |
|----:|:--------:|---------------|
|   1 |  Bottom  | GND           |
|   2 |   Top    | RX (to UPS)   |
|   3 |  Bottom  | TX (from UPS) |
|   4 |   Top    | +12V          |
|   5 |  Bottom  | Not used      |
|   6 |   Top    | Not used      |
|   7 |  Bottom  | Not connected |
|   8 |   Top    | Not connected |
|   9 |  Bottom  | Not connected |
|  10 |   Top    | Not connected |
