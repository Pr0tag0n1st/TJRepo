#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <ctime>
int main() {
	al_init();
	al_init_primitives_addon();
	srand(time(NULL));

	ALLEGRO_DISPLAY*display = al_create_display(800, 600);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	while(1){
		int cx = rand() % 800 + 1;
		int cy = rand() % 600 + 1;
		int r = rand() % 500 + 1;
		int red = rand() % 256;
		int blue = rand() % 256;
		int green = rand() % 256;
		int t = rand() % 10;
		al_draw_circle(cx, cy, r, al_map_rgb(red, green, blue), t);
		al_flip_display();
	}
} 