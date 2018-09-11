LD_FILE = boards/samd51x20-bootloader.ld
USB_VID = 0x239A
USB_PID = 0x8021
USB_PRODUCT = "GameBoy M4 Cart"
USB_MANUFACTURER = "Chickadee Tech LLC"

INTERNAL_FLASH_FILESYSTEM = 1
LONGINT_IMPL = MPZ

CHIP_VARIANT = SAMD51J20A
CHIP_FAMILY = samd51

# No touch on SAMD51 yet
CIRCUITPY_TOUCHIO = 0

CIRCUITPY_AUDIOIO = 0
CIRCUITPY_AUDIOBUSIO = 0
CIRCUITPY_GBIO = 1
