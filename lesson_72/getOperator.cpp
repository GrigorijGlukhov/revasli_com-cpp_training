// secure input function
#include <iostream>
#include <stdio>

double GetValue() {
    std::cout << "Enter a double value: ";
    double a;
    std::cin >> a;
    if (std::cin.fail()) { // check for wrong type
        std::cin.clear(); // clear input in cin
        std::cin.ignore(32767, '\n'); // delete rest of symbols
    }
    else
        return a;
}

char GetOperator() {
    while(true) {
        std::cout << "Enter one of the following operators: +, -, *, /: ";
        char sm;
        std::cin >> sm;
         std::cin.ignore(32767, '\n');
        // check enter for correct symbol
        if (sm == '+' || sm == '-' || sm == '*' || sm == '/') 
            return sm;
        else
            std::cout << "Ops, that input is invalid! Try again. \n";
    }
}

int main(){
    std::cout << "Enter two double digits and operator.\n";
    double a = GetValue();
    double b = GetValue();
    char op = GetOperator();
    
    double result;
     if (op == '+') result = a + b;
     else if (op == '-') result = a - b;
     else if (op == '*') result = a * b;
     else if (op == '/') result = a / b;
    
    printf("%d %c %d = %d", a, op, b, result);
    return 0;
}