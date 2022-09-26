#include <iostream>
#include "Xml.h"
using namespace yazi::xml;

int main()
{
    Xml root;
    root.load("./test.xml");
    std::cout << root.str() << std::endl;
    root.clear();
    return 0;
}