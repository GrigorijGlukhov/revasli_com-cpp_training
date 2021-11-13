#include <iostream> 
#include <string>

class Anything {
    static int s_idGenerator;
    int m_Id;
public:
    Anything() { m_Id = s_idGenerator++; }
    int getId() { return m_Id; }
};

int Anything::s_idGenerator = 1;

int main(){
    Anything first;
    Anything second;
    Anything third;
    
    std::cout << first.getId() << '\n';
    std::cout << second.getId() << '\n';
    std::cout << third.getId() << '\n';
    
    return 0;
}