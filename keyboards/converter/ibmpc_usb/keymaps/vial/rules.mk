VIA_ENABLE = yes
VIAL_ENABLE = yes
LTO_ENABLE = yes
# Trim features only on AVR, where flash and EEPROM are tight
ifneq ($(filter atmega% at90%,$(MCU)),)
    NKRO_ENABLE = no
    MOUSEKEY_ENABLE = no
    QMK_SETTINGS = no
endif
