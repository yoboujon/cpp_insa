#include <cstddef>
#include <iostream>
#include <sys/types.h>
#include <vector>

void question1(uint maxVec);

int main(void)
{
    question1(10);
    return 0;
}

void question1(uint maxVec)
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