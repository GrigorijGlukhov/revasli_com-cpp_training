// order of exacution of ctors and dtors
#include <iostream>
#include <string>

class Another
{
    int m_nID;
public:
    Another(int nID)
    {
        std::cout << "Cting Another" << nID << '\n';
        m_nID = nID;
    }
    ~Another()
    {
        std::cout << "Dting Another" << m_nID << '\n';
    }
    int getID() { return m_nID; }
};

int main()
{
    Another object(1); // creating in stack
    std::cout << object.getID() << '\n';

    Another *pObject = new Another(2); // creation in heap
    std::cout << pObject->getID() << '\n';
    delete pObject;

    return EXIT_SUCCESS;
}

