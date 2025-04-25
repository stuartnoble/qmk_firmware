# Off to reduce binary size
AUTO_SHIFT_ENABLE = no
BACKLIGHT_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
GRAVE_ESC_ENABLE = no
OS_DETECTION_ENABLE = no
RGBLIGHT_ENABLE = no
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE = no
WPM_ENABLE = no

# Actively in use
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes
MOUSEKEY_ENABLE = yes
OLED_ENABLE = yes
SPLIT_KEYBOARD = yes
VIA_ENABLE = yes

SRC += oled/glyphs/keymaps.c oled/glyphs/layers.c oled/glyphs/modifiers.c oled/primary.c oled/secondary.c oled.c