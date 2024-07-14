# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
HAPTIC_ENABLE = yes
HAPTIC_DRIVER = SOLENOID

SRC += matrix.c ibmpc.c
