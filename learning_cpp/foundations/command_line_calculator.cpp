#include <iostream>
#include <string>

using namespace std;

int main()
{

	float number1{};
	cout << "Enter a number: ";
	cin >> number1;

	float number2{};
	cout << "Enter another number: ";
	cin >> number2;

	char operation{};
	cout << "Enter a operation (+, -, / or *): ";
	cin >> operation;


	float result{};
	if (operation == '+'){
		result = number1 + number2;
	}
	else if (operation == '-'){
		result = number1 - number2;
	}
	else if (operation == '/'){
		result = number1 / number2;
	}
	else if (operation == '*'){
		result = number1 * number2;
	}
	else{
		cout << "Invalid operation. Valid options are +, -, / or *";
		return -1;
	}

	cout << to_string(number1) + " " + operation + " " + to_string(number2) + " = " + to_string(result) + "\n";

	return 0;

}