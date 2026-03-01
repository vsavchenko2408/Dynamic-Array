#ifndef LIST_H
#define LIST_H
#include <cstddef>

template<typename T>
class List
{
    struct Node
    {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value, Node* p = nullptr, Node* n = nullptr): data(value), prev(p), next(n)
        {
            
        }
    };
    Node* _head;
    Node* _tail;
    size_t _size;
    public:

    List(): _head(nullptr), _tail(nullptr), _size(0)
    {}
    List(size_t size): _head(nullptr), _tail(nullptr), _size(size)
    {

    }
};

#endif