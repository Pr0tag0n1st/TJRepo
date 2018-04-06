#include <iostream>
using namespace std;
#include <string>
#include <vector>
class KIDS {
public:
	void studentInit(int ID, int Age, string Gender, string LName);
	void studentPrint();

private:
	int id;
	int age;
	string gender;
	string lname;
};


int main() {
	vector<KIDS> classlist;
	vector<KIDS>::iterator roll;
	KIDS kid1;
	KIDS kid2;
	KIDS kid3;
	KIDS kid4;
	KIDS kid5;

	kid1.studentInit(771180, 16, "MALE", "Cochran");
	kid2.studentInit(666793, 16, "MALE", "Gonzales");
	kid3.studentInit(667665, 16, "MALE", "Unfug");
	kid4.studentInit(680342, 17, "MALE", "Young");
	kid5.studentInit(665825, 16, "MALE", "Martinez");
	classlist.push_back(kid1);
	classlist.push_back(kid2);
	classlist.push_back(kid3);
	classlist.push_back(kid4);
	classlist.push_back(kid5);
	for (roll = classlist.begin(); roll != classlist.end(); roll++) {
		roll->studentPrint();
	}
	system("Pause");
}
void KIDS::studentInit(int ID, int Age, string Gender, string LName) {
	id = ID;
	age = Age;
	gender = Gender;
	lname = LName;
}
void KIDS::studentPrint() {
	cout << lname << " is ID# " << id << ", " << age << " years old, and identifies as " << gender << "." << endl;
}