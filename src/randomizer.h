#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>

//-------------------------------------------------------------------------
template <typename T>
class randomizer
{
private:
    T begin, end;

public:
    void set_rnd(T begin, T end);
    T get_randome_element();
    ~randomizer() {}
};
//

//
template <typename T>
void randomizer<T>::set_rnd(T tmp_begin, T tmp_end)
{
    begin = tmp_begin;
    end = tmp_end;
}
//

//
template <typename T>
T randomizer<T>::get_randome_element()
{
    std::random_device r_device;
    std::mt19937 my_dev(r_device());
    std::uniform_int_distribution<T> distrib(begin, end);
    T number = distrib(my_dev);

    return number;
}
//-------------------------------------------------------------------------

#endif // RANDOMIZER_H
