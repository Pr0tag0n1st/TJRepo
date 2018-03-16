#include <vector>
#include <iostream>
using namespace std;
#include <fstream>
int main() {
	int temp;
	int temp2;
	int T;
	vector<int>add;
	vector<int>multiply;
	vector<int>num1;
	vector<int>num2;
	vector<int>::iterator iter1;
	vector<int>::iterator iter2;
	ofstream writefile;
	ifstream readfile;
	cout << "How many test cases are there?" << endl;
	cin >> temp;
	writefile.open("Prob03.in");
	writefile << temp << endl;
	readfile.open("Prob03.in");
	readfile >> T;
	cout << "Now give me pairs of numbers to add and multiply." << endl;
	for (int i = 0; i < T; i++) {
		cin >> temp;
		num1.push_back(temp);
		cin >> temp;
		num2.push_back(temp);
	}
	for (iter1 = num1.begin(); iter1 != num1.end(); iter1++) {
		cout << *iter1 << " ";
		writefile << *iter1 << " ";
	}
	for (iter2 = num2.begin(); iter2 != num2.end(); iter2++) {
		cout << *iter2 << endl;
		writefile << *iter2 << endl;
	}
	for (int i = 0; i < T; i++) {
		readfile >> temp;
		readfile >> temp2;
		add.push_back(temp + temp2);
		multiply.push_back(temp*temp2);
	}
	cout << "Here are your results:" << endl;
	for (iter1 = add.begin(); iter1 != add.end(); iter1++) {
		cout << *iter1 << " ";
		writefile << *iter1 << " ";
	}
	for (iter2 = multiply.begin(); iter2 != multiply.end(); iter2++) {
		cout << *iter2 << " ";
		writefile << *iter2 << " " << endl;
	}
	system("Pause");

}