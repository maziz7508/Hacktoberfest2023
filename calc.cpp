#include <iostream>
using namespace std;

int main() {
  char op;
  float num1, num2;

  cout << "Enter operator (+, -, *, /): ";
  cin >> op;

  cout << "Enter two operands: ";
  if (!(cin >> num1 >> num2)) {
    cout << "Invalid input. Please enter numeric operands." << endl;
    return 1; // Exit with an error code
  }

  switch (op) {
    case '+':
      cout << num1 << " + " << num2 << " = " << num1 + num2;
      break;

    case '-':
      cout << num1 << " - " << num2 << " = " << num1 - num2;
      break;

    case '*':
      cout << num1 << " * " << num2 << " = " << num1 * num2;
      break;

    case '/':
      if (num2 != 0) {
        cout << num1 << " / " << num2 << " = " << num1 / num2;
      } else {
        cout << "Error! Division by zero is not allowed.";
      }
      break;

    default:
      cout << "Error! Invalid operator.";
      break;
  }

  return 0;
}
