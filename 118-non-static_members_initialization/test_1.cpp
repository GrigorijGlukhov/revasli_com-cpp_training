#include <iostream>
#include <string>

class Thing {
    std::string m_color = "blue";
    double radius = 20.0;
    public:
    Thing() {};
    Thing( const std::string & color ) : m_color{color} {}
    Thing( double radius ) : m_radius{radius} {};
    Thing( const std::string & color, double radius ) : m_color{color}, m_radius{radius} {}
    void print() {
        std::cout << "color: " << m_color << " radius: " << m_radius << '\n';
    }

};


int main() {
    Thing defl;
    defl.print();

    Thing red("red");
    red.print();

    Thing thirty(30.0);
    thirty.print();

    Thing redThirty("red", 30.0);
    redThirty.print();

    return EXIT_SUCCESS;
}
