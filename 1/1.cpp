#include<iostream>
using namespace std;

// Function prototypes
void input(int& inputleft, int& inputright);
void conversion(int& origin, int& inputleft, int& inputright, char& a_or_p);
void output(int& origin, int& inputleft, int& inputright, char& a_or_p);

int main(void) {
    int finish = 0;

    do {
        int origin = 0;
        int userinputL = 0, userinputR = 0;
        char a_or_p;
        char keep_search;
        input(userinputL, userinputR);        // Call input function to get user inputs
        conversion(origin, userinputL, userinputR, a_or_p);    // Convert time to 12-hour format
        output(origin, userinputL, userinputR, a_or_p);        // Output converted time
        cout << "Do you want to search two more integers? (y/n)\n"; // Ask user if they want to continue
        do {
            cin >> keep_search;
            if (keep_search == 'y') {
                break;
            }
            else if (keep_search == 'n') {
                finish = 1; // Set finish flag to 1 to exit the loop
                break;
            }
            else {
                cout << "Error input: " << keep_search << "\nPlease enter \"y\" or \"n\" to decide whether to keep searching\n";
            }
        } while (1);
    } while (!finish);

    cout << "\nBye Bye"; // Display farewell message

    return 0;
}

// Function to get user inputs
void input(int& inputleft, int& inputright) {
    cout << "Please enter two integers that you want to search.\n(eg: if you want to search 14:15, enter 14,15)\n";

    do {
        cout << "\nFirst integer:\n";
        cin >> inputleft;
        if (inputleft >= 0 && inputleft <= 24) { // Check if input is within valid range
            break;
        }
        else {
            cout << "Error input: " << inputleft << "\nPlease enter an integer between 0 to 24\n";
        }
    } while (1);

    do {
        cout << "\nSecond integer:\n";
        cin >> inputright;
        if (inputright >= 0 && inputright < 60) { // Check if input is within valid range
            break;
        }
        else {
            cout << "Error input: " << inputright << "\nPlease enter an integer between 0 to 59\n";
        }
    } while (1);
}

// Function to convert time to 12-hour format
void conversion(int& origin, int& inputleft, int& inputright, char& a_or_p) {
    origin = inputleft;
    if (inputleft > 12 && inputleft <= 24) {
        inputleft -= 12;
        a_or_p = 'p';
    }
    else if (inputleft <= 12 && inputleft >= 0) {
        a_or_p = 'A';
    }
}

// Function to output converted time
void output(int& origin, int& inputleft, int& inputright, char& a_or_p) {
    cout << origin << ":" << inputright << "=" << inputleft << ":" << inputright;
    if (a_or_p == 'A') {
        cout << " A.M\n";
    }
    else if (a_or_p == 'p') {
        cout << " P.M\n";
    }
}
