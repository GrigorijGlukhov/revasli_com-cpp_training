#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray
{
  int m_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
public:
  int& operator[] (int index); // for non-const objects
  const int& operator[] (int index) const; // for const objects
};


#endif
