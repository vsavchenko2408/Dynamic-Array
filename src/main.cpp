#include <iostream>
#include "../include/vector.h"

int main()
{
    Vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.at(2) = 5;
    for(size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;



}