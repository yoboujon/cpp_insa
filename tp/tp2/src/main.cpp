#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <set>
#include <sys/types.h>
#include <vector>
#include <list>
#include <map>
#include "../include/partie2.h"

void question1(const uint maxVec);
void question2(const uint max);
void question3();
void question4();
void question5();
void question6();

int main(void)
{
    question1(10);
    question2(10);
    question3();
    question4();
    question5();
    question6();

    // Partie2
    MatriceCreuse m(5,5,{{0,2},{0,1}},2);
    std::cout << m;
    std::cout << m(0,2) << std::endl;
    std::cout << m[{0,5}] << std::endl;
    m(0,0) = 5;
    std::cout << m << std::endl;
    auto m2 = m+5;
    std::cout << m2 << std::endl;
    std::cout << m+m2 << std::endl;
    std::cout << m2-m << std::endl;
    MatriceCreuse m3(3,4,{{2,2}},5);
    try {
        std::cout << m+m3;
    }
    catch(const char* err)
    {
        std::cerr << err << std::endl;
    }
    std::cout << m << std::endl;
    m+=1;
    std::cout << m;
    return 0;
}

void question6()
{
    std::list<std::string> phrase = {"il","fait","beau"};
    auto it = std::find(phrase.begin(),phrase.end(),"beau");
    phrase.emplace(it, "très");
    for(const auto& mot : phrase)
        std::cout << mot << " ";
    std::cout << "\n";
}

void question5()
{
    std::vector<std::string> dico = {"Orange", "Girafe", "Piano", "Lion", "Ballon"};
    for(const auto& mot : dico)
        std::cout << mot << "\t";
    std::cout << "\n";
    // tri
    std::sort(dico.begin(),dico.end());
    for(const auto& mot : dico)
        std::cout << mot << "\t";
    std::cout << "\n";
}

void question4()
{
    std::map<std::string,uint> contacts = {
        {"Boujon", 781930616},
        {"Soler", 593457861},
        {"Paris", 635861042},
        {"Muller", 512104809},
        {"Sanchez", 695614801},
        {"Dubois", 745102647},
        {"Dupont", 597153486}
    };
    for(const auto& c : contacts)
        std::cout << "Nom: " << c.first << "\tNuméro: " << c.second << "\n";
    for(auto it=contacts.begin() ; it != contacts.end();)
    {
        if (it->second >= 500000000 && it->second < 600000000)
            it = contacts.erase(it);
        else
            it++;
    }
    std::cout << "\nAprès\n";
    for(const auto& c : contacts)
        std::cout << "Nom: " << c.first << "\tNuméro: " << c.second << "\n";
}

void question3()
{
    std::set<std::string> eleves = {"Boujon","Soler","Dubois","Dupont","Paris","Muller","Sanchez"};
    for(const auto& nom : eleves)
        std::cout << nom << "\t";
    std::cout << std::endl;
    eleves.erase(eleves.begin(),std::next(eleves.begin(),2));
    for(const auto& nom : eleves)
        std::cout << nom << "\t";
    std::cout << std::endl;
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