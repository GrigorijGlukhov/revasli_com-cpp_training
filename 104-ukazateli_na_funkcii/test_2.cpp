#include <iostream>

void SetInteger(int& value) {
  do {
    std::cin >> value;
    std::cin.ignore(32767, '\n');
    std::cin.clear();
  } while ( std::isdigit(value) );
}
//------------------------------------------------------------------
void SetOperator(char& op) {
  do {
    std::cin >> op;
    std::cin.ignore(32767, '\n');
    std::cin.clear();
  } while (!(op == '/' || op == '*' || op == '-' || op == '+'));
}
//------------------------------------------------------------------
int Add(int a, int b) {
  return a + b;
}

int Substract(int a, int b) {
  return a - b;
}

int Devide(int a, int b) {
  return a / b;
}

int Multiply(int a, int b) {
  return a * b;
}
//------------------------------------------------------------------
typedef int(*ArithmeticFcn)(int, int);
//------------------------------------------------------------------

struct arithmeticStruct {
  char op;
  ArithmeticFcn fcn;
};

static arithmeticStruct arithmeticArray[] = {
  {'+', Add},
  {'-', Substract},
  {'*', Multiply},
  {'/', Devide}
};

/*ArithmeticFcn GetArithmeticFcn(const char& op) {
  switch( op ) {
    default:
    case '/' : return Devide;
    case '*' : return Multiply;
    case '-' : return Substract;
    case '+' : return Add;
  }
}*/

ArithmeticFcn GetArithmeticFcn(const char& op) {
  for (arithmeticStruct& i: arithmeticArray) {
    if ( op == i.op )
      return i.fcn;
  }
}
//------------------------------------------------------------------

//------------------------------------------------------------------
// Main
//------------------------------------------------------------------
int main() {
  
  int a;
  std::cout << "Enter integer for 'a': ";
  SetInteger(a);
  int b;
  std::cout << "\nEnter integer for 'b': ";
  SetInteger(b);
  
  std::cout << "\nEnter math operator(-,+,*,/): ";
  char op;
  SetOperator(op);

  int result;
  //int(*Calc)(int, int) = GetArithmeticFcn(op);
  // use typedef
  ArithmeticFcn Calc = GetArithmeticFcn(op);
  std::cout << "Result is: " << a << " " << op << " " << b << " = ";
  std::cout << Calc(a, b) << "\n";

  return EXIT_SUCCESS;
}
