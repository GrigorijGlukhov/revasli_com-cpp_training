#include <iostream> 

int main(){
    const unsigned int redBits = 0xff000000;
    const unsigned int greenBits = 0x00ff0000;
    const unsigned int blueBits = 0x0000ff00;
    const unsigned int alphaBits = 0x000000ff;
    
    unsigned int pixel = 0xa125c2ff;
    
    unsigned char red = (pixel & redBits) >> 24;
    unsigned char green = (pixel & greenBits) >> 16;
    unsigned char blue = (pixel & blueBits) >> 8;
    unsigned char alpha =(pixel & alphaBits);
    
    std::cout << "Your color contains:\n";
    std::cout << static_cast<int>(red) << " of red\n";
    std::cout << static_cast<int>(green) << " of green\n";
    std::cout << static_cast<int>(blue) << " of blue\n";
    std::cout << static_cast<int>(alpha) << " of alpha\n";
    
    return 0;
}