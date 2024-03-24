#include<iostream>
using namespace std;

// Function prototypes
double convertToMPH(int min, int sec);
double convertToMPH(double kph);

int main(void) {
    int choise = 0;
    int min = 0, sec = 0;
    double kph = 0;
    double mph = 0;

    cout << "To calculate your speed in mph, you can enter your speed by:\n(1) minutes and seconds per mile\n(2) kilometers per hour\n";
    cout << "Which way do you choose? (1/2)\n";

    do {
        choise = 0;
        cin >> choise;
        if (choise == 1) {
            do {
                cout << "\nMinutes: ";
                cin >> min;
                if (min < 0) {
                    cout << "Error input: " << min;
                    cout << " Please enter an integer greater than 0\n";
                }
                else {
                    break;
                }
            } while (1);

            do {
                cout << "\nSeconds: ";
                cin >> sec;
                if (sec >= 60 || sec < 0) {
                    cout << "Error input";
                    cout << " Please enter an integer between 0 and 59\n";
                }
                else {
                    mph = convertToMPH(min, sec);
                    cout << "\nYour speed: " << mph << " mph";
                    break;
                }
            } while (1);
            break;
        }
        else if (choise == 2) {
            cout << "Kilometers per hour:\n";
            cin >> kph;
            mph = convertToMPH(kph);
            cout << "\nYour speed: " << mph << " mph";
            break;
        }
        else {
            cout << "Error input";
            cout << "\nPlease enter 1 or 2 to choose the method\n";
            break;
        }
    } while (1);

    return 0;
}

// Function to convert minutes and seconds per mile to mph
double convertToMPH(int min, int sec) {
    double min_sec = min + sec / 60;
    return 60 / min_sec;
}

// Function to convert kilometers per hour to mph
double convertToMPH(double kph) {
    return (kph / 1.61);
}
