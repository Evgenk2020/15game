#include "move.h"

//-----------------------------------------------------------------
// class move_up
shtick move_up::moove()
{
    t_shtick.sh_vert = -1;
    t_shtick.sh_hori = 0;

    return t_shtick;
}
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// class move_down
shtick move_down::moove()
{
    t_shtick.sh_vert = 1;
    t_shtick.sh_hori = 0;

    return t_shtick;
}
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// class move_left
shtick move_left::moove()
{
    t_shtick.sh_vert = 0;
    t_shtick.sh_hori = -1;

    return t_shtick;
}
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// class move_right
shtick move_right::moove()
{
    t_shtick.sh_vert = 0;
    t_shtick.sh_hori = 1;

    return t_shtick;
}
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// class mistake
shtick mistake::moove()
{
    t_shtick.sh_vert = -1;
    t_shtick.sh_hori = -1;

    return t_shtick;
}
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// class movment
std::unique_ptr<motion> movment::e_motion(std::string temp)
{
    if (temp == "key_up")
        return std::make_unique<move_up>();

    if (temp == "key_down")
        return std::make_unique<move_down>();

    if (temp == "key_right")
        return std::make_unique<move_right>();

    if (temp == "key_left")
        return std::make_unique<move_left>();

    else
        return std::make_unique<mistake>();
}
//-----------------------------------------------------------------
