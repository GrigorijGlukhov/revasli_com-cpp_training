#include <iostream>
#include <string>
//enter number of names
int getValue() {
    int a;
    std::cin >> a;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32765, "\n");
    }
    else
        return a;
}
//get single name
std::string getName() {
    std::string name;
    std::cin >> name;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, "\n");
    }
    else
        return name;
}
// get all names
void getNames(std::string *names, const int *namesCount) {
    for (int name = 0; name < *namesCount; ++name,names++) {
        std::cout << "Enter name #" << name+1 << " ";
        *names = getName();
    }
}
//sort all names
void sortNames(std::string *names, const int *namesCount) {
    //std::cout << "Sorting: " << *names << " & " << *(names+1) << "\n";
    //if (*names > *(names+1)) {
        //std::cout << "swaped\n";
        //std::swap(*names, *(names+1));
    //}
    for(int name = 0; name < *namesCount; ++name) {
        for(int currentName = name+1; currentName < *namesCount; ++currentName) {
            if(*(names+name) > *(names+currentName))
                std::swap(*(names+name), *(names+currentName));
        }
    }
}


//print all names
void printNames(const std::string *names, const int *namesCount) {
    for (int name = 0; name < *namesCount; ++name)
        std::cout << name+1 << " - " << *(names+name) << "\n";
}

int main(){
    //ask for number of names
    std::cout << "Enter number of names: ";
    int namesNumber = getValue();
    //ask names
    std::string *names = new std::string[namesNumber]; // dregular array of strings
    
    getNames(&names, &namesNumber);
    
    sortNames(&names, &namesNumber);
    
    printNames(&names, &namesNumber);
    
    delete[] names;
    names = nullptr;
    return 0;
}