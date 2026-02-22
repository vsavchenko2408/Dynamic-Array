#ifndef ARRAY_H
#define ARRAY_H
#include <cstddef>
#include <stdexcept>
template<typename T>
class Array
{
    T* _array;
    size_t _size;
    public:
////////////////////////////////////// deafult
    Array() : _array(nullptr), _size(0)
    {

    }
////////////////////////////////////// param
    Array( size_t size) : _size(size)
    {
        _array = new T[_size];
    }
////////////////////////////////////// copy 
    Array(const Array& copy)
    {
        if(copy._size > 0)
        {
            _size = copy._size;
            _array = new T[_size];
            for(size_t i = 0; i < _size; ++i)
            {
                _array[i] = copy._array[i];
            }
        }
        else
        {
            _size = 0;
            _array = nullptr;
        }
    }
////////////////////////////////////// move constr
    Array(Array&& move) noexcept
    {
        _size = move._size;
        _array = move._array;
        move._array = nullptr;
        move._size = 0;
    }
////////////////////////////////////// move oper
    Array& operator=(Array&& move) noexcept
    {
        if(this != &move)
        {
            delete[] _array;
            _size = move._size;
            _array = move._array;
            move._array = nullptr;
            move._size = 0;
            return *this;
        }
        else
        {
            return *this;
        }
    }
////////////////////////////////////// copy oper
    Array& operator=(const Array& copy)
    {
        if(this == &copy) return *this;
        delete[] _array;
        if(copy._size > 0)
        {
            this->_size = copy._size;
            this->_array = new T[_size];
            for(size_t i = 0; i < _size; ++i)
            {
                this->_array[i] = copy._array[i];
            }
        }
        else
        {
            this->_size = 0;
            this->_array = nullptr;
        }
        return *this;
    }
////////////////////////////////////// oper[]
    const T& operator[](size_t index) const
    {
        return _array[index];
    }
////////////////////////////////////// at()
    T& at(size_t index) const
    {
        if(index >= _size)
        {
            throw std::out_of_range("Array::at");
        }
        return _array[index];
    }
////////////////////////////////////// push_back()
    void push_back(const T& obj)
    {
        T* temp = new T[_size+1];
        for(size_t i = 0; i < _size; ++i)
        {
            temp[i] = _array[i];
        }
        temp[_size] = obj;
        delete[] _array;
        _array = temp;
        ++_size;
    }
////////////////////////////////////// size()
    size_t size()const
    {
        return _size;
    }
////////////////////////////////////// front()
    T& front()
    {
        return _array[0];
    }
////////////////////////////////////// back()
    T& back()
    {
        return _array[_size - 1];
    }
////////////////////////////////////// is_empty()
    bool is_empty() const
    {
        if(_size >= 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
////////////////////////////////////// clear
    void clear()
    {
        delete[] _array;
        _array = nullptr;
        _size = 0;
    }
////////////////////////////////////// destr
    ~Array()
    {
        delete[] _array;
    }
//////////////////////////////////////
};

#endif