#include <iostream>
using namespace std;
#include <string>

void print_menu();
void religion(int position);
double Celsius(double Fahrenheit);

int main() {
	char input = 'a';
	double numinput;
		print_menu();
	while (input != 'q') {
		cout << "Command: ";
		cin >> input;
		switch (input) {
		case 'h':
			print_menu();
			break;
		case 't':
			cout << "Fahrenheit: ";
			cin >> numinput;
			cout << numinput << " Fahrenheit is " << Celsius(numinput) << " Celsius" << endl;
			break;
		case 'r':
			cout << "Which religion?" << endl;
			cin >> numinput;
			religion(numinput);
			break;
		default:
			cout << "Invalid command" << endl;
		}
	}
	
}

//Prints out instructions again
void print_menu() {
	cout << "Quit: q" << endl;
	cout << "Help: h" << endl;
	cout << "Info about a religion: r" << endl;
	cout << "Temperature conversion: t" << endl;
	
}

//Uses an integer to print a religion according to what spot it occupies in the top 10 religions
void religion(int position) {
	switch (position){
	case 1:
		cout << "Christianity: 31.2%" << endl;
		break;
	case 2:
		cout << "Islam: 24.1%" << endl;
		break;
	case 3:
		cout << "Secular: 16%" << endl;
		break;
	case 4:
		cout << "Hinduism : 15.1%" << endl;
		break;
	case 5:
		cout << "Buddhism: 6.9%" << endl;
		break;
	case 6:
		cout << "Chinese traditional religion: 5.5%" << endl;
		break;
	case 7:
		cout << "Ethnic religions: 4.19%" << endl;
		break;
	case 8:
		cout << "African traditional religions: 1.40%" << endl;
		break;
	case 9:
		cout << "Sikhism: 0.32%" << endl;
		break;
	case 10:
		cout << "Spiritism: 0.21%" << endl;
		break;
	default:
		cout << "Don't know anything about religion #"<<position<<"." << endl;
	}
}

//Converts a value from Fahrenheit to Celsius
double Celsius(double Fahrenheit){
	double newTemp = (Fahrenheit - 32)*5 / 9;
	return newTemp;
}