#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>;

using namespace std;

int main(void) {
    srand(time(0)); // Initialize random seed using the current time
    int real_pin = 0; // Variable to store the real PIN
    int real_PIN[5]; // Array to store the individual digits of the real PIN
    int correct_num[5]; // Array to store the correct numbers based on real PIN
    int rnum[10]; // Array to store random numbers
    int inpuut_num = 0; // Variable to store user input PIN
    int inpuut_NUM[5]; // Array to store individual digits of user input PIN
    int PIN_correct = 0; // Variable to track the number of correct digits in user input PIN

    cout << "Please enter your PIN(five num)\n"; // Prompting user to enter their PIN

    cin >> real_pin; // Reading the real PIN from the user

    // Extracting individual digits of the real PIN and storing them in the array real_PIN
    for (int i = 0; i < 5; i++) {
        real_PIN[4 - i] = real_pin / int(pow(10, i)) % 10;
    }

    cout << "\nPIN";
    // Displaying the header for PIN numbers
    for (int i = 0; i <= 9; i++) {
        cout << " " << i;
    }

    cout << "\nnum";
    // Generating random numbers and displaying them
    for (int i = 0; i <= 9; i++) {
        rnum[i] = rand() % 3 + 1;
        cout << " " << rnum[i];
    }

    // Assigning correct numbers based on the real PIN
    for (int i = 0; i < 5; i++) {
        correct_num[i] = rnum[real_PIN[i]];
    }

    cout << "\n\nEnter your PIN to inspect your data\n";

    // Loop to repeatedly ask user for PIN input until it's correct
    do {
        PIN_correct = 0; // Resetting the number of correct digits

        // Reading the user input PIN and extracting individual digits
        cin >> inpuut_num;
        for (int i = 0; i < 5; i++) {
            inpuut_NUM[4 - i] = inpuut_num / int(pow(10, i)) % 10;
        }

        // Checking each digit of user input PIN against correct numbers
        for (int i = 0; i < 5; i++) {
            if (inpuut_NUM[i] == correct_num[i]) {
                PIN_correct += 1; // Incrementing correct digit count
            }
        }

        // If all digits are correct, display success message and the dog ASCII art
        if (PIN_correct == 5) {
            cout << "\nPIN correct";
            cout << "\n\nYour PIN:";
            for (int i = 0; i < 5; i++) {
                cout << real_PIN[i];
            }
            cout << "\nThe num:";
            for (int i = 0; i < 5; i++) {
                cout << correct_num[i];
            }
            cout << "\nYour dog:\n\n";

            // ASCII art of a dog
            std::cout << "     / \\__" << std::endl;
            std::cout << "   (       @\\___" << std::endl;
            std::cout << "   /             O" << std::endl;
            std::cout << " /      (_____/" << std::endl;
            std::cout << "/______/       U" << std::endl;

            break; // Exit the loop
        }
        else {
            cout << "\nPIN wrong\nplease enter again\n"; // Display message for wrong PIN input
        }
    } while (1); // Infinite loop until correct PIN is entered

    return(0);
}
