// Aggregation class example
//
#include <iostream>
#include <string>

class Worker
{
  std::string m_name;
public:
  Worker(const std::string & name) : m_name(name) {}
  std::string getName() { return m_name; }
};

class Department
{
  Worker *m_worker;
public:
  Department(Worker * worker = nullptr) : m_worker(worker) {}
};

int main()
{
  Worker *worker = new Worker("Alex");
  { // new department namespace
    Department department(worker); // Departnent aggregates worker 
  } // destroy Department

  delete worker; // worker is still alive

  return 0;
}
