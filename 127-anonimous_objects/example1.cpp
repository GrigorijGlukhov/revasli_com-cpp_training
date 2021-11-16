//  Anonimous object
#include <iostream>
#include <string>

class Dollars
{
    int m_dollars;
public:
    Dollars(int dollars) : m_dollars(dollars) {}
    int getDollars() const // using const method, because we send Dollars as const ref
    {
        return m_dollars;
    }
};

Dollars add(const Dollars & d1, const Dollars & d2) // converts Dollars obj to const obj, so we need const method
{
    return Dollars (d1.getDollars() + d2.getDollars());//return anonimous object Dollar
}

int main()
{
    Dollars d1(7);
    std::cout << "Dollars: " << d1.getDollars() << "\n";
    Dollars d2(17);
    std::cout << "Dollars: " << d2.getDollars() << "\n";
    std::cout << "Sum is: " << add(d1, d2).getDollars() << "\n"; // return anon obj and usig getDollar() method with it
    // or we can do this:
    std::cout << add(Dollars(30), Dollars(20)).getDollars() << "\n"; // without Dollars obj creation

    
    return 0;
}
