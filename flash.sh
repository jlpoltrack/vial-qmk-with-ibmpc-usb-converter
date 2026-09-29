#!/bin/bash
# Build and flash the converter without touching BOOT0/BOOTSEL.
# Needs a vial_VERY_INSECURE or debug build already running (or the board in its bootloader).
# Usage: ./flash.sh <weact_g431|rpi_pico|rpi_pico2> [keymap] [extra qmk compile args, e.g. -e CONSOLE_ENABLE=yes]
set -e
VARIANT=${1:?usage: ./flash.sh <weact_g431|rpi_pico|rpi_pico2> [keymap] [qmk args]}
KM=${2:-vial_VERY_INSECURE}
shift; shift || true
KB=converter/ibmpc_usb/$VARIANT
PYTHON=${PYTHON:-python3}

qmk compile -kb "$KB" -km "$KM" "$@"
BASE=".build/$(echo "$KB" | tr / _)_$KM"

case "$VARIANT" in
    rpi_pico)  UF2_VOLUME=${UF2_VOLUME:-/Volumes/RPI-RP2} ;;
    rpi_pico2) UF2_VOLUME=${UF2_VOLUME:-/Volumes/RP2350} ;;
esac

case "$VARIANT" in
    rpi_pico*) in_boot() { [ -d "$UF2_VOLUME" ]; } ;;
    *)        in_boot() { dfu-util -l 2>/dev/null | grep -q "0483:df11"; } ;;
esac

if ! in_boot; then
    echo "Requesting bootloader jump over raw HID..."
    "$PYTHON" - <<'PY'
import hid
devs = [d for d in hid.enumerate(0xFEED, 0x6536) if d['usage_page'] == 0xFF60]
if not devs:
    raise SystemExit("converter not found on USB")
h = hid.Device(path=devs[0]['path'])
try:
    h.write(b'\x00\x0b'.ljust(33, b'\x00'))  # VIA id_bootloader_jump
except hid.HIDException:
    pass  # the board may reset before acknowledging the report
PY
    for _ in $(seq 1 50); do in_boot && break; sleep 0.2; done
    in_boot || { echo "No bootloader found (secure build? enter it by hand once)"; exit 1; }
fi

case "$VARIANT" in
    rpi_pico*)
        sleep 1  # let the drive finish mounting
        cp "$BASE.uf2" "$UF2_VOLUME/" ;;
    *)
        dfu-util -a 0 -d 0483:df11 -s 0x08000000:leave -D "$BASE.bin" 2>&1 \
            | grep -E "File downloaded|Error during download get_status" >/dev/null ;;
esac
echo "Flashed $BASE"
