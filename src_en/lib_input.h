#ifndef S_INPUT_H
#define S_INPUT_H

#include "_input_one.h"

//****************************************************************
template <typename T>
class symbol_input : private single_input, public unblock {
private:
    T symbol;

public:
    void take_symbol();
    T get_symbol();
    ~symbol_input() {}
};



template <typename T>
void symbol_input<T>::take_symbol() {
    set_keypress();
    symbol = getchar();
    reset_keypress();
}



template <typename T>
T symbol_input<T>::get_symbol() {return symbol;}
//****************************************************************

#endif // S_INPUT_H
