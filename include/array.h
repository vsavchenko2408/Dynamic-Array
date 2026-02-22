#ifndef ARRAY_H
#define ARRAY_H
#include <cstddef>
#include <stdexcept>
template<typename T, size_t N>
class Array
{
    T arr[N];
    public:
    Array() = default;

    Array(size_t size)
    {
        T arr[size];
    }
    T& operator[](size_t index)
    {
        return arr[index];
    }

    T& at(size_t index)
    {
        if(index <= N)
        {
            return arr[index];
        }
        else
        {
            throw std::out_of_range("Array::at");
        }
    }

    size_t size()
    {
        return N;
    }
    bool is_empty()
    {
        if(N ==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif