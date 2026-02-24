#ifndef ARRAY_H
#define ARRAY_H
#include <cstddef>
#include <stdexcept>
#include <utility>

template<typename T, size_t N>
class Array
{
    T arr[N];
    public:
    Array() = default;

    T& operator[](size_t index)
    {
        return arr[index];
    }
    const T& operator[](size_t index) const
    {
        return arr[index];
    }
    T& at(size_t index)
    {
        if(index >= N)
        {
            throw std::out_of_range("Array::at");
        }
            return arr[index];
    }
    const T& at(size_t index) const
    {
        if(index >= N)
        {
            throw std::out_of_range("Array::at");
        }
            return arr[index];
    }

    size_t size() const noexcept
    {
        return N;
    }
    bool empty() const noexcept
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

    T& front()
    {
        return arr[0];
    }
    const T& front() const
    {
        return arr[0];
    }

    T& back()
    {
        return arr[size()-1];
    }
    const T& back() const
    {
        return arr[size()-1];
    }

    T* data()
    {
        return arr;
    }

    const T* data() const
    {
        return arr;
    }
    void fill(const T& value)
    {
        for(size_t i = 0; i < N; i++)
        {
            arr[i] = value;
        }
    }
    void swap(Array& other) noexcept
    {
        for(size_t i = 0; i < N; i++)
        {
            std::swap(this->arr[i], other.arr[i]);
        }
    }
};

#endif