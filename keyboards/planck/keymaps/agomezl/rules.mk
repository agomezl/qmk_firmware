SRC += muse.c
# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LTO_ENABLE = yes
COMMAND_ENABLE    = yes
BOOTMAGIC_ENABLE  = full
MOUSEKEY_ENABLE   = yes
KEY_LOCK_ENABLE   = yes

DYNAMIC_MACRO_ENABLE = yes

# WE have no RGB D=
RGBLIGHT_ENABLE   = no
RGB_MATRIX_ENABLE = no
