#include <iostream>
#include "../include/vector.h"
#include "../include/array.h"
#include "../include/list.h"

#include <algorithm>

int main()
{

Vector<int> v;
v.push_back(3);
v.push_back(5);
v.push_back(2);
v.push_back(7);
v.push_back(6);

Vector<int> v1(v);

std::cout << "Without sort: " << std::endl;
for(size_t i = 0; i < v1.size(); ++i)
{
    std::cout << v1.at(i) << " ";
}
std::cout << std::endl;
std::sort(v1.begin(),v1.end());
std::cout << "After sort: " << std::endl;
for(size_t i = 0; i < v1.size(); ++i)
{
    std::cout << v1.at(i) << " ";
}
std::cout << std::endl;

std::cout << "Old vector: " << std::endl;
for(size_t i = 0; i < v.size(); ++i)
{
    std::cout << v.at(i) << " ";
}
std::cout << std::endl;

}