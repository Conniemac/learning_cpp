#include <iostream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <random>
#include <cctype>

using namespace std;

bool is_digits(string* str){

	for (char character : *str){
		if (!isdigit(character)){
			return false;
		}
	}

	return true;
}

int main(){

    static random_device rd;
	static mt19937 engine(rd());
	uniform_int_distribution<int> dist(0,100);
	int random_number{dist(engine)};

	string user_input{};
	int guess{};
	bool correct_guess{false};
	int guess_count{0};
	while (!correct_guess){

		if (guess_count >= 10){
			cout << "You ran out of guesses. The number was: " << random_number << '\n';
			return 0;
		}

		cout << "Enter a integer between 0 and 100: ";
		getline(cin, user_input);
		if (is_digits(&user_input)){
			guess = stoi(user_input);
		}
		else{
			cout << string("'") + user_input + "' is not a number. Not counting this guess.\n\n";
			continue;
		}


		if (guess < 0 || guess > 100){
			cout << (string("'") + to_string(guess) + "' is not between 0 and 100. Not counting this guess.\n\n");
			continue;
		}

		if (guess == random_number){
			cout << "You win. The random number was: " << random_number << '\n';
			break;
		}
		else{

			if (guess < random_number){
				cout << "Higher\n\n";
			}
			else{
				cout << "Lower\n\n";
			}
		}


		guess_count++;
	}



	return 0;
}