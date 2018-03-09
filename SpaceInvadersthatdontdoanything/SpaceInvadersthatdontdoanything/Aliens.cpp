#include <iostream>
using namespace std;
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
class aliens {
public:
	void InitInvader(int x, int y, int hp);
	void DrawInvader(ALLEGRO_BITMAP *image);
	void print();
private:
	int x_pos;
	int y_pos;
	int health;
};


int main() {
	al_init();
	al_init_image_addon();
	ALLEGRO_DISPLAY*display = al_create_display(1200, 800);
	ALLEGRO_BITMAP*alien = al_load_bitmap("ufo.png");
	al_set_target_backbuffer(display);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	aliens alien1;
	aliens alien2;
	aliens alien3;
	aliens alien4;
	alien1.InitInvader(50, 50, 50);
	alien2.InitInvader(200, 50, 50);
	alien3.InitInvader(350, 50, 50);
	alien4.InitInvader(500, 50, 50);
	alien1.DrawInvader(alien);
	alien2.DrawInvader(alien);
	alien3.DrawInvader(alien);
	alien4.DrawInvader(alien);
	alien1.print();
	alien2.print();
	alien3.print();
	alien4.print();
	al_flip_display();
	al_rest(5.0);
}
void aliens::InitInvader(int x, int y, int hp) {
	x_pos = x;
	y_pos = y;
	health = hp;
}
void aliens::DrawInvader(ALLEGRO_BITMAP *image) {
	al_draw_bitmap(image, x_pos, y_pos, 0);
}
void aliens::print() {
	cout << "X pos:" << x_pos << " Y pos:" << y_pos << " hp:" << health << endl;
}