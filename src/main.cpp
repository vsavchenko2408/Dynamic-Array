#include <iostream>
#include "../include/vector.h"
#include "../include/array.h"
int main()
{

Array<int, 5> arr;
for(size_t i = 0; i < arr.size(); i++)
{
    arr[i] = i+1;
}
for(size_t j = 0; j < arr.size(); j++)
{
    std::cout << arr[j] << " "; 
}
std::cout << std::endl;


}