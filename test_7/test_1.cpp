#include <iostream>

double max( double a, double b) {
  return a > b ? a : b;
}

void swap( int & a, int & b ) {
  int tmp = b;
  b = a;
  a = tmp;
}

int getLargestElemrnt( int array[], int count ) {
  int largest = 0;
  for ( int elem = 0; elem < count; ++elem )
    if(largest < array[elem]) largest = array[elem];
  return largest;
}

int main() {

  std::cout << max(3, 5) << '\n';
  int a = 5, b = 3;
  std::cout << a << " " << b << '\n';
  swap(a, b);
  std::cout << a << " " << b << '\n';

  int *array = new int[7] {0, 3, 9, 4, 5, 8, 2};
  std::cout << "largest: " << getLargestElemrnt( array, 7 );

  delete[] array;

  return EXIT_SUCCESS;
}
