#include <iostream> 

class Numbers {
    public:
    int m_a;
    int m_b;
    
    void print() {
        std::cout << "a: " << m_a << " b: " << m_b << "\n";
    }
    
     void set(int a, int b) {
         m_a = a;
         m_b = b;
     }
};

int main(){
    Numbers n1;
    n1.set(3, 4);
    n1.print();
    
    Numbers n2;
    n2.set(4, 4);
    n2.print();
    
    return 0;
}