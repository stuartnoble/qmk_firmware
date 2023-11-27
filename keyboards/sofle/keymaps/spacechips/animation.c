#include "animation.h" 
#include <stdio.h>
#include "print.h"

unsigned int state = 0;

// OLED_DISPLAY_HEIGHT = 32
// OLED_DISPLAY_WIDTH = 128
// OLED_MATRIX_SIZE = (OLED_DISPLAY_HEIGHT/8) * OLED_DISPLAY_WIDTH = 512

// Use our own variables for the rotated display specs

#ifndef ANIM_FRAME_TIME
  #define ANIM_FRAME_TIME 250
#endif

#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 32

#define IMAGE_HEIGHT 256
#define DISPLAY_BYTES_PER_LINE 4

#define OLED_PAGES 4


static void render_background(const char *background) {
    static uint32_t anim_timer = 0;
    static uint16_t offset = 0;

    if (timer_elapsed32(anim_timer) > ANIM_FRAME_TIME) {
        anim_timer = timer_read32();

        char display_frame[512];

        for (int i = 0; i <= DISPLAY_WIDTH - 1; i++ ) {
            uint16_t frame_start = offset + i;
            uint16_t frame_end = 

            display_frame[i] = pgm_read_byte(background + offset + i);
            
            display_frame[i + 128] = pgm_read_byte((background + offset + 256) + i);
            
            display_frame[i + 256] = pgm_read_byte((background + offset + 512) + i);
            
            display_frame[i + 384] = pgm_read_byte((background + offset + 768) + i);
        }

        oled_write_raw(display_frame, 512);
        offset = (offset + 1) % 256;
    }

    // static uint32_t anim_timer = 0;
    // static uint8_t offset = 0;
    // //static uint16_t frame_end = IMAGE_HEIGHT * DISPLAY_BYTES_PER_LINE;
    // static uint16_t display_height_bytes = DISPLAY_HEIGHT * DISPLAY_BYTES_PER_LINE;

    // if (timer_elapsed32(anim_timer) > ANIM_FRAME_TIME) {
    //     anim_timer = timer_read32();

    //     //uint16_t frame_start = frame_end - display_height_bytes;    

    //     char display_frame[display_height_bytes];

    //     for (int i = 0; i <= DISPLAY_HEIGHT - 1; i++ ) {
    //         //display_frame[i] = pgm_read_byte(background + (frame_start - offset) + i);
    //         display_frame[i] = pgm_read_byte(background + i);
            
    //         // if (i % DISPLAY_WIDTH > 0) {
    //         //     display_frame[i] <<= offset;
    //         // }

    //         // uprintf("%02X", display_frame[i]);
    //         // if (i > 0) print(":");
    //     }

    //     oled_write_raw(display_frame, display_height_bytes);
    //     offset = offset + 1;
    // }

    // static uint32_t anim_timer = 0;
    
    // static uint16_t viewport_end = 0;
    // static uint16_t viewport_start = 0;
    // static uint16_t oled_height_bytes = 0;
    // static uint16_t offset = 0;

    // if (timer_elapsed32(anim_timer) > ANIM_FRAME_TIME) {
    //     anim_timer = timer_read32();

    //     viewport_end = (background_height * 4);
    //     oled_height_bytes = oled_height * 4;
    //     viewport_start = viewport_end - oled_height_bytes;

        // oled_set_cursor(0,0);
        // oled_write_raw_P(background, 512);

    //     offset = offset - 1;
    // }

    // oled_set_cursor(0,0);
    // oled_write_raw_P(background >> 2, 512);
}

static void render_space(void) {
    //, 256, 128
    render_background(space_bitmap);

    //char wpm = get_current_wpm();
    //char render_row[512];
    // int i;

    //oled_set_cursor(0,0);
    // for (int i = 0; i < (32 * 128 / 8); i++) {
    //     render_row[i] = pgm_read_byte(space_bitmap + i);
    // }

    // oled_write_raw(render_row, 512);


    //oled_write_raw_P(space_bitmap + 512, 512); // 512 of 1024 max, second 512 needs to adjust if we hit the bottom of the screen

    // if current line > oled height, user space_bitmap + (index - 512)
    
    //render_row[0] = pgm_read_byte(space_bitmap

    // for(i=0; i<wpm/4; i++) {
    //     render_row[i] = pgm_read_byte(space_row_1+i+state);
    // };
    // for(i=wpm/4; i<128; i++) {
    //     render_row[i] = (pgm_read_byte(space_row_1+i+state)&pgm_read_byte(mask_row_1+i-wpm/4)) | pgm_read_byte(ship_row_1+i-wpm/4);
    // };

    // oled_write_raw(render_row, 128);
    // // oled_write_raw_P(space_row_1, 128);
    // oled_set_cursor(0,1);
    // for(i=0; i<wpm/4; i++) {
    //     render_row[i] = pgm_read_byte(space_row_2+i+state);
    // };
    // for(i=wpm/4; i<128; i++) {
    //     render_row[i] = (pgm_read_byte(space_row_2+i+state)&pgm_read_byte(mask_row_2+i-wpm/4)) | pgm_read_byte(ship_row_2+i-wpm/4);
    // };
    // oled_write_raw(render_row, 128);
    // oled_set_cursor(0,2);
    // for(i=0; i<wpm/4; i++) {
    //     render_row[i] = pgm_read_byte(space_row_3+i+state);
    // };
    // for(i=wpm/4; i<128; i++) {
    //     render_row[i] = (pgm_read_byte(space_row_3+i+state)&pgm_read_byte(mask_row_3+i-wpm/4)) | pgm_read_byte(ship_row_3+i-wpm/4);
    // };

    // oled_write_raw(render_row, 128);
    // oled_set_cursor(0,3);
    // for(i=0; i<wpm/4; i++) {
    //     render_row[i] = pgm_read_byte(space_row_4+i+state);
    // };
    // for(i=wpm/4; i<128; i++) {
    //     render_row[i] = (pgm_read_byte(space_row_4+i+state)&pgm_read_byte(mask_row_4+i-wpm/4)) | pgm_read_byte(ship_row_4+i-wpm/4);
    // };

    // oled_write_raw(render_row, 128);

    // state = (state + 1 + (wpm/15)) % (128*2);
}