#include <iostream>
#include <string>

class Welcome
{
    char *m_data;
public:
    Welcome() // ctor
    {
        m_data = new char[14];
        const char *init = "Hello, World!";
        for ( int ch=0; ch<14; ++ch )
            *(m_data+ch) = *(init+ch);
    }
    ~Welcome() { delete[] m_data; } // dtod
    void print()
    {
        std::cout << m_data << "\n";
    }
};

int main()
{
    Welcome wlcme;
    wlcme.print();

    return 0;
}
