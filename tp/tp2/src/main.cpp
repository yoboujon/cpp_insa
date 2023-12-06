#include <cstddef>
#include <iostream>
#include <iterator>
#include <sys/types.h>
#include <vector>
#include <list>

void question1(const uint maxVec);
void question2(const uint max);

int main(void)
{
    question1(10);
    question2(10);
    return 0;
}

void question2(const uint max)
{
    std::list<char> l1;
    for(uint i=0; i<max; i++)
        l1.push_back('a'+i);
    auto l2 = l1;
    l2.erase(l2.begin(),std::next(l2.begin(), 5));

    // printing
    for(const auto& val : l1)
        std::cout << val << "\t";
    std::cout << std::endl;    
    for(const auto& val : l2)
        std::cout << val << "\t";
    std::cout << std::endl; 
}

void question1(const uint maxVec)
{
    std::vector<float> v1;
    const float value = 1.0f/maxVec;
    for(uint i=0; i<maxVec; i++)
        v1.push_back(value*i);
    auto v2 = v1;
    for(size_t i=0; i<(maxVec/2); i++)
        v2.pop_back();

    // printing
    for(const auto& val : v1)
        std::cout << val << "\t";
    std::cout << std::endl;    
    for(const auto& val : v2)
        std::cout << val << "\t";
    std::cout << std::endl;  
}