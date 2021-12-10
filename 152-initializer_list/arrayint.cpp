// example of container class of int type
// can hold any type
//
#include <cassert>

#include "arrayint.h"

ArrayInt::ArrayInt() : m_length(0), m_data(nullptr) {} // zero length array
ArrayInt::ArrayInt(int length) : m_length(length) // length-sized array
{
  assert(length >= 0); // protection from zero-less length
  if( length > 0 ) // check for positive length of array
    m_data = new int[length]; // create length-sized array of ints
  else
    m_data = nullptr; // initialize m_data with null pointer
}
ArrayInt::ArrayInt(const std::initializer_list<int> & list) : ArrayInt(list.size()) // std::initializer_list ctor
{
  int count = 0; // initialize star element
  for( auto & element : list )
  {
    m_data[count] = element;
    ++count;
  }
}
ArrayInt::~ArrayInt() { delete[] m_data; } // release memory from m_data array

void ArrayInt::erase()
{
  delete[] m_data; // delete memory references for this array
  m_data = nullptr; // m_data should be nulled because its still exists (prevent hanged pointer)
  m_length = 0;
}

int& ArrayInt::operator[] (int index)
{
  assert(index >= 0 && index < m_length); // prevent out of index
  return m_data[index]; // return ref to indexed element of array
}

int ArrayInt::getLength() { return m_length; } // getter length of array 

void ArrayInt::reallocate( int newLength ) // clear and resize array
{
  erase(); // erase array

  if ( newLength <= 0 ) // return if length is zero, because erase() zeroyed array already
    return;

  m_data = new int[newLength]; // recreating array
  m_length = newLength; // store new length
}

void ArrayInt::resize( int newLength ) // resize and prevent array data
{
  if( newLength == m_length ) // return if nothing to do
    return;

  if( newLength <= 0 ) // erase if zero or negative length
  {
    erase();
    return;
  }

  int *_data = new int[newLength]; // temp array

  if ( m_length > 0 )
  {
    int elementsToCopy = (newLength > m_length) ? m_length : newLength; // choose using new length or m_length

    for( int index = 0; index < elementsToCopy; ++index )
      _data[index] = m_data[index];

  }

  delete[] m_data; // clear old array

  m_data = _data; // copy new created array to m_data
  m_length = newLength;
}

void ArrayInt::insertBefore( int value, int index ) // insert value element at index
{
  assert(index >= 0 && index <= m_length);
  
  int *_data = new int[m_length+1]; // create temp array of m_length + 1
  
  for( int before = 0; before < index; ++before ) // copy firest part of array to temp array
    _data[before] = m_data[before];
  
  _data[index] = value; // insert new element at index
  
  for( int after = index; after < m_length; ++after )
    _data[after + 1] = m_data[after]; // copy rest of array after index
  
  delete[] m_data; // clear old array
  m_data = _data;
  ++m_length;
}

void ArrayInt::remove( int index ) // remove indexed element from array
{
  assert(index >= 0 && index < m_length);

  if ( m_length == 1 )
  {
    erase();
    return;
  }

  int *_data = new int[m_length - 1]; // create temp array of length - 1

  for( int before = 0; before < index; ++before ) // copy first part of array
    _data[before] = m_data[before];

  for( int after = index + 1; after < m_length; ++after )
    _data[after - 1] = m_data[after];

  delete[] m_data; // clear old array
  m_data = _data;
  --m_length;
}

void ArrayInt::instertAtBeginning(int value) { insertBefore(value, 0); }
void ArrayInt::instertAtEnd(int value) { insertBefore(value, m_length); }

//void ArrayInt::operator=(const std::initializer_list<int> & list) // assignment operator overloading. By element copy
//{
//  int _listSize = list.size();
//  int *_data = new int[_listSize];
//  int _index = 0;
//  for(auto & element : list)
//  {
//    _data[_index] = element;
//    ++_index;
//  }
//  delete[] m_data;
//  m_data = _data;
//  m_length = _listSize;
//}

ArrayInt& ArrayInt::operator=(const std::initializer_list<int> & list) // assignment operator overloading. By element copy
{
  if( list.size() != static_cast<unsigned int>(m_length) ) // if length not same recreate m_data
  {
    delete[] m_data;
    m_length = list.size();
    m_data = new int[m_length];
  }
  // copy elements
  int _index = 0;
  for( auto & element : list )
  {
    m_data[_index] = element;
    ++_index;
  }
  return *this;
}

