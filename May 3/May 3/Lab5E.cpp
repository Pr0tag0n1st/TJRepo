#include <list>
#include <fstream>
#include <iostream>
using namespace std;

list<int> numberlist;
list<int>::iterator iter;

void read_file();
int list_min(list <int> numbers);
int list_max(list <int> numbers);

int main() {
	read_file();
	system("Pause");
}

void read_file() {
	ifstream filein;
	int tempnum;
	filein.open("Numbers.txt");
	for (int i = 0; i < 24; i++) {
		filein >> tempnum;
		numberlist.push_back(tempnum);
	}
	cout << "The minimum value in numbers.txt is: " << list_min(numberlist) << endl;
	cout << "The minimum value in numbers.txt is: " << list_max(numberlist) << endl;
}

int list_min(list <int> numbers) {
	int tempnum;
	int minnum = *numberlist.begin();
	for (iter = numberlist.begin(); iter != numberlist.end(); iter++) {
		tempnum = *iter;
		if (tempnum < minnum) {
			minnum = tempnum;
		}
	}
	return minnum;
}

int list_max(list <int> numbers) {
	int tempnum;
	int maxnum = *numberlist.begin();
	for (iter = numberlist.begin(); iter != numberlist.end(); iter++) {
		tempnum = *iter;
		if (tempnum > maxnum) {
			maxnum = tempnum;
		}
	}
	return maxnum;
}