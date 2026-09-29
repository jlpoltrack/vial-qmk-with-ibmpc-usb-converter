# Raspberry Pi Pico (RP2040)

* Hardware: Raspberry Pi Pico (RP2040)

## 3.3V only

RP2040 GPIOs are **not 5V tolerant**. Before connecting, move the keyboard's
clock/data pull-ups from 5V to 3.3V (the Pico's 3V3 OUT, pin 36), or use a
bidirectional level shifter (e.g. BSS138). The IBM M122 reads these lines with
a TTL 7406/7407, which accepts a 3.3V high. The keyboard is still powered from 5V.

## Wiring

Keyboard     | Pico
:----------- | :---------------
GND          | GND (pin 3)
Clock        | GP2 (pin 4)
Data         | GP3 (pin 5)
VCC          | VBUS 5V (pin 40)

Clock and data are swapped automatically if wired the wrong way round
(keyboards that accept commands only, i.e. not XT).

Lock LED     | Pin
:----------- | :--
Caps Lock    | GP25 (onboard LED)
Num Lock     | GP4 (pin 6)
Scroll Lock  | GP5 (pin 7)

Solenoid     | Pin
:----------- | :--
Solenoid     | GP6 (pin 9, active high, via MOSFET with flyback diode)
Enable       | GP7 (pin 10, optional)

## Build

    make converter/ibmpc_usb/rpi_pico:vial

## Flashing

* **First flash:** hold BOOTSEL while plugging in, then copy the `.uf2` to the `RPI-RP2` drive.
* **After that:** `./flash.sh rpi_pico` (hands-free with the `vial_VERY_INSECURE` or `debug` keymaps),
  a `QK_BOOT` key, or double-tap the RUN/reset line.
