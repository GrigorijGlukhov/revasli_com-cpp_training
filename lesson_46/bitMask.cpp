#include <iostream> 

int main(){
    const unsigned char isHungry = 0x01; //0000 0001
    const unsigned char isSad = 0x02; // 0000 0010
    const unsigned char isMad = 0x04; // 0000 0100
    const unsigned char isHappy = 0x08; // 0000 1000
    const unsigned char isLaughting = 0x10; // 0001 0000
    const unsigned char isAsleep = 0x20; // 0010 0000
    const unsigned char isDead = 0x40; // 0100 0000
    const unsigned char isCrying = 0x80; // 1000 0000
    
    unsigned char me = 0;
    me |= isHappy | isLaughting; // adds some options - some bits are on
    me &= ~isLaughting; // not laughting now
    
    std::cout << "Is i am happy? " << static_cast<bool>(me & isHappy) << "\n";
    std::cout << "Is a am laughting? " << static_cast<bool>(me & isLaughting) << "\n";
    
    return 0;
}