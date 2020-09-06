#ifndef S_INPUT_H
#define S_INPUT_H

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>



class single_input {
private:
    struct termios oldt, newt;

public:
    void set_keypress();
    void reset_keypress();
    ~single_input() {}
};



class unblock {
private:
    int flags;

public:
    unblock();
    void set_unblock();
    void reset_unblock();
    ~unblock() {}
};



//-----------------------------------------------------
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
//-----------------------------------------------------

#endif // S_INPUT_H
