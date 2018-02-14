#include <ctime>
#include <string>
#include <iostream>
using namespace std;
int main() {
	string input={ "yeah" };
	string adjectives[20]{ "Little", "Big", "Young", "Ice", "Lil'", "Biggy", "Thug", "Notorious", "Extra", "2", "The Rapper", "Wiz", "50", "Dr.", "Ol'", "Flo", "Chance", "Critical", "Street", "Thunder"};
	string nouns[20]{ "Tim", "John", "Money", "Cube", "Falcon", "Drake", "Chainz", "Dawg", "Khalifa", "Cent", "Rida", "Panda", "Lamp", "Dre", "Man", "Boy", "Smalls", "Tupac", "Fire", "Deja Vu" };
	srand(time(NULL));
	cout << "YO!!!  I've got some sweet names for you!  Check this out!" << endl;
	while (input.compare("yeah") != 1) {
		int slot1 = rand() % 20;
		int slot2 = rand() % 20;
		cout << "Your new name is " << adjectives[slot1] << " " << nouns[slot2] << "!" << endl;
		cout << "Another one? (yeah/nah)" << endl;
		getline(cin, input);
		if (input.compare("nah") != 1)
			return 0;
	}

}
