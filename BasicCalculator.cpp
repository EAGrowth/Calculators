#include <iostream>

int main() {
    char operation;
    double Fnum, Snum;

    // Prompt the user for input
    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "Enter two numbers: ";
    std::cin >> Fnum >>Snum;

    switch (operation) {
        case '+':
            std::cout << Fnum << " + " << Snum << " = " << Fnum + Snum << std::endl;
            break;
        case '-':
            std::cout << Fnum << " - " << Snum << " = " << Fnum - Snum << std::endl;
            break;
        case '*':
            std::cout << Fnum << " * " << Snum << " = " << Fnum * Snum << std::endl;
            break;
        case '/':
            if (Snum != 0)
                std::cout << Fnum << " / " << Snum << " = " << Fnum / Snum << std::endl;
            else
                std::cout << "Error! Division by zero." << std::endl;
            break;
        default:
            std::cout << "Error! Operator is not correct." << std::endl;
            break;
    }

    return 0;
}
