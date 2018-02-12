#include <ctime>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
	srand(time(NULL));
	string Response;
	int p1score = 0;
	int p2score = 0;
	bool rematch = 1;

		cout << "Let's have you fight an ai." << endl;
		while (rematch == 1) {
			cout << "Select your sign. (rock, paper, scissors)" << endl;
			getline(cin, Response);
			int airesponse = rand() % 3;//generates 0 - 2; 0 = rock, 1 = paper, 2 = scissors
			if (Response.compare("rock") != 1 && airesponse == 0)
				cout << "It's a tie!" << endl;
			else if (Response.compare("rock") != 1 && airesponse == 1) {
				cout << "The ai wins!" << endl;
				p2score++;
			}
			else if (Response.compare("rock") != 1 && airesponse == 2) {
				cout << "You win!" << endl;
				p1score++;
			}
			else if (Response.compare("paper") != 1 && airesponse == 0) {
				cout << "You win!" << endl;
				p1score++;
			}
			else if (Response.compare("paper") != 1 && airesponse == 1)
				cout << "It's a tie!" << endl;
			else if (Response.compare("paper") != 1 && airesponse == 2) {
				cout << "The ai wins!" << endl;
				p2score++;
			}
			else if (Response.compare("scissors") != 1 && airesponse == 0){
				cout << "The ai wins!" << endl;
				p2score++;
		}
			else if (Response.compare("scissors") != 1 && airesponse == 1) {
				cout << "You win!" << endl;
				p1score++;
			}
			else if (Response.compare("scissors") != 1 && airesponse == 2)
				cout << "It's a tie!" << endl;
			cout << "The score is " << p1score << " to " << p2score << ".  Would you like to play again?" << endl;
			getline(cin, Response);
			if (Response.compare("yes") != 1)
				cout << "Ok!" << endl;
			else if (Response.compare("no") != 1) {
				cout << "Seeya later then." << endl;
				rematch = 0;
				return 0;
			}
			}
		}
	