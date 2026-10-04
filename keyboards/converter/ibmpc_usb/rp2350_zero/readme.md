# Waveshare RP2350-Zero

* Hardware: Waveshare RP2350-Zero (RP2350A), ARM Cortex-M33 mode
* Same protocol code and GPIOs as the [Pico 2](../rpi_pico2/readme.md) target
* Onboard WS2812 RGB LED (GP16) shows lock state

## 5V signals

RP2350 GPIOs (except GP26-29) are 5V tolerant **while the board is powered**,
so the keyboard's own 5V clock/data pull-ups are within spec. Pull-ups to 3V3
are still the more conservative choice.

## Wiring

Keyboard     | RP2350-Zero
:----------- | :----------
GND          | GND
Clock        | GP10
Data         | GP12
VCC          | 5V

Clock and data are swapped automatically if wired the wrong way round
(keyboards that accept commands only, i.e. not XT).

Lock LED     | Pin
:----------- | :--
All          | Onboard RGB LED: Caps red, Num green, Scroll blue (colors mix)
Num Lock     | GP4 (optional external LED)
Scroll Lock  | GP5 (optional external LED)

If Caps Lock shows green, change `WS2812_BYTE_ORDER` to `WS2812_BYTE_ORDER_GRB`
in `config.h`.

Solenoid     | Pin
:----------- | :--
Solenoid     | GP6 (active high, via MOSFET with flyback diode)
Enable       | GP7 (optional)

RP2350 erratum E9 can leave an undriven input pad floating near 2.2V, so fit
a pull-down of 8.2k or less on the MOSFET gate(s) to keep the solenoid off
during boot.

## Build

    make converter/ibmpc_usb/rp2350_zero:vial

## Flashing

* **First flash:** hold BOOT while plugging in (or while pressing RESET), then copy the `.uf2` to the `RP2350` drive.
* **After that:** `./flash.sh rp2350_zero` (hands-free with the `vial_VERY_INSECURE` or `debug` keymaps),
  a `QK_BOOT` key, or double-tap RESET.
