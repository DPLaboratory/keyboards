#include QMK_KEYBOARD_H
#include "features/mouse_turbo_click.h"
#include "features/helper.h"


enum custom_keycodes {
  MACRO_ONE = SAFE_RANGE,
  MACRO_TWO,
  MACRO_THREE,
  MACRO_FOR,
  NEW_SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┐
     * │ A │ B │
     * ├───┼───┤
     * │ D │ E │
     * └───┴───┘
     */
    [0] = LAYOUT_ortho_2x2(
        MACRO_ONE,    MACRO_TWO,
        MACRO_THREE,    MACRO_FOR
    )
};

static void render_DPLab_logo(void) {
    static const char PROGMEM DPLab_logo[] = {
        0x0A,
        0x20,0x20,0x20,0x20,0x20,0x20,0x20, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x0A,
        0x20,0x20,0x20,0x20,0x20,0x20,0x20, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0x0A,
        0x20,0x20,0x20,0x20,0x20,0x20,0x20, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0x00
    };

    oled_write_P(DPLab_logo, false);
}

#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        render_DPLab_logo();
        //oled_write_P(PSTR("Layer: "), false);
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  //if (!process_mouse_turbo_click(keycode, record, TURBO)) { return false; }


  switch (keycode) {
    case MACRO_ONE:
      process_mouse_turbo_click2(record);
      break;
    case MACRO_TWO:
      process_helper(record);
      break;

    case MACRO_THREE:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("Macro 3");
      } else {
        // when keycode QMKURL is released
      }
      break;
    case MACRO_FOR:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("Macro 4");
      } else {
        // when keycode QMKURL is released
      }
      break;

  }
  return true;
}
