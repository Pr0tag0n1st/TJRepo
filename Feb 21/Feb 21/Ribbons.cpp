#include <iostream>
using namespace std;
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
int main() {
	al_init();
	al_init_primitives_addon();
	struct Points {
		float x, y;
		float blank;
	};
	Points points[5] = { {50, 50, 0}, {100, 100, 0}, {50, 150, 0}, {150, 150, 0}, {200, 200, 0} };
	ALLEGRO_DISPLAY*display = al_create_display(500, 500);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_ribbon((float*)points, 5, al_map_rgb(255, 255, 255), 10, 5);
	al_flip_display();
	al_rest(3.0);
	al_destroy_display(display);
}