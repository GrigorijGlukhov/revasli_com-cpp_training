#include <iostream>
#include <string>

class Anything {
    std::string m_value;
public:
    Anything( const std::string & value = "" ) : m_value(value) {}
    const std::string & getValue() const { return m_value; } // for const obj
    std::string & getValue() { return m_value; } // for non const obj
};


int main(){
    Anything anything;
    anything.getValue() = "Hello, "; // returns non const ref and assign string to it
    std::cout << anything.getValue();
    const Anything anything2("Mike");
    std::cout << anything2.getValue(); //cant assign anything because of const
    return 0;
}