#include <iostream>
using namespace std;
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
class Vegetable {
public:
	void drawVegetable(ALLEGRO_BITMAP*image);
protected:
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

	ALLEGRO_DISPLAY *display = al_create_display(1200, 800);
	cout << "flag1" << endl;
	al_clear_to_color(al_map_rgb(255, 255, 255));
	ALLEGRO_BITMAP*potato = al_load_bitmap("potato.jpg");
	ALLEGRO_BITMAP*radish = al_load_bitmap("radish.jpg");
	Potato p1;
	Potato p2;
	Radish r1;
	Radish r2;
	cout << "flag2" << endl;
	while (1){
		int p1rand_x = rand() % 1200;
		int	p1rand_y = rand() % 800;
		int p1rand_angle = rand() % 360;
		int p2rand_x = rand() % 1200;
		int	p2rand_y = rand() % 800;
		int p2rand_angle = rand() % 360;
		int r1rand_x = rand() % 1200;
		int	r1rand_y = rand() % 800;
		int r1rand_angle = rand() % 360;
		int r2rand_x = rand() % 1200;
		int	r2rand_y = rand() % 800;
		int r2rand_angle = rand() % 360;
		p1.initPotato(p1rand_x, p1rand_y, p1rand_angle);
		p2.initPotato(p2rand_x, p2rand_y, p2rand_angle);
		r1.initRadish(r1rand_x, r1rand_y, r1rand_angle);
		r2.initRadish(r2rand_x, r2rand_y, r2rand_angle);
		cout << "flag3" << endl;
		p1.drawVegetable(potato);
		p2.drawVegetable(potato);
		r1.drawVegetable(radish);
		r2.drawVegetable(radish);
		al_flip_display();
		al_rest(0.25);
	}
}
void Potato::initPotato(int x, int y, int degree) {

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