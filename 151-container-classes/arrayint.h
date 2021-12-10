// example of container class of int type
// can hold any type
//
#ifndef ARRAYINT_H
#define ARRAYINT_H

class ArrayInt
{
  int m_length;                             // length of array
  int * m_data;                             // array of ints
public:
  ArrayInt();                               // zero length array
  ArrayInt(int length);                     // length-sized array
  ~ArrayInt();                              // release memory from m_data array

  void erase();                             // delete all values and make nullptr array 
  int& operator[] (int index);              // indexed element access
  int getLength();                          // length getter

  void reallocate(int newLength);           // erase and change length of array. fast.
  void resize(int newLength);               // non destructive array resize. prevent all values. slow.

  void insertBefore(int value, int index);  // insert value at index
  void remove(int index);                   // remove element at index

  void instertAtBeginning(int value);           // insert at index 0
  void instertAtEnd(int value);                 // insert at index m_length
};

#endif // ARRAYINT_H
