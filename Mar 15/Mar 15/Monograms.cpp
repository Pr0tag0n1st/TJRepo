#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include <fstream>
int main() {
	string fnames;
	string mnames;
	string lnames;
	string tempname;
	vector<string>FULLNAMES;
	vector<char>MONOGRAMS;
	vector<int> N;
	vector<int>::iterator iterN;
	int input;
	int T;
	ofstream writeout;
	ifstream writein;
	cout << "How many test cases are there?" << endl;
	cin >> input;
	writeout.open("Prob01.in.txt");
	T = input;
	writeout << T << endl;;
	cout << "How many names are in each test case?" << endl;
	for (int i = 0; i < T; i++) {
		cin >> input;
		N.push_back(input);
		writeout << input << endl;

	}
	cout << "What are said names? (Please enter First, Middle, then Last names" << endl;
	for (int i = 0; i < T; i++) {
		for (iterN = N.begin(); iterN != N.end(); iterN++) {
			cout << "First name:" << endl;
			getline(cin, fnames);
			getline(cin, fnames);
			cout << "Middle name:" << endl;
			getline(cin, mnames);
			cout << "Last name:" << endl;
			getline(cin, lnames);
			writeout << fnames << " " << mnames << " " << lnames << endl;
		}
	}
	writeout.close();
	writein.open("Prob01.in.TXT");
	for (int i = 0; i < T; i++) {
		for (iterN = N.begin(); iterN != N.end(); iterN++) {

			FULLNAMES.push_back();
		}
	}
	cout << "That leaves the names as:" << endl;
	for (int i = 0; i < T; i++) {
		for (iterN = N.begin(); iterN != N.end(); iterN++) {
			cout << *iterN << endl;
		}

	}
	system("Pause");
}