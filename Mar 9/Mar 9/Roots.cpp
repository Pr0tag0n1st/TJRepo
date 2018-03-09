#include <iostream>
using namespace std;
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
class Vegetable {
public:
	void drawVegetable(ALLEGRO_BITMAP*image);
	void printVegetable();
private:
	int x_pos;
	int y_pos;
	int angle;
	
};
class Potato :public Vegetable {
public:
	void initPotato(int x, int y, int degree);
private:
};
class Radish :public Vegetable {
public:
	void initRadish(int x, int y, int degree);
};
int main() {
	srand(time(NULL));
	al_init();
	al_init_image_addon();
	int rand_x = rand() % 1200;
	int rand_y = rand() % 800;
	int rand_angle = rand() % 360;
	ALLEGRO_DISPLAY *display = al_create_display(1200, 800);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	ALLEGRO_BITMAP*potato = al_load_bitmap("potato.jfif");
	ALLEGRO_BITMAP*radish = al_load_bitmap("radish.jfif");
	Potato p1;
	Potato p2;
	Radish r1;
	Radish r2;
	while (1);
	{
		p1.initPotato(rand_x, rand_y, rand_angle);
		p2.initPotato(rand_x, rand_y, rand_angle);
		r1.initRadish(rand_x, rand_y, rand_angle);
		r2.initRadish(rand_x, rand_y, rand_angle);
		p1.drawVegetable(potato);
		p2.drawVegetable(potato);
		r1.drawVegetable(radish);
		r2.drawVegetable(radish);
		al_flip_display();
	}
}
void Potato::initPotato(int x, int y, int degree) {
	//error here, says "Vegetable:variable" is inaccessible
	x_pos = x;
	y_pos = y;
	angle = degree;
}
void Radish::initRadish(int x, int y, int degree) {
	x_pos = x;
	y_pos = y;
	angle = degree;
}
void Vegetable::drawVegetable(ALLEGRO_BITMAP*image) {
	al_draw_rotated_bitmap(image, x_pos, y_pos, 100, 100, angle, 0);
}