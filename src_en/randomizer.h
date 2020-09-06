#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>



//-------------------------------------------------------------------------
template <typename T>
class randomizer {
private:
    T begin, end;

public:
    void set_begin(T temp);
    void set_end(T temp);
    T get_randome_element();
};

template <typename T>
void randomizer<T>::set_begin(T temp) {begin = temp;}

template <typename T>
void randomizer<T>::set_end(T temp) {end = temp;}

template <typename T>
T randomizer<T>::get_randome_element() {
    std::random_device r_device;
    std::mt19937 my_dev(r_device());
    std::uniform_int_distribution<T> distrib(begin, end);
    T number = distrib(my_dev);

    return number;
}
//-------------------------------------------------------------------------

#endif // RANDOMIZER_H
