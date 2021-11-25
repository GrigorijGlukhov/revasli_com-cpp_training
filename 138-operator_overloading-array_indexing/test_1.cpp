#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
  std::string name;
  char grade;
};

class GradeMap
{
  std::vector<StudentGrade> m_map;
public:
  GradeMap();
  char& operator[] (const std::string&);
};
GradeMap::GradeMap() {};
char& GradeMap::operator[] (const std::string & name)
{
  for( auto &student : m_map ) // search for Studen by name
    if (student.name == name)
      return student.grade; // return grade of found Student
  StudentGrade temp{name, ' '}; // temporary Student obj
  m_map.push_back(temp); // add temp-obj to m_map(at end)
  return m_map.back().grade; // get last element of m_map and return ref char& to its member-var grade to assign value from outside
}

int main()
{
  GradeMap grades;
  grades["Ivan"] = 'A';
  grades["Bob"] = 'B';

  std::cout << grades["Ivan"] << '\n';
  std::cout << grades["Bob"] << '\n';


  return 0;
}
