# Raspberry Pi Pico 2 W (RP2350)

Same as [Pico 2](../rpi_pico2/readme.md) (wiring, 5V notes, solenoid, flashing),
except the wireless chip owns GP23-25 and GP29, so the onboard LED is unusable:

Lock LED     | Pin
:----------- | :--
Caps Lock    | GP8 (pin 11)
Num Lock     | GP4 (pin 6)
Scroll Lock  | GP5 (pin 7)

Wireless is not used. Build with `make converter/ibmpc_usb/rpi_pico2w:vial`.
