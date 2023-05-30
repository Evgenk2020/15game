#ifndef MOVE_H
#define MOVE_H

#include <memory>
// fedora----------------------------------
#include <string>
// fedora----------------------------------

struct shtick
{
    int sh_vert, sh_hori;
};

class motion
{
protected:
    shtick t_shtick;

public:
    virtual shtick moove() = 0;
    virtual ~motion() {}
};

class move_up : public motion
{
public:
    virtual shtick moove() override;
    virtual ~move_up() {}
};

class move_down : public motion
{
public:
    virtual shtick moove() override;
    virtual ~move_down() {}
};

class move_left : public motion
{
public:
    virtual shtick moove() override;
    virtual ~move_left() {}
};

class move_right : public motion
{
public:
    virtual shtick moove() override;
    virtual ~move_right() {}
};

class mistake : public motion
{
public:
    virtual shtick moove() override;
    virtual ~mistake() {}
};

class movment
{
public:
    static std::unique_ptr<motion> e_motion(std::string temp);
    ~movment() {}
};

#endif // MOVE_H
