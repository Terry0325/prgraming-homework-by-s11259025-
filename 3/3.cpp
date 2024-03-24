#include <iostream>
using namespace std;

int main(void) {
    int student = 0;
    int input_index = 0; // Variable to keep track of the index for student inputs
    int input[1000]; // Array to store student inputs
    int grade_index = 0; // Variable to iterate through grades
    int grade[6] = { 0, 0, 0, 0, 0, 0 }; // Array to store count of each grade

    cout << "How many students?\n"; // Prompt to enter the number of students
    cin >> student; // Input the number of students

    cout << "Please enter all student scores separated by space (e.g., 6 students => 0 1 2 3 4 5):\n"; // Prompt to enter student scores
    do {
        cin >> input[input_index]; // Input each student score
        for (grade_index = 0; grade_index <= 5; grade_index++) { // Iterate through grades
            if (input[input_index] == grade_index) { // Check if the student score matches the current grade
                grade[grade_index] += 1; // Increment the count of that grade
            }
        }
        input_index++; // Move to the next student input

    } while (input_index < student); // Continue until inputs for all students are taken

    for (grade_index = 0; grade_index <= 5; grade_index++) { // Loop through each grade
        cout << "\n" << grade[grade_index] << " grade(s) of " << grade_index << "\n"; // Output the count of students for each grade
    }

    return 0;
}
