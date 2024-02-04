#include <iostream>
#include "StringClass.hpp"

int main(){
    String s1 = "Hussein";
    String s2 = "Mohamed";
    s1 = s2;
    std::cout << s1.printString() << std::endl;
    return 0;
}