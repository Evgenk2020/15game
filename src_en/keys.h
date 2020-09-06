#ifndef KEYS_H
#define KEYS_H

#include <memory>
#include <array>
#include <string>



//----------------------------------------------------------------------
//key base
class set_keys {
public:
    virtual std::string get_key_codes() const = 0;
    virtual ~set_keys() {}
};
//----------------------------------------------------------------------



class key_up : public set_keys {
public:
    std::string get_key_codes() const override;
    virtual ~key_up() {}
};



class key_down : public set_keys {
public:
    std::string get_key_codes() const override;
    virtual ~key_down() {}
};



class key_right : public set_keys {
public:
    std::string get_key_codes() const override;
    virtual ~key_right() {}
};



class key_left : public set_keys {
public:
    std::string get_key_codes() const override;
    virtual ~key_left() {}
};



class key_esc : public set_keys {
public:
    std::string get_key_codes() const override;
    virtual ~key_esc() {}
};



class key_f1 : public set_keys {
public:
    std::string get_key_codes() const override;
    virtual ~key_f1() {}
};



class key_error : public set_keys {
public:
    std::string get_key_codes() const override;
    virtual ~key_error() {}
};



//----------------------------------------------------------------------
//keymap factory
struct keymap {std::unique_ptr<set_keys> _direct_key;};

class keyboard {
private:
    const std::array<int, 4> upkey = {27, 91, 65, -1};
    const std::array<int, 4> downkey = {27, 91, 66, -1};
    const std::array<int, 4> rightkey = {27, 91, 67, -1};
    const std::array<int, 4> leftkey = {27, 91, 68, -1};
    const std::array<int, 4> esckey = {27, -1, -1, -1};
    const std::array<int, 4> f1key = {27, 79, 80, -1};
    const std::array<int, 4> errkey = {-1, -1, -1, -1};

public:
    keymap get_key_map(std::array<int, 4> temp);
    ~keyboard() {}
};

//----------------------------------------------------------------------

#endif // KEYS_H
