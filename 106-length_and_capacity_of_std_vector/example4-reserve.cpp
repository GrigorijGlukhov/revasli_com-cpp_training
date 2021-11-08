// shows how std::vector changing its capacity and length
// using sdt::vector reserve(n)

#include <iostream>
#include <vector>

void printStack( const std::vector<int> & vector ) {
  for ( auto const & elem : vector )
    std::cout << elem << ' ';
  std::cout << "Vector (capacity " << vector.capacity() << " length " << vector.size() << ")\n";
}

int main() {
  std::vector<int> stack;

  stack.reserve(7);

  printStack(stack);
  
  stack.push_back(7);
  printStack(stack);

  stack.push_back(5);
  printStack(stack);

  stack.push_back(3);
  printStack(stack);

  std::cout << "top on stack: " << stack.back() << "\n";

  stack.pop_back();
  printStack(stack);

  stack.pop_back();
  printStack(stack);

  stack.pop_back();
  printStack(stack);

  
  return EXIT_SUCCESS;
}
