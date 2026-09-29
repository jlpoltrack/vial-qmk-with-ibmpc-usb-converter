# Raspberry Pi Pico 2 (RP2350)

* Hardware: Raspberry Pi Pico 2 (RP2350A), ARM Cortex-M33 mode
* Same pinout and protocol code as the [Pico (RP2040)](../rpi_pico/readme.md) target

## 5V signals

Unlike the RP2040, RP2350 GPIOs (except GP26-29) are 5V tolerant **while the
Pico is powered**. Because the keyboard is powered from the Pico's VBUS, the
keyboard's own 5V clock/data pull-ups are within spec. Moving them to 3.3V
(3V3 OUT, pin 36) is still the more conservative choice.

## Wiring

Keyboard     | Pico 2
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

RP2350 erratum E9 can leave an undriven input pad floating near 2.2V, so fit
a pull-down of 8.2k or less on the MOSFET gate(s) to keep the solenoid off
during boot.

## Build

    make converter/ibmpc_usb/rpi_pico2:vial

## Flashing

* **First flash:** hold BOOTSEL while plugging in, then copy the `.uf2` to the `RP2350` drive.
* **After that:** `./flash.sh rpi_pico2` (hands-free with the `vial_VERY_INSECURE` or `debug` keymaps),
  a `QK_BOOT` key, or double-tap the RUN/reset line.
