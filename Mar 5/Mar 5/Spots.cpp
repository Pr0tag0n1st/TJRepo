#include <iostream>
using namespace std;
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
class spot {
private:
	int x_pos;
	int y_pos;
	int r;
	int red;
	int blue;
	int green;

public:
	void initspot(int x, int y, int radius, int color1, int color2, int color3);
};
int main() {
	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY *display = al_create_display(1200, 800);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	spot spot1;
	spot spot2;
	spot spot3;
	spot spot4;
	spot spot5;
	spot1.initspot(200, 300, 50, 255, 100, 100);
	spot2.initspot(500, 500, 75, 100, 255, 100);
	spot3.initspot(900, 700, 100, 100, 100, 255);
	spot4.initspot(200, 600, 125, 255, 255, 255);
	spot5.initspot(900, 200, 25, 100, 100, 100);

	al_flip_display();
	al_rest(3.0);
}
void spot::initspot(int x, int y, int radius, int color1, int color2, int color3) {
	al_draw_filled_circle(x, y, radius, al_map_rgb(color1, color2, color3));
}