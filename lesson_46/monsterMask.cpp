#include <iostream> 

int main(){
    const unsigned char atackPoison = 0x01; //0000 0001
    const unsigned char atackLightning = 0x02; // 0000 0010
    const unsigned char atackFire = 0x04; // 0000 0100
    const unsigned char atackCold = 0x08; // 0000 1000
    const unsigned char atackTheft = 0x10; // 0001 0000
    const unsigned char atackAcid = 0x20; // 0010 0000
    const unsigned char atackParalysis = 0x40; // 0100 0000
    const unsigned char atackBlindness = 0x80; // 1000 0000
    
    const unsigned char resistPoison = 0x01; //0000 0001
    const unsigned char resistLightning = 0x02; // 0000 0010
    const unsigned char resistFire = 0x04; // 0000 0100
    const unsigned char resistCold = 0x08; // 0000 1000
    const unsigned char resistTheft = 0x10; // 0001 0000
    const unsigned char resistAcid = 0x20; // 0010 0000
    const unsigned char resistParalysis = 0x40; // 0100 0000
    const unsigned char resistBlindness = 0x80; // 1000 0000
    
    unsigned char hero = 0;
    unsigned char monster = 0;
    
    hero |= (atackFire | atackTheft);
    monster |= (resistFire | resistParalysis);
    
    std::cout << "Can Hero atack theft? " << static_cast<bool>(hero & atackTheft) << "\n";
    std::cout << "Can Monster resist cold? " << static_cast<bool>(monster & resistCold) << "\n";
    
    return 0;
}