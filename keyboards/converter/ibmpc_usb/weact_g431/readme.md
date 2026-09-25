# WeAct STM32G431 Core Board

* Hardware: [WeAct STM32G431CoreBoard](https://github.com/WeActStudio/WeActStudio.STM32G431CoreBoard) (STM32G431CBU6, QFN48)

## Wiring

Keyboard     | G431 pin (header P1)
:----------- | :-------------------
Clock        | PB7
Signal GND   | PB6 (GPIO driven low)
Data         | PB5
VCC          | 5V
GND          | GND

PB6 is a GPIO held low (max ~20mA), so it can only serve as a signal/shield
ground. The keyboard's supply ground must go to a real GND pin (P1 pin 1).

PB7/PB5 use the MCU's internal pull-ups. Add external 4.7k pull-ups to 5V if
the keyboard's signal edges are slow or unreliable.

## Build

    make converter/ibmpc_usb/weact_g431:vial

## Flashing

* **First flash:** hold BOOT0, tap NRST, release BOOT0, then `make converter/ibmpc_usb/weact_g431:vial:flash`.
* **After that (no buttons):** use Vial's "Reboot to bootloader" (the `vial` keymap requires
  unlocking first: hold Esc + Enter), or a `QK_BOOT` key assigned in Vial, then run the flash command.
* **SWD:** the 4-pin header (PA13/PA14) works with an ST-Link, e.g.
  `st-flash --reset write .build/converter_ibmpc_usb_weact_g431_vial.bin 0x08000000`.
