#ifndef KEY_DETECT_H
#define KEY_DETECT_H

#include <memory>
#include <array>
#include "s_input.h"
#include "keys.h"



class key_enter : public keyboard {
private:
    symbol_input<int> _symbol_input;

protected:
    int symbols[MAX_KEY];

public:
    void put_symbol();
    int* get_symbol();
    virtual ~key_enter() {}
};



class key_codes_check : public key_enter {
private:
    int btn_number;

public:
    void codes_check(int temp);
    int get_codes_check();
    virtual ~key_codes_check() {}
};



//*********************************************************
class key_detect : public key_codes_check {
private:
    std::string key_detected;

public:
    void key_detection();
    std::string get_key_name();
    virtual ~key_detect() {}
};
//*********************************************************

#endif // KEY_DETECT_H
