// using of destructor with dynamic memory in class
// RAII - resource Acquisition is Initialization
// Massiv using RAII - allocates and deletes dynamic memory
//
#include <iostream>
#include <string>

class Massiv
{
    int *m_array;
    int m_length;
public:
    Massiv( int length ) : m_length{length}
    {
        m_array = new int[m_length];
    }
    ~Massiv()
    {
        delete[] m_array;
    }
    void setValue( int index, int value ) { m_array[index] = value; }
    int getValue( int index ) { return m_array[index]; }

    int getLength() { return m_length; }
};

int main()
{
    Massiv arr(15);
    for ( int count=0; count < arr.getLength; ++count ) 
        arr.setValue( count, count+1 );
    std::cout << "The value of element 7 is " << arr.getValue(7);

    return EXIT_SUCCESS;
}

