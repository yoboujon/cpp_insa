#include <iostream>

void maj1(int& j);
void maj2(int* j);

int main(void)
{
    int i(2);
    maj1(i);
    std::cout << i << std::endl;
    maj2(&i);
    std::cout << i <<std::endl;
    return 0;
}

void maj1(int& j)
{
    j *= 2;
}

void maj2(int* j)
{
    (*j) *= 2;
}