// indexing operator overloading
// const and non-const objects
// poiter to object and indexing
#include <iostream>
#include "intarray.h"

int main()
{
  IntArray array;
  //array[12] = 5; // error assert!!!
  array[4] = 5; // correct!

  std::cout << array[4] << '\n';
  
  const IntArray carray; // const object
  //carray[4] = 100; // error! can't assign value to const reference
  std::cout << carray[4] << '\n';

  // pointer to object and indexing
  IntArray *parray = new IntArray;
  (*parray)[4] = 5; // pointer derefenrence 
  std::cout << (*parray)[4] << '\n';


  return 0;
}
