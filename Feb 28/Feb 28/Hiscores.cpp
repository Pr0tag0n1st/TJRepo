#include <iostream>
#include<fstream>

using namespace std;
//made by Deven and TJ
int main() {
	ofstream scores;
	ifstream read("scores.txt");
	double allscores[6];
	double top5[6];
	double n;
	double temp;
	double newscore;

	if (read.is_open())
	{
		for (int i = 0; i < 6; i++)
		{

			read >> n;
			allscores[i] = n;


		}

		read.close();


	}
	cin >> newscore;
	for (int i = 0; i < 6; i++)
		if (allscores[i] < newscore) {
			temp = allscores[i];
			top5[i] = newscore;
			newscore = temp;
		}
		else top5[i] = allscores[i];

		cout << "Top scores are:" << endl;
		for (int i = 0; i < 5; i++)
			cout << top5[i] << endl;
		scores.open("scores.txt");
		for (int i = 0; i < 6; i++)
			scores << top5[i] << endl;

		system("Pause");
}
