#ifndef KEYS_H
#define KEYS_H

#include <memory>
#include <array>
#include "defines.h"



//----------------------------------------------------------------------
//key base
struct key_codes {
    std::array<int, MAX_KEY> codes;
    std::string key_name;
};

class set_keys {
protected:
    key_codes _key_codes;

public:
    virtual key_codes get_key_codes() const = 0;
    virtual ~set_keys() {}
};
//----------------------------------------------------------------------



class key_up : public set_keys {
public:
    key_up();
    key_codes get_key_codes() const override;
    virtual ~key_up() {}
};



class key_down : public set_keys {
public:
    key_down();
    key_codes get_key_codes() const override;
    virtual ~key_down() {}
};



class key_right : public set_keys {
public:
    key_right();
    key_codes get_key_codes() const override;
    virtual ~key_right() {}
};



class key_left : public set_keys {
public:
    key_left();
    key_codes get_key_codes() const override;
    virtual ~key_left() {}
};



class key_esc : public set_keys {
public:
    key_esc();
    key_codes get_key_codes() const override;
    virtual ~key_esc() {}
};



class key_f1 : public set_keys {
public:
    key_f1();
    key_codes get_key_codes() const override;
    virtual ~key_f1() {}
};



//----------------------------------------------------------------------
//keymap factory
struct keymap {
    std::unique_ptr<set_keys> _direct_key[FUNC_KEYS];
};

enum push_key{
    up,
    down,
    right,
    left,
    esc,
    kF1
};

class keyboard {
public:
    keymap get_key_map();
    ~keyboard() {}
};
//----------------------------------------------------------------------

#endif // KEYS_H
