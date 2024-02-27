# Off to reduce binary size
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
OS_DETECTION_ENABLE = no
SWAP_HANDS_ENABLE = no
WPM_ENABLE = no
MOUSEKEY_ENABLE = no
AUTO_SHIFT_ENABLE = no   
RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no                       

# Actively in use
OLED_ENABLE = yes
SPLIT_KEYBOARD = yes 
ENCODER_ENABLE = yes 
LTO_ENABLE = yes
ENCODER_MAP_ENABLE = yes  
EXTRAKEY_ENABLE = yes       
CAPS_WORD_ENABLE = yes

SRC += oled/glyphs/keymaps.c oled/glyphs/layers.c oled/glyphs/modifiers.c