#include "key_detect.h"

#include <memory>
#include <array>
#include "lib_input.h"
#include "keys.h"



//----------------------------------------------------------------------
//class key_enter
struct entering {std::array<int, 4> symbols;};

class key_enter {
private:
    entering _entering;
    symbol_input<int> _symbol_input;

public:
    void set_symbol();
    entering get_symbol();
    ~key_enter() {}
};
//----------------------------------------------------------------------



//----------------------------------------------------------------------
//class key_enter
void key_enter::set_symbol() {
    _entering.symbols = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        _symbol_input.take_symbol();
        _entering.symbols[i] = _symbol_input.get_symbol();

        if (i == 0)
            _symbol_input.set_unblock();
    }

    _symbol_input.reset_unblock();
}

entering key_enter::get_symbol() {return _entering;}
//----------------------------------------------------------------------



//----------------------------------------------------------------------
//class key_names
void key_names::set_key_name() {
    key_enter _key_enter;
    keyboard _keyboard;

    _key_enter.set_symbol();
    //k_names = _keyboard.get_key_map(_key_enter.get_symbol().symbols)._direct_key->get_key_codes().key_name;
    k_names = _keyboard.get_key_map(_key_enter.get_symbol().symbols)._direct_key->get_key_codes();
}

std::string key_names::get_key_mames() {return k_names;}
//----------------------------------------------------------------------
