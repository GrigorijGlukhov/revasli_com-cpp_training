#include <iostream> 
#include <string>

int main(){
    std::string name;
    std::cout << "Enter your name: ";
    //std::cin >> name;
    name = "Alex";
    std::string surName;
    surName = "Brox";
    int age = 37;
    std::string fullName = name + " " + surName;
    
    //std::getline(std::cin, name); // getline can take whole string line with spaces!
    std::cout << "\nLength of line is " << fullName.length() << std::endl;
    //std::cin.ignore(32767, '\n');
    
    std::cout << "\nYour name is " << fullName;
    std::cout << "\nYour age is " << age << " and you live " << double(age)/fullName.length() << " year for letter";
    return 0;
}