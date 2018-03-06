#include <iostream>
#include <string>
using namespace std;
char foodDrop(char place);
class Pokemon {
private:

	int health;
	int index;
	int hp;
	int dexnum;
public:
	 void foodeat(char foodType);
	 void initPokemon(int health, int index);
	 void printinfo();

};

int main() {
	char place;
	while (1) {

		cout << "Desert = d" << endl;
		cout << "Forest = f" << endl;
		system("pause");

		cout << "Where is your pokemon looking for food?" << endl;
		cin >> place;
		char food = foodDrop(place);
		string species;
		Pokemon pokemon1;
		Pokemon pokemon2;
		Pokemon pokemon3;
		Pokemon pokemon4;
		cout << "Here's Squirtle's health and pokedex number." << endl;
		pokemon1.initPokemon(25, 7);
		pokemon1.foodeat(food);
		cout << "After feeding:" << endl;
		pokemon1.printinfo();
		cout << "Turtwig's:" << endl;
		pokemon2.initPokemon(30, 387);
		pokemon2.foodeat(food);
		cout << "After feeding:" << endl;
		pokemon2.printinfo();
		cout << "Charmander:" << endl;
		pokemon3.initPokemon(20, 4);
		pokemon3.foodeat(food);
		cout << "After feeding:" << endl;
		pokemon3.printinfo();
		cout << "Munchlax:" << endl;
		pokemon4.initPokemon(50, 446);
		pokemon4.foodeat(food);
		cout << "After feeding:" << endl;
		pokemon4.printinfo();
		system("Pause");
	}
}

void Pokemon::foodeat(char foodType) {
	if (foodType == 'm')
		hp += 3;
	else if (foodType == 'b')
		hp += 10;
	else if (foodType == 'f')
		hp += 5;
	else if (foodType == 'c')
		hp += 7;
	
}

void Pokemon::initPokemon(int health, int index) {
	hp = health;
	dexnum = index;
	cout << "Health:" << health << "  Dex #:" << index << "." << endl;
}

void Pokemon::printinfo() {
	cout <<"Health:" << hp << "  Dex #:" << dexnum<<"." << endl;
}
char foodDrop(char place) {



	//forest food drop chance
	if (place == 'f') {
		int map = rand() % 2 + 1;
		if (map == 1) {
			cout << "found a mushroom!";
			return 'm';
		}
		else {
			cout << "found a berry!";
			return 'b';
		}
	}

	//desert food drop chance
	if (place == 'd') {
		int map = rand() % 100 + 1;
		if (map < 20) {
			cout << "found a berry";
			return 'b';
		}
		if (map < 60) {
			return 'f';
			cout << "found a fruit!" << endl;
		}
		else {
			cout << "found cheese!" << endl;
			return 'c';
		}
	}
}