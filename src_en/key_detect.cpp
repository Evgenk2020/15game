#include "key_detect.h"

//----------------------------------------------------------------------
//class key_enter
void key_enter::put_symbol() {
    for (int i = 0; i < 4; i++) {
        symbols[i] = 0;
    }

    _symbol_input.take_symbol();

    bool esc_symbol_is_detected = (_symbol_input.get_symbol() == ESCAPE_POD);

    if (esc_symbol_is_detected) {
        symbols[MIN_KEY] = _symbol_input.get_symbol();
        _symbol_input.set_unblock();

        for (int j = START_POD; j < MAX_KEY; j++) {
            _symbol_input.take_symbol();
            symbols[j] = _symbol_input.get_symbol();
        }

        _symbol_input.reset_unblock();
    }
}

int* key_enter::get_symbol() {return symbols;}
//----------------------------------------------------------------------



//----------------------------------------------------------------------
//class key_codes_check
void key_codes_check::codes_check(int temp) {
    bool current_code_is_correct;
    btn_number = 0;

    for (int i = MIN_KEY; i < MAX_KEY; i++) {
        current_code_is_correct = (get_key_map()._direct_key[temp]->get_key_codes().codes[i] == get_symbol()[i]);

        if (current_code_is_correct)
            ++btn_number;
    }
}

int key_codes_check::get_codes_check() {return btn_number;}
//----------------------------------------------------------------------



//----------------------------------------------------------------------
//class key_detect
void key_detect::key_detection() {
    bool another_key_is_pressed;
    bool all_cods_are_checked;

    for (int i = 0; i < FUNC_KEYS; i ++) {
        codes_check(i);
        all_cods_are_checked = (get_codes_check() == MAX_KEY);

        if (all_cods_are_checked) {
            key_detected = get_key_map()._direct_key[i]->get_key_codes().key_name;
            break;
        }

        another_key_is_pressed = ((i == (FUNC_KEYS - 1)) && (get_codes_check() != MAX_KEY));

        if (another_key_is_pressed)
            key_detected = "no button found...";
    }
}

std::string key_detect::get_key_name() {return key_detected;}
//----------------------------------------------------------------------
