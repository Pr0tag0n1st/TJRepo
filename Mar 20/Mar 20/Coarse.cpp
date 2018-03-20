#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main() {
	int testruns;
	int teams;
	float count = 0;
	float tempcount;
	float sum = 0;
	ofstream writefile;
	ifstream readfile;
	readfile.open("Rough.txt");
	readfile >> testruns;
	cout << testruns << endl;
	readfile >> teams;
	cout << teams << endl;
	cout << "flag1" << endl;
	for (int i = 0; i < testruns; i++) {
		tempcount = 0;
		sum = 0;
		cout << "flag2" << endl;
		for (int i = 0; i < teams; i++) {
			readfile >> tempcount;
			cout << tempcount << endl;
			sum = tempcount + count;
			count = sum;
			cout << count << endl;
		}
		
	}
	
	writefile.open("Everywhere.txt");
	writefile <<setprecision(0)<<fixed<< count;
	readfile.close();
	cout << "The teams together have counted " <<setprecision(0)<< fixed<< count << " grains of sand." << endl;
	system("Pause");
}