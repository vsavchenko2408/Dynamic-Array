#include <iostream>
#include "../include/array.h"

int main()
{
    Array<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.at(3) = 5;
    for(size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;



}