#include <ctime>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
int knockBack(int D, int w, int p, double s, int b, double r);
class SmashBros {
public:
	void initCharacter(string name, int percent, int lives);
	void printCharacter();
	void loseStock(int knockback, int lives);
private:
	string CharacterName;
	int damage;
	int stocks;
	int atk;
};
int main() {

	string CharacterChoice;
	srand(time(NULL));
	int startpercent = rand() % 100;
	int startingstocks = rand() % 2 + 1;
	int atkdamage = rand() % 20 + 2;
	int weight = rand() % 59 + 55;
	SmashBros player1;
	SmashBros player2;
	SmashBros player3;
	SmashBros player4;
	cout << "Welcome to a completely nonexistant version of Super Smash Brothers!" << endl;
	cout << "Choose your character (even if they're not technically in the game)!" << endl;
	getline(cin, CharacterChoice);

	player1.initCharacter(CharacterChoice, startpercent, startingstocks);
	int kb = knockBack(atkdamage, weight, startpercent, .5, 20, 1);
	cout << "knockback is " << kb << endl;
	player1.loseStock(kb, startingstocks);
	//system("pause");
	player1.printCharacter();
	//system("Pause");

	cout << "Choose your character, player 2!" << endl;
	getline(cin, CharacterChoice);
	startpercent = rand() % 100;
	startingstocks = rand() % 2 + 1;
	atkdamage = rand() % 20 + 2;
	weight = rand() % 59 + 55;
	player2.initCharacter(CharacterChoice, startpercent, startingstocks);
	kb = knockBack(atkdamage, weight, startpercent, .5, 20, 1);
	cout << "knockback is " << kb << endl;
	player2.loseStock(kb, startingstocks);
	//system("pause");
	player2.printCharacter();
	//system("Pause");
	cout << "Choose your character player 3!" << endl;
	getline(cin, CharacterChoice);
	startpercent = rand() % 100;
	startingstocks = rand() % 2 + 1;
	atkdamage = rand() % 20 + 2;
	weight = rand() % 59 + 55;
	player2.initCharacter(CharacterChoice, startpercent, startingstocks);
	kb = knockBack(atkdamage, weight, startpercent, .5, 20, 1);
	cout << "knockback is " << kb << endl;
	player2.loseStock(kb, startingstocks);
	//system("pause");
	player2.printCharacter();
	//system("Pause");
	cout << "Choose your character player 3!" << endl;
	getline(cin, CharacterChoice);
	startpercent = rand() % 100;
	startingstocks = rand() % 2 + 1;
	atkdamage = rand() % 20 + 2;
	weight = rand() % 59 + 55;
	player3.initCharacter(CharacterChoice, startpercent, startingstocks);
	kb = knockBack(atkdamage, weight, startpercent, .5, 20, 1);
	cout << "knockback is " << kb << endl;
	player3.loseStock(kb, startingstocks);
	//system("pause");
	player3.printCharacter();
	//system("Pause");
	cout << "Choose your character player 4!" << endl;
	getline(cin, CharacterChoice);
	startpercent = rand() % 100;
	startingstocks = rand() % 2 + 1;
	atkdamage = rand() % 20 + 2;
	weight = rand() % 59 + 55;
	player4.initCharacter(CharacterChoice, startpercent, startingstocks);
	kb = knockBack(atkdamage, weight, startpercent, .5, 20, 1);
	cout << "knockback is " << kb << endl;
	player4.loseStock(kb, startingstocks);
	//system("pause");
	player4.printCharacter();
	//system("Pause");
}
void SmashBros::initCharacter(string name, int percent, int lives) {
	CharacterName = name;
	damage = percent;
	stocks = lives;
	cout << "Your character is: " << CharacterName << ", their damage is " << damage << " %, and their stocks are " << stocks << "." << endl;
}
void SmashBros::printCharacter() {
	cout << "After the hit, " << CharacterName << " is at " << damage << " %, and their remaining stocks are " << stocks << "." << endl;
}
int knockBack(int D, int w, int p, double s, int b, double r) {
	int num;
	num = ((((7 * (D + 2)*(D + p) / (w + 100)) + 9) * 2 * s) + b)*r;
	cout << "knockback is calculated to be " << num << endl;
	return num;
}
void SmashBros::loseStock(int knockback, int lives) {
	stocks = lives;
	atk = knockback / 3;
	if (knockback > 75) {
		stocks--;
		damage = 0;

	}
	else {
		damage = damage + atk;
	}
}

