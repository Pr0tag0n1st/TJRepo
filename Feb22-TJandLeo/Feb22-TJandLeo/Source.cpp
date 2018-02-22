#include<iostream>
using namespace std;
int main() {
	long  bin, dec = 0, rem, base = 1;
	cout << "enter a binary number in 0 and 1s" << endl;
	cin >> bin;
	while (bin > 0) {
		rem = bin % 10;
		bin = bin / 10;
		dec = dec + rem * base;
		base = base * 2;
	}
	cout << dec << endl;
	system("pause");
}