#include "keys.h"

//------------------------------------------------------------------------------
//class key_up
key_up::key_up() {
    _key_codes.codes = {27, 91, 65, -1};
    _key_codes.key_name = "key_up";
}

key_codes key_up::get_key_codes() const {return _key_codes;}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//class key_down
key_down::key_down() {
    _key_codes.codes = {27, 91, 66, -1};
    _key_codes.key_name = "key_down";
}

key_codes key_down::get_key_codes() const {return _key_codes;}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//class key_right
key_right::key_right() {
    _key_codes.codes = {27, 91, 67, -1};
    _key_codes.key_name = "key_right";
}

key_codes key_right::get_key_codes() const {return _key_codes;}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//class key_left
key_left::key_left() {
    _key_codes.codes = {27, 91, 68, -1};
    _key_codes.key_name = "key_left";
}

key_codes key_left::get_key_codes() const {return _key_codes;}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//class key_esc
key_esc::key_esc() {
    _key_codes.codes = {27, -1, -1, -1};
    _key_codes.key_name = "key_esc";
}

key_codes key_esc::get_key_codes() const {return _key_codes;}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//class key_f1
key_f1::key_f1() {
    _key_codes.codes = {27, 79, 80, -1};
    _key_codes.key_name = "key_f1";
}

key_codes key_f1::get_key_codes() const {return _key_codes;}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//keymap factory
//class keyboard
keymap keyboard::get_key_map() {
    keymap all_key;
    all_key._direct_key[up] = std::make_unique<key_up>();
    all_key._direct_key[down] = std::make_unique<key_down>();
    all_key._direct_key[right] = std::make_unique<key_right>();
    all_key._direct_key[left] = std::make_unique<key_left>();
    all_key._direct_key[esc] = std::make_unique<key_esc>();
    all_key._direct_key[kF1] = std::make_unique<key_f1>();

    return all_key;
}
//------------------------------------------------------------------------------
