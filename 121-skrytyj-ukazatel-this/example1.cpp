//using chais with this
#include <iostream> 

class Mathem {
    int m_value;
public:
    Mathem() { m_value = 0; }
    
    Mathem& add(int value) { m_value += value; return *this; }
    Mathem& sub(int value) { m_value -= value; return *this; }
    Mathem& mul(int value) { m_value *= value; return *this; }
    
    int getValue() { return m_value; }
};

int main(){
    Mathem operation;
    operation.add(7).sub(5).mul(5);
    
    std::cout << operation.getValue() << '\n';
    return 0;
}