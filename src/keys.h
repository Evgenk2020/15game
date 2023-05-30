#ifndef KEYS_H
#define KEYS_H

#include <memory>
#include <array>
#include <string>

//----------------------------------------------------------------------
// key base
class set_keys
{
public:
    virtual std::string get_key_codes() const = 0;
    virtual ~set_keys() {}
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// keymap factory
struct keymap
{
    std::unique_ptr<set_keys> _direct_key;
};

class keyboard
{
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
