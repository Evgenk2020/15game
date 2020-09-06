#ifndef _INPUT_ONE_H
#define _INPUT_ONE_H

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

//------------------------------------------------------------------------
//
class single_input {
private:
    struct termios oldt, newt;

public:
    void set_keypress();
    void reset_keypress();
    ~single_input() {}
};
//------------------------------------------------------------------------



//------------------------------------------------------------------------
//
class unblock {
private:
    int flags;

public:
    unblock();
    void set_unblock();
    void reset_unblock();
    ~unblock() {}
};
//------------------------------------------------------------------------

#endif // _INPUT_ONE_H
