#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
	//Project variables
	ifstream readfile;
	ofstream writefile;
	int cases;
	int lines;
	char character;
	string namein;
	string nameout;


	//Textfile being read from
	readfile.open("Prob06.in.txt");
	readfile >> cases;
	writefile.open("Prob06.out.txt");

	//Cases loop
	for (int i = 0; i < cases; i++) {
		namein.clear();
		nameout.clear();
		readfile >> lines;

		//Lines per case loop
		for (int j = 0; j < lines; j++) {
			namein.clear();
			nameout.clear();
			//readfile >> namein; //try getline() here instead
			getline(readfile, namein);
			if (j == 0)
				getline(readfile, namein);

			cout << namein << endl;

			//String character replacement
			for (string::iterator it = namein.begin(); it != namein.end(); it++) {
				character = *it;
				switch (character) {
				case 'A':
					nameout += "Alpha-";
					break;
				case 'a':
					nameout += "Alpha-";
					break;
				case 'B':
					nameout += "Beta-";
					break;
				case 'b':
					nameout += "Beta-";
					break;
				case 'C':
					nameout += "Charlie-";
					break;
				case 'c':
					nameout += "Charlie-";
					break;
				case 'D':
					nameout += "Delta-";
					break;
				case 'd':
					nameout += "Delta-";
					break;
				case 'E':
					nameout += "Echo-";
					break;
				case 'e':
					nameout += "Echo-";
					break;
				case 'F':
					nameout += "Foxtrot-";
					break;
				case 'f':
					nameout += "Foxtrot-";
					break;
				case 'G':
					nameout += "Golf-";
					break;
				case 'g':
					nameout += "Golf-";
					break;
				case 'H':
					nameout += "Hotel-";
					break;
				case 'h':
					nameout += "Hotel-";
					break;
				case 'I':
					nameout += "India-";
					break;
				case 'i':
					nameout += "India-";
					break;
				case 'J':
					nameout += "Juliet-";
					break;
				case 'j':
					nameout += "Juliet-";
					break;
				case 'K':
					nameout += "Kilo-";
					break;
				case 'k':
					nameout += "Kilo-";
					break;
				case 'L':
					nameout += "Lima-";
					break;
				case 'l':
					nameout += "Lima-";
					break;
				case 'M':
					nameout += "Mike-";
					break;
				case 'm':
					nameout += "Mike-";
					break;
				case 'N':
					nameout += "November-";
					break;
				case 'n':
					nameout += "November-";
					break;
				case 'O':
					nameout += "Oscar-";
					break;
				case 'o':
					nameout += "Oscar-";
					break;
				case 'P':
					nameout += "Papa-";
					break;
				case 'p':
					nameout += "Papa-";
					break;
				case 'Q':
					nameout += "Quebec-";
					break;
				case 'q':
					nameout += "Quebec-";
					break;
				case 'R':
					nameout += "Romeo-";
					break;
				case 'r':
					nameout += "Romeo-";
					break;
				case 'S':
					nameout += "Sierra-";
					break;
				case 's':
					nameout += "Sierra-";
					break;
				case 'T':
					nameout += "Tango-";
					break;
				case 't':
					nameout += "Tango-";
					break;
				case 'U':
					nameout += "Uniform-";
					break;
				case 'u':
					nameout += "Uniform-";
					break;
				case 'V':
					nameout += "Victor-";
					break;
				case 'v':
					nameout += "Victor-";
					break;
				case 'W':
					nameout += "Whiskey-";
					break;
				case 'w':
					nameout += "Whiskey-";
					break;
				case 'X':
					nameout += "Xray-";
					break;
				case 'x':
					nameout += "Xray-";
					break;
				case 'Y':
					nameout += "Yankee-";
					break;
				case 'y':
					nameout += "Yankee-";
					break;
				case 'Z':
					nameout += "Zulu-";
					break;
				case 'z':
					nameout += "Zulu-";
					break;
				case ' ':
					nameout += " ";
					break;
				}
					
				
			}
			cout << nameout << endl;
			writefile << nameout << endl;
			system("Pause");
		}

	}


}