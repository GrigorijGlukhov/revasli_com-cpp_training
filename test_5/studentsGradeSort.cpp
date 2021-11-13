#include <iostream> 
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    int score;
};

//enter number of names
int getValue() {
    int a;
    std::cin >> a;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32765, "\n");
    }
    else
        return a;
}

//get single name
std::string getName() {
    std::string name;
    std::cin >> name;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, "\n");
    }
    else
        return name;
}

void setStudentData(Student *students, const int *studentsCount) {
    for (int person = 0; person < *studentsCount; ++person,students++) {
        std::cout << "Enter name #" << person+1 << " ";
        students->name = getName();
        std::cout << " and score: ";
        students->score = getValue();
        std::cout << "\n";
    }
}




//sort struct by score
void sortStudentsByScore(Student students[], const int *numberOfStudents) {
    Student *st1, *st2;
    for(int student = 0; student < numberOfStudents-1; ++student) {
        int smallestIndex = student;
        for(int searchIndex = smallestIndex+1; searchIndex < numberOfStudents-1) {
            
        }
    }
}





void printListOfStudents(const Student *students, const int *numberOfStudents) {
    for (int student = 0; student < *numberOfStudents; ++student,students++) {
        std::cout << student+1 << " " << students->name << " has score: " << students->score << "\n";
    }
}

int main(){
    
    std::cout << "Enter number of students: ";
    int numberOfStudents = getValue();

    Student *students = new Student[numberOfStudents];
    
    setStudentData(&students, &numberOfStudents);
    
    sortStudentsByScore(students, &numberOfStudents);
    
    printListOfStudents(&students, &numberOfStudents);
    
    return 0;
}