//This is a calculator app which have operations +, -, *, /, %
#include <iostream>
#include <iomanip>
#include <limits> 

using namespace std;

double getUserInput() {
    double value;
    while (true) {
        cout << "Please enter a double value: ";
        cin >> value;

        // Check if the input is valid
        if (cin.fail()) {
            // If input is not valid, clear the error flag
            cin.clear();
            // Ignore the rest of the line to discard the invalid input
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "Invalid input. Please enter a valid double value." << std::endl;
        } else {
            // If input is valid, break out of the loop
            cin.ignore(numeric_limits < streamsize > ::max(), '\n'); // Clear the input buffer
            break;
        }
    }
    return value;
}

int main() {
    char opr;
    double num1, num2;
    double result;

    cout << "enter an operator" << endl;
    cin >> opr;

    //Will keep asking the user to enter a valud operator untill they give one of the expected ones. 
    while(opr != '+' && opr != '-' && opr != '*' && opr != '/' && opr != '%') {
        cout << "Please enter a valid operator +, -, *, /, %" << endl;
        cin >> opr;
    }

    num1 = getUserInput();
    num2 = getUserInput();
    
    switch(opr) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '%':
            result = static_cast<int>(num1) % static_cast<int>(num2);  //static convertion from double to int because % only takes int
            break;
        default:
            cout << "Invalid operator" << endl;
    }

    cout << num1 << " " << opr << " " << num2 << " = " << result << endl;

    return 0;
}