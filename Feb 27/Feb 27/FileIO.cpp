#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int input;
	cin >> input;
	ofstream Bob;
	Bob.open("Prob01.in.txt");
	Bob << "Fernyyy The Mannnnn" << endl;
	Bob << "Tjjjjjjjj The Boiiii";
	Bob.close();

	string line;
	ifstream Bob1("Prob01.in.txt");
	if (Bob1.is_open()) {
		while (getline(Bob1, line)) {
			for (int i = 0; i < input; i++) {
				cout << line << endl;
			}
		}
		Bob1.close();
	}
	else
		cout << "Unable to open" << endl;

	system("pause");
}