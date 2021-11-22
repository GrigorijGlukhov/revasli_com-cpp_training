#include <iostream>
 
class Dollars
{
private:
    int m_dollars;
 
public:
    Dollars(int dollars) { m_dollars = dollars; }
 
    // Выполняем Dollars + int
    Dollars operator+(int value);
 
    int getDollars() { return m_dollars; }
};
 
// Примечание: Эта функция является методом класса!
// Вместо параметра dollars в перегрузке через дружественную функцию здесь неявный параметр, на который указывает указатель *this
Dollars Dollars::operator+(int value)
{
    return Dollars(m_dollars + value);
}
 
int main()
{
	Dollars dollars1(7);
	Dollars dollars2 = dollars1 + 3;
	std::cout << "I have " << dollars2.getDollars() << " dollars.\n";
 
	return 0;
}
