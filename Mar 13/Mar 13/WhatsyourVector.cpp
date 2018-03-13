#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int input;
	vector<int> Victor;
	vector<int>::iterator iter;
	cout << "Give me a number other than 0:" << endl;
	cin >> input;
	Victor.push_back(input);
	while (input != 0) {
		cout << "Another one:" << endl;
		cin >> input;
		Victor.push_back(input);
	}
	cout << "Here are your numbers:" << endl;
	for (iter = Victor.begin(); iter != Victor.end(); ++iter)
		cout << *iter << endl;
	sort(Victor.begin(), Victor.end());
	cout << "In order, they are:" << endl;
	for (iter = Victor.begin(); iter != Victor.end(); ++iter)
		cout << *iter << endl;
	system("Pause");
}