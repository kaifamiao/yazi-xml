#pragma once

#include <string>
#include <map>
#include <vector>
using namespace std;

namespace yazi {
namespace xml {

class Value
{
public:
    Value();
    Value(bool value);
    Value(int value);
    Value(double value);
    Value(const char * value);
    Value(const string & value);
    ~Value();

    Value & operator = (bool value);
    Value & operator = (int value);
    Value & operator = (double value);
    Value & operator = (const char * value);
    Value & operator = (const string & value);
    Value & operator = (const Value & value);

    bool operator == (const Value & other);
    bool operator != (const Value & other);
    
    operator bool();
    operator int();
    operator double();
    operator string();

private:
    string m_value;
};

class Xml
{
public:
    Xml();
    Xml(const char * name);
    Xml(const string & name);
    Xml(const Xml & other);

    string name() const;
    void name(const string & name);

    string text() const;
    void text(const string & text);

    Value & attr(const string & key);
    void attr(const string & key, const Value & value);

    Xml & operator = (const Xml & other);

    void append(const Xml & child);
    Xml & operator [] (int index);

    typedef std::vector<Xml> Child;
    Child operator [] (const char * name)
    {
        return (*this)[string(name)];
    }

    Child operator [] (const string & name)
    {
        std::vector<Xml> child;
        for (auto it = m_child->begin(); it != m_child->end(); it++)
        {
            if (it->name() == name)
            {
                child.push_back(*it);
            }
        }
        return child;
    }

    void remove(int index);
    void remove(const char * name);
    void remove(const string & name);

    int size() const;

    void clear();

    string str() const;

    typedef std::vector<Xml>::iterator iterator;
    iterator begin()
    {
        return m_child->begin();
    }
    iterator end()
    {
        return m_child->end();
    }
    iterator erase(iterator it)
    {
        it->clear();
        return m_child->erase(it);
    }

    bool load(const string & filename);
    bool save(const string & filename);
    bool parse(const string & str);

private:
    string * m_name;
    string * m_text;
    std::map<string, Value> * m_attrs;
    std::vector<Xml> * m_child;
};
}
}