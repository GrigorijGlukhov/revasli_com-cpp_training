#include <iostream>
#include <cstdint>
#include <algorithm>

//------------------------------------------------------------------

struct Student {
  std::string name;
  int score;
};

//------------------------------------------------------------------
// getInput for strings with spaces
//------------------------------------------------------------------
void getString(std::string & name, const std::string msg) {
  while (true) {
    std::cout << msg;
    getline(std::cin, name);
    if ( std::cin.fail() ) {
      std::cin.clear();
      std::cin.ignore(32767, '\n');
      std::cout << "Wrong. Try again!\n";
    } else {
      std::cin.ignore(32767, '\n');
      return;
    }
  }
}


//------------------------------------------------------------------
// getInput for int with spaces
//------------------------------------------------------------------
void getInt(int & value, const std::string message) {
  std::cout << message;
  std::cin >> value;
  while(std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(32767, '\n');
    std::cout << "Try again: ";
    std::cin >> value;
  }
}



//------------------------------------------------------------------
void GetStudentsData(Student * studentsArray, int numberOfStuds) {
  Student *current;
  for ( int st = 0; st < numberOfStuds; ++st ) {
    current = studentsArray+st;
    getString(current->name, "Enter student name: ");
    getInt(current->score, "Enter student score: ");
  }
}

void PrintStudentsList(Student * studentsArray, int numberOfStuds, std::string msg) {
  std::cout << msg;
  Student *current;
  for ( int st = 0; st < numberOfStuds; ++st ) {
    current = studentsArray+st;
    std::cout << st+1 << ") Name: " << current->name << " has score: ";
    std::cout << current->score << '\n';
  }
}
//------------------------------------------------------------------

void sortStudents(Student * students, int length) {
  for ( int st = 0; st < length; ++st) {
    int largestIndex = st;
    for ( int rest = st+1; rest < length; ++rest) {
      if ( students[rest].score > students[largestIndex].score ) {
        largestIndex = rest;
      }
    }
    std::swap(students[st], students[largestIndex]);
  }
}

//------------------------------------------------------------------
// Main
//------------------------------------------------------------------
int main() {
  // ask for students count
  int stCnt;
  getInt(stCnt, "Enter number of students: ");

  // create array of Student struct size of stCnt
  Student *students = new Student[stCnt];

  // fill stubents bio with data
  GetStudentsData(students, stCnt);

  // sort students by score
  std::cout << "\nSorting:";
  sortStudents(students, stCnt);

  // print result
  std::cout << '\n';
  PrintStudentsList(students, stCnt, "Students list:\n");

  //swap(students,students+1);

  // print result
  std::cout << '\n';
  //PrintStudentsList(students, stCnt, "Students list:\n");
  
  //release heap and null ptr
  delete[] students;
  students = nullptr;

  return EXIT_SUCCESS;
}


