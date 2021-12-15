// Access specifiers and inheritance
// :public :private :protected

#include <iostream>

class Parent
{
  public:
    int m_public;
  private:
    int m_private;
  protected:
    int m_protected;
};

class Priv : private Parent
{
// all members from Parent are private now and can't be accessed neigther from children class or outside
// m_public - denied
// m_private - denied
// m_protected - denied
  public:
    int m_public2;
  private:
    int m_private2;
  protected:
    int m_protected2;
};

class Prot : protected Priv
{
// Can't access to all members of Parent class(all private in Priv class)
// can access to m_public2 and m_protected2 because they all protected now
// can't access to Priv members from Prot class from outside (all protected)
// m_public - denied
// m_private - denied
// m_protected - denied
// m_public2 - protected - only children
// m_private2 - denied
// m_protected2 - protected - only children
  public:
    int m_public3;
  private:
    int m_private3;
  protected:
    int m_protected3;
};


int main()
{
  Parent parent;
  parent.m_public = 1;

  Priv priv;
  priv.m_public2 = 2;

  Prot prot;
  prot.m_public3 = 3;m_public2 = 2;

  Prot prot;
  prot.m_public3 = 3;

  return 0;
}
