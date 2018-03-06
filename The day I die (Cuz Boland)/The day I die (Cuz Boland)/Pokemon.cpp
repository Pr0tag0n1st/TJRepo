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


	cout << "Desert = d"<< endl;
	cout << "Forest = f"<< endl;
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
	pokemon1.printinfo();
	cout << "Turtwig's:" << endl;
	pokemon2.initPokemon(30, 387);
	pokemon2.foodeat(food);
	pokemon2.printinfo();
	cout << "Charmander:" << endl;
	pokemon3.initPokemon(20, 4);
	pokemon3.foodeat(food);
	pokemon3.printinfo();
	cout << "Munchlax:" << endl;
	pokemon4.initPokemon(50, 446);
	pokemon4.foodeat(food);
	pokemon4.printinfo();
	system("Pause");
	//pokemon5.initPokemon("Squirtle", 25, 7, "Water", "Water");
	//pokemon6.initPokemon("Squirtle", 25, 7, "Water", "Water");
	//pokemon7.initPokemon("Squirtle", 25, 7, "Water", "Water");
	//pokemon8.initPokemon("Squirtle", 25, 7, "Water", "Water");
	//pokemon9.initPokemon("Squirtle", 25, 7, "Water", "Water");
	//pokemon10.initPokemon("Squirtle", 25, 7, "Water", "Water");
}

void Pokemon::foodeat(char foodType) {
	if (foodType == 'm')
		health += 3;
	else if (foodType == 'b')
		health += 10;
	else if (foodType == 'f')
		health += 5;
	else if (foodType == 'c')
		health += 7;
	
}

void Pokemon::initPokemon(int health, int index) {
	hp = health;
	dexnum = index;

}

void Pokemon::printinfo() {
	cout <<"Health:" << health << "  Dex #:" << index<<"." << endl;
}
char foodDrop(char place) {



	//forest food drop chance
	if (place == 'f') {
		int map = rand() % 2 + 1;
		if (map == 1)
			return 'm';
		else
			return 'b';
	}

	//desert food drop chance
	if (place == 'd') {
		int map = rand() % 100 + 1;
		if (map < 20)
			return 'b';
		if (map < 60)
			return 'f';
		else
			return 'c';
	}
}