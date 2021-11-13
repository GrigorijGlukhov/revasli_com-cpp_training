#include <iostream>
#include <string>

class Ball {
   char *m_color = "Red";
   double m_radius = 20.0;
   public:
   
	Ball ( double radius ) { m_radius = radius; }
	Ball ( char * color = "Red", double radius = 20.0 ) { m_color = color; m_radius = radius; }
	Ball () {  }
    
   void printBall() { std::cout << "This ball is color " << m_color << " and radius " << m_radius << "\n"; };
};


int main(){
    Ball def("Green");
    def.printBall();
	
	Ball x("Blue", 30.0);
	x.printBall();
    
    return 0;
}