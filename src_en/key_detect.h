#ifndef KEY_DETECT_H
#define KEY_DETECT_H

#include <string>

//*************************************************************
class key_names {
private:
    std::string k_names;

public:
    void set_key_name();
    std::string get_key_mames();
    ~key_names() {}
};

#endif // KEY_DETECT_H
//*************************************************************
