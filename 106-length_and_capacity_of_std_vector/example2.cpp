#include <iostream>
#include <vector>

int main() {
  std::vector<int> array;
  array = {0, 1, 2, 3, 4};
  array.resize(8);
  array = {3, 5, 7};

  std::cout << "Length of array: " << array.size() << '\n';
  std::cout << "Capacity of array: " << array.capacity() << '\n';

//  for (auto const & elem : array )
//    std::cout << elem << " ";
  
  return EXIT_SUCCESS;
}
