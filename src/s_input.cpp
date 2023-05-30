#include "s_input.h"

//------------------------------------------------------------------------
// keypress
void single_input::set_keypress()
{
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void single_input::reset_keypress() { tcsetattr(STDIN_FILENO, TCSANOW, &oldt); }
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// unblock
unblock::unblock() { flags = fcntl(0, F_GETFL, 0); }
void unblock::set_unblock() { fcntl(0, F_SETFL, flags | O_NONBLOCK); }
void unblock::reset_unblock() { fcntl(0, F_SETFL, flags & ~O_NONBLOCK); }
//------------------------------------------------------------------------
