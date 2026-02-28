#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <stdexcept>

template<typename T>
class Vector
{
    T* _array;
    size_t _size;
    size_t _capacity;
    public:
////////////////////////////////////// deafult
    Vector() : _array(nullptr), _size(0) , _capacity(0)
    {

    }
////////////////////////////////////// param
    Vector( size_t size) : _size(size) , _capacity(size*2)
    {
        _array = new T[_capacity];
    }
////////////////////////////////////// copy constr
    Vector(const Vector& copy) : _array(nullptr), _size(copy._size), _capacity(copy._capacity)
    {
        if(copy._size > 0)
        {
            _array = new T[_capacity];
            for(size_t i = 0; i < _size; ++i)
            {
                _array[i] = copy._array[i];
            }
        }

    }
////////////////////////////////////// move constr
    Vector(Vector&& move) noexcept
    {
        _capacity = move._capacity;
        _size = move._size;
        _array = move._array;
        move._array = nullptr;
        move._capacity = 0;
        move._size = 0;
    }
////////////////////////////////////// move oper
    Vector& operator=(Vector&& move) noexcept
    {
        if(this != &move)
        {
            delete[] _array;
            _capacity = move._capacity;
            _size = move._size;
            _array = move._array;
            move._array = nullptr;
            move._capacity = 0;
            move._size = 0;
            return *this;
        }
        else
        {
            return *this;
        }
    }
////////////////////////////////////// copy oper
Vector& operator=(const Vector& copy) 
{
     if(_array != copy._array) 
     {
        _capacity = copy._capacity;
        _size = copy._size; 
        delete[] _array; 
        _array = new T[_capacity];
        for(size_t i = 0; i < _size; ++i) 
        { 
            _array[i] = copy._array[i];
        } 
        return *this; 
        } 
        return *this; 
}
////////////////////////////////////// const oper[]
    const T& operator[](size_t index) const
    {
        return _array[index];
    }
//////////////////////////////////////  oper[]
     T& operator[](size_t index) 
    {
        return _array[index];
    }
////////////////////////////////////// at()
    T& at(size_t index) 
    {
        if(index >= _size)
        {
            throw std::out_of_range("Vector::at");
        }
        return _array[index];
    }
////////////////////////////////////// const at()
    const T& at(size_t index) const
    {
        if(index >= _size)
        {
            throw std::out_of_range("Vector::at");
        }
        return _array[index];
    }
////////////////////////////////////// push_back()
void push_back(const T& obj)
{
    if (_size == _capacity)
    {
        size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;

        T* temp = new T[new_capacity];
        for (size_t i = 0; i < _size; ++i)
            temp[i] = _array[i];

        delete[] _array;
        _array = temp;
        _capacity = new_capacity;
    }

    _array[_size] = obj;
    ++_size;
}
//////////////////////////////////////reserve()
void reserve(size_t new_capacity)
 {
     if(new_capacity > _capacity)
      {
        _capacity = new_capacity;
        T* temp = new T[_capacity];
        for(size_t i = 0; i < _size;++i) 
        {
            temp[i] = _array[i]; 
        }
        delete[] _array; 
        _array = temp; 
} 
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
//////////////////////////////////////begin()
int* begin() 
{
    return _array;
}
//////////////////////////////////////end()
int* end() 
{
    return _array + _size;
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
        _capacity = 0;
    }
////////////////////////////////////// destr
    ~Vector()
    {
        delete[] _array;
    }
//////////////////////////////////////
};

#endif