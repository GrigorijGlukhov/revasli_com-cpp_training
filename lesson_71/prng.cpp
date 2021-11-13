// simple pseudo random generator
#include <iostream> 

unsigned int PRNG() {
    static unsigned int seed = 4541; // starting seed
    // generate new from seed
    seed = (8253729 * seed + 2396403);
    
    return seed % 32768; // return seed inrange of 32768
}

int main(){
    
    for (int count = 0; count < 100; ++count) {
        std::cout << PRNG() << "\t"; // print prandom numbers
        
        if ((count+1) % 5 == 0) {
            std::cout << "\n";
        }
    }
    return 0;
}