#include <iostream>
#include <fstream>
using namespace std;
int main() {
	int iterms;
	int lastline;
	system("color 22");
	long sum;
	ofstream writefile;
	ifstream readfile;
	cout << "How many terms do you need in the Fibonacci sequence?" << endl;
	writefile.open("Fibonaccisolution");
	readfile.open("Fibonacci");
	readfile >> iterms;
	cout << iterms << endl;
//	system("Pause");
	for (int i = 0; i < iterms; i++) {
//		system("Pause");
		long temp1 = 0;
		long temp2 = 1;
		readfile >> lastline;
		//system("Pause");
		for (int j = 0; j < lastline; j++) {
			if (lastline == 1){
				writefile << "0" << endl;
				break;
			}

			sum = temp1 + temp2;
			temp1 = temp2;
			temp2 = sum;
			cout << sum;
	//		system("pause");
		}
			writefile << temp2 << endl;
	}
		
}