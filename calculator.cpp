#include <iostream>
using namespace std;

void add(double x, double y) {
    cout << "The result of addition is: " << x + y << endl;
}

void subtract(double x, double y) {
    cout << "The result of subtraction is: " << x - y << endl;
}

void multiply(double x, double y) {
    cout << "The result of multiplication is: " << x * y << endl;
}

void divide(double x, double y) {
    if (y != 0) {
        cout << "The result of division is: " << x / y << endl;
    } else {
        cout << "Error: Division by zero is not allowed." << endl;
    }
}

int main() {
    double num1, num2;
    int choice;
    char continueCalculation;

    do {
        // Input first number
        cout << "Enter the first number: ";
        cin >> num1;

        // Input second number
        cout << "Enter the second number: ";
        cin >> num2;

        // Choose operation
        cout << "Choose an operation:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "Enter the number corresponding to the operation (1/2/3/4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                add(num1, num2);
                break;
            case 2:
                subtract(num1, num2);
                break;
            case 3:
                multiply(num1, num2);
                break;
            case 4:
                divide(num1, num2);
                break;
            default:
                cout << "Invalid operation choice. Please enter a number between 1 and 4." << endl;
                break;
        }

        // Ask user if they want to perform another calculation
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueCalculation;
    } while (continueCalculation == 'y' || continueCalculation == 'Y');

    cout << "Thank you for using the calculator. Goodbye!" << endl;

    return 0;
}
