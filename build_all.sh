#!/bin/bash
# Build every converter variant; AVR targets are skipped when avr-gcc is missing.
AVR="atmega32u2_atmel_dfu atmega32u2_usbasploader atmega32u4_atmel_dfu atmega32u4_bootloadhid atmega32u4_caterina atmega32u4_halfkay atmega32u4_qmk_dfu atmega32u4_qmk_hid atmega32u4_usbasploader"
ARM="weact_g431 rpi_pico rpi_pico2"

VARIANTS=$ARM
if command -v avr-gcc >/dev/null; then
    VARIANTS="$AVR $ARM"
else
    echo "avr-gcc not found: skipping AVR variants"
fi

failed=()
for keymap in vial vial_VERY_INSECURE; do
    for var in $VARIANTS; do
        make -j converter/ibmpc_usb/$var:$keymap || failed+=("$var:$keymap")
    done
done

if [ ${#failed[@]} -gt 0 ]; then
    echo "FAILED: ${failed[*]}"
    exit 1
fi
echo "All builds OK"
