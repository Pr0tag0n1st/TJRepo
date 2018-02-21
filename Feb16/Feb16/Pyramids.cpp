#include <iostream>
using namespace std;
#include <string>
int main() {
	int size;
	int slope = 0;
	cout << "Give me the height of a pyramid." << endl;
	cin >> size;
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i + slope; j++) {
			cout << "*";
		}
		cout << endl;
		slope += 1;
	}

	system("Pause");
}