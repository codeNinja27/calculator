//This is a calculator app which have operations +, -, *, /, %
#include <iostream>
#include <iomanip>

using namespace std;

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

    cout << "enter two numbers" << endl;
    cin >> num1;
    cin >> num2;
 
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