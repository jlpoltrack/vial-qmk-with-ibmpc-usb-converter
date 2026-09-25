#!/bin/bash
# Build and flash the WeAct G431 converter without touching BOOT0/NRST.
# Needs a vial_VERY_INSECURE build already running (or the board already in DFU).
# Usage: ./flash_g431.sh [keymap] [extra qmk compile args, e.g. -e CONSOLE_ENABLE=yes]
set -e
KB=converter/ibmpc_usb/weact_g431
KM=${1:-vial_VERY_INSECURE}
shift || true
PYTHON=${PYTHON:-python3}

qmk compile -kb "$KB" -km "$KM" "$@"
BIN=".build/$(echo "$KB" | tr / _)_$KM.bin"

in_dfu() { dfu-util -l 2>/dev/null | grep -q "0483:df11"; }

if ! in_dfu; then
    echo "Requesting bootloader jump over raw HID..."
    "$PYTHON" - <<'EOF'
import hid
devs = [d for d in hid.enumerate(0xFEED, 0x6536) if d['usage_page'] == 0xFF60]
if not devs:
    raise SystemExit("converter not found on USB")
h = hid.Device(path=devs[0]['path'])
try:
    h.write(b'\x00\x0b'.ljust(33, b'\x00'))  # VIA id_bootloader_jump
except hid.HIDException:
    pass  # the board may reset before acknowledging the report
EOF
    for _ in $(seq 1 50); do in_dfu && break; sleep 0.2; done
    in_dfu || { echo "No DFU device (secure build? press BOOT0 + NRST once)"; exit 1; }
fi

dfu-util -a 0 -d 0483:df11 -s 0x08000000:leave -D "$BIN" 2>&1 | grep -E "File downloaded|Error during download get_status" >/dev/null
echo "Flashed $BIN"
