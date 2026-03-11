#include <iostream>
#include <string>
#include <cctype> 
#include <tuple>
#include <stdexcept> 

using namespace std;


tuple<string, string, char> parse_problem_string(string problem){

	string number_string1{""};
	string number_string2{""};
	char operation{};

	cout << "Starting string parsing: \n";
	bool first_number{true};
	for (char ch: problem){

		if (ch == '+' || ch == '-' || ch == '/' || ch == '*'){
			cout << "operator" << '\n';
			operation = ch;
			first_number = false;
		}
		else if (ch == ' '){
			cout << "space" << '\n';
			continue;
		}
		else{ 
			if (!isdigit(ch)){
				throw invalid_argument(string("'") + ch + "' is not a digit\n"); 
			}

			if (first_number){
				cout << "number1" << '\n';
				number_string1 += ch;
			}
			else{

			cout << "number2" << '\n';
			number_string2 += ch;
			}
		}

	}

	return {number_string1, number_string2, operation};
}

int main()
{


	string problem{};
	cout << "Enter a simple math problem using +, -, / or *: ";
	getline(cin, problem);

	auto [number_string1, number_string2, operation] = parse_problem_string(problem);

	cout << "\nString parsing results: \n";
	cout << "operator: " << operation << '\n';
	cout << "number1: " << number_string1 << '\n';
	cout << "number2: " << number_string2 << "\n\n";

	float result{};
	float number1{stof(number_string1)};
	float number2{stof(number_string2)};
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
		cout << "Invalid operation '" << operation << "'. Operation must be +, -, / or *\n";
		return -1;
	}

	cout << "Result: " << number1 << ' ' << operation << ' ' << number2 << " = " << result << '\n';
}