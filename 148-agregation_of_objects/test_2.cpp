// Aggregation class example
//
#include <iostream>
#include <string>
#include <vector>

class Worker
{
  std::string m_name;
public:
  Worker(const std::string & name) : m_name(name) {}
  std::string getName() { return m_name; }
};

class Department
{
  std::vector<Worker *> m_workers;
public:
  Department() {}
  void add(Worker * worker)
  {
    m_workers.push_back(worker);
  }

  friend std::ostream& operator<< (std::ostream & out, const Department & dept)
  {
    for ( auto & worker : dept.m_workers )
      out << worker->getName() << ' ';
    return out;
  }
};

int main()
{
  Worker *worker1 = new Worker("Alex");
  Worker *worker2 = new Worker("Bob");
  Worker *worker3 = new Worker("Claude");
  { // new department namespace
    Department department; // Departnent aggregates worker 
    department.add(worker1);
    department.add(worker2);
    department.add(worker3);

    std::cout << department << '\n';
  } // destroy Department

  std::cout << worker1->getName() << '\n';
  std::cout << worker2->getName() << '\n';
  std::cout << worker3->getName() << '\n';

  delete worker1; // worker is still alive
  delete worker2; 
  delete worker3;

  return 0;
}
