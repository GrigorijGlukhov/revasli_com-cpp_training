#include <iostream>
#include <cassert>

class Stack {
    const int m_aLength = 10;
    int m_array[10];
    int m_stackLength = 0;
    public:
    void reset() {
		m_stackLength = 0;
      for( int elem = 0; elem < m_aLength; ++elem )
      	m_array[elem] = 0;
    }
	
    bool push(int val) {
		if( m_stackLength < m_aLength ) {
			m_array[m_stackLength] = val;
			std::cout << m_stackLength << " " << val << "\n";
			++m_stackLength;
			return true;
		}
     	return false;
    }
	
    int pop() {
		if( m_stackLength > 0 ) {
			--m_stackLength;
			int _result = m_array[m_stackLength];
			m_array[m_stackLength] = 0;
			std::cout << m_stackLength << " " << _result << "\n";
			return _result;
		}
		assert(false && "Stack is empty");
    }
	
    void print() {
		std::cout << "( ";
        for( int elem = 0; elem < m_aLength; ++elem )
        		if (m_array[elem] > 0) std::cout << m_array[elem] << " ";
    	std::cout << ")\n";
    }
};

int main(){
    
    Stack stack;
    stack.reset();
    stack.print();
    
    stack.push(5);
    stack.push(3);
    stack.push(7);
    stack.print();
    
    stack.pop();
	 //stack.print();
	 stack.pop();
    //stack.print();
	 stack.pop();
	 stack.print();
    
    return 0;
}