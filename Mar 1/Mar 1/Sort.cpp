#include <fstream>
#include <iostream>
using namespace std;
int temp;
int temp2;
int numbers[10];
int order[10];
int main() {
	ofstream input;
	input.open("numbers.txt");
	input << 78 << endl;
	input << 2 << endl;
	input << 50 << endl;
	input << 60 << endl;
	input << 25 << endl;
	input << 19 << endl;
	input << 33 << endl;
	input << 47 << endl;
	input << 95 << endl;
	input << 87 << endl;
	input.close();
	ifstream sort;
	sort.open("numbers.txt");
	if (sort.is_open()) {
		for (int i = 0; i < 10; i++) {
			sort >> temp;
			numbers[i] = temp;
		}
		sort.close();
	}

	else cout << "Error" << endl;
	for (int i = 0; i < 10; i++)
		cout << numbers[i] << endl;

		for (int i = 0; i < 10; i++)
			if (numbers[i] < temp) {
				temp = numbers[i];
				order[i] = temp;

			}
		//temp = allscores[i];
		//top5[i] = newscore;
		//newscore = temp;
			cout << "The order is:" << endl;
			for (int i = 0; i < 10; i++)
				cout << order[i] << endl;
	system("pause");
}
//#include <iostream>
//#include<fstream>
//using namespace std;
////made by Deven and TJ
//int main() {
//	ofstream scores;
//	ifstream read("scores.txt");
//	double allscores[6];
//	double top5[6];
//	double n;
//	double temp;
//	double newscore;
//	if (read.is_open())
//	{
//		for (int i = 0; i < 6; i++)
//		{
//			read >> n;
//			allscores[i] = n;
//		}
//		read.close();
//	}
//	cin >> newscore;
//	for (int i = 0; i < 6; i++)
//		if (allscores[i] < newscore) {
//			

//		}
//		else top5[i] = allscores[i];
//
//		cout << "Top scores are:" << endl;
//		for (int i = 0; i < 5; i++)
//			cout << top5[i] << endl;
//		scores.open("scores.txt");
//		for (int i = 0; i < 6; i++)
//			scores << top5[i] << endl;
//
//		system("Pause");
//}
