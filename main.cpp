#include <iostream>
#include <fstream>
#include <sstream>
#include "Xml.h"
using namespace yazi::xml;

#include <sys/time.h>

int main()
{
    Xml root;
    root.load("./test.xml");
    std::cout << root.str() << std::endl;
    root.clear();
    return 0;
}