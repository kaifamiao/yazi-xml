#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include <xml/Xml.h>
using namespace yazi::xml;

int main()
{
    Xml root;
    root.load("./test.xml");

    const string & name = root["student"]["name"].text();
    std::cout << "name=" << name << std::endl;

    int id = root["student"].attr("id");
    std::cout << "id=" << id << std::endl;

    const string & age = root["student"]["age"].text();
    std::cout << "age=" << age << std::endl;

    for (Xml::iterator it = root.begin(); it != root.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}