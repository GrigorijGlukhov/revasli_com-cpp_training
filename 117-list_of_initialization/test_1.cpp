// list of initialization
#include <iostream>
#include <string>
#include <cstdint>

class RGBA {
    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;
    public:
    RGBA ( std::uint8_t red = 0, 
           std::uint8_t green = 0, 
           std::uint8_t blue = 0, 
           std::uint8_t alpha = 255 ):
        m_red{red}, 
        m_green{green}, 
        m_blue{blue}, 
        m_alpha{alpha} {}
    void print() {
        std::cout << "R: " << static_cast<int>(m_red);
        std::cout << " G: " << static_cast<int>(m_green);
        std::cout << " B: " << static_cast<int>(m_blue);
        std::cout << " A: " << static_cast<int>(m_alpha);
    }
};

int main() {
    RGBA rgba(0, 124, 76, 255);
    rgba.print();

    EXIT_SUCCESS;
}