//This is a calculator app 
#include <iostream>
using namespace std;

int main() {
    char opr;
    int num1, num2;
    int result;

    cout << "enter an operator" << endl;
    cin >> opr;

    while(opr != '+' && opr != '-' && opr != '*' && opr != '/') {
        cout << "Please enter a valid operator +, -, *, /" << endl;
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
        default:
            cout << "Invalid operator" << endl;
    }

    cout << num1 << " " << opr << " " << num2 << " = " << result << endl;

    return 0;
}