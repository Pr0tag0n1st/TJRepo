#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main() {
	al_init();
	al_init_primitives_addon();

	ALLEGRO_DISPLAY*display = al_create_display(800, 600);
	bool Doexit = false;
	bool Redraw = true;
	al_set_target_bitmap(al_get_backbuffer(display));
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	while (!Doexit) {

		for (int j = 0; j < 30; j++) {
			al_draw_filled_circle(400, 300, 600 - (j * 25), al_map_rgb(255 +(j*10), 255 + (j*10), 255 + (j*10)));
		}
		for (int i = 0; i < 26; i++) {
			al_draw_filled_rectangle(i * 20, 20 + (i * 10), 20 + (i * 20), 40 + (i * 20), al_map_rgb(5 * i, 20 * i, 10 * i));
			al_draw_filled_rectangle(800 - (i * 20), 580 - (i * 10), 780 - (i * 20), 560 - (i * 20), al_map_rgb(5 * i, 20 * i, 10 * i));
			al_draw_filled_rectangle(800 - (i * 20), 20 + (i * 10), 780 - (i * 20), 40 + (i * 20), al_map_rgb(5 * i, 20 * i, 10 * i));
			al_draw_filled_rectangle(i * 20, 580 - (i * 10), 20 + (i * 20), 560 - (i * 20), al_map_rgb(5 * i, 20 * i, 10 * i));
		}
		for (int x = 0; x < 40; x++) {
			al_draw_filled_rectangle(x * 20, 0, 20 + (x * 20), 20, al_map_rgb(0 + (x * 5), 0, 0));
			al_draw_filled_rectangle(0, x * 20, 20, 20 + (x * 20), al_map_rgb(0 + (x * 7), 0, 0));
			al_draw_filled_rectangle(800, 600 - (x * 20), 780, 560 - (x * 20), al_map_rgb(0 + (x * 7), 0, 0));
			al_draw_filled_rectangle(800 - (x * 20), 600, 780 - (x * 20), 580, al_map_rgb(0 + (x * 5), 0, 0));
		}
		al_flip_display();
	}
}