#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
#include <iomanip>
#include <limits>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

enum Option {
    STANDARD,
    TRIGONOMETRY,
    LOGARITHMS,
    CHANGE,
    INVALID
};

Option getOption(const string& choose) {
    if (choose == "Standard") return STANDARD;
    if (choose == "Trigonometry") return TRIGONOMETRY;
    if (choose == "Logarithms") return LOGARITHMS;
    if (choose == "Change") return CHANGE;
    return INVALID;
}

void Standard() {
    double FNumber, SNumber;
    char operation;
    string command;

    do {
        cout << "Enter First Number: " << endl;
        cin >> FNumber;
        cout << "Choose an operation (+, -, *, /, %): ";
        cin >> operation;
        cout << "Enter Second Number: " << endl;
        cin >> SNumber;

        switch (operation) {
            case '+':
                cout << "The result is: " << FNumber + SNumber << endl;
                break;
            case '-':
                cout << "The result is: " << FNumber - SNumber << endl;
                break;
            case '*':
                cout << "The result is: " << FNumber * SNumber << endl;
                break;
            case '/':
                if (SNumber != 0) {
                    cout << "The result is: " << FNumber / SNumber << endl;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            case '%':
                if (SNumber != 0) {
                    cout << "The result is: " << fmod(FNumber, SNumber) << endl;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            default:
                cout << "Invalid operation!" << endl;
                break;
        }

        cout << "Type 'Exit' to quit or 'Change' to change calculator type, or press Enter to continue: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, command);

        if (command == "Change") break;

    } while (command != "Exit");
}

void Trigonometry() {
    double angle;
    string function;
    string command;

    do {
        cout << "Enter angle in degrees: ";
        cin >> angle;

        double radians = angle * (M_PI / 180.0);

        cout << "Choose a trigonometric function (sin, cos, tan): ";
        cin >> function;

        double result;
        if (function == "sin") {
            result = sin(radians);
        } else if (function == "cos") {
            result = cos(radians);
        } else if (function == "tan") {
            result = tan(radians);
        } else {
            cout << "Invalid function!" << endl;
            return;
        }

        cout << "The result is: " << result << endl;

        cout << "Type 'Exit' to quit or 'Change' to change calculator type, or press Enter to continue: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, command);

        if (command == "Change") break;

    } while (command != "Exit");
}

void Logarithms() {
    double number;
    string base;
    string command;

    do {
        cout << "Enter a number: ";
        cin >> number;
        cout << "Choose the logarithm base (2 for log base 2, 10 for log base 10, e for natural log): ";
        cin >> base;

        double result;
        if (base == "2") {
            result = log2(number);
        } else if (base == "10") {
            result = log10(number);
        } else if (base == "e") {
            result = log(number);
        } else {
            cout << "Invalid base!" << endl;
            return;
        }

        cout << "The result is: " << result << endl;

        cout << "Type 'Exit' to quit or 'Change' to change calculator type, or press Enter to continue: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, command);

        if (command == "Change") break;

    } while (command != "Exit");
}

int main() {
    string choose;
    Option option;

    do {
        cout << "Choose an option (Standard, Trigonometry, Logarithms) or type 'Exit' to quit: ";
        getline(cin, choose);

        if (choose == "Exit") break;

        option = getOption(choose);

        switch (option) {
            case STANDARD:
                Standard();
                break;
            case TRIGONOMETRY:
                Trigonometry();
                break;
            case LOGARITHMS:
                Logarithms();
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (true);

    return 0;
}
