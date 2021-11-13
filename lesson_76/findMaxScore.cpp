#include <iostream> 

int main(){
    int scores[] = {47, 25, 16, 73, 34, 51, 85, 48, 19};
    
    int numStudents = sizeof(scores) / sizeof(scores[0]);
    
    int maxScore = 0;
    int maxScoreIndex = 0;
    for(int student = 0; student < numStudents; ++student) {
        if(scores[student] > maxScore) {
            maxScore = scores[student];
            maxScoreIndex = student;
        }
    }
    std::cout << "The best score was " << maxScore << " has index " << maxScoreIndex << "\n";
    
    return 0;
}