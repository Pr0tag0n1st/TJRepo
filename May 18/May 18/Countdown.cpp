#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include<allegro5/allegro_primitives.h>
#include <iostream>
#include <ctime>
using namespace std;
const float FPS = 10;
int main() {
	srand(time(NULL));
	int character = rand() % 36;
	char possible[36] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char randcode[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char passcode[10] = { 'X', 'Y', '7', 'O', '2', 'Q', 'T', '5', 'D', '0' };
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	bool Doexit = false;
	bool Redraw = true;
	ALLEGRO_DISPLAY* display = al_create_display(640, 480);
	ALLEGRO_FONT* font = al_load_font("heav.ttf", 48, 0);
	if (font == NULL) {
		cout << "Things broke" << endl;
	}
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	al_set_target_bitmap(al_get_backbuffer(display));
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_flip_display();
	al_start_timer(timer);
	while (!Doexit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		cout << "Game loop started" << endl;
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			Redraw = true;
			cout << "Timer section" << endl;

			for (int i = 0; i < 10; i++) {
				character = rand() % 36;
				if (randcode[i] != passcode[i])
					randcode[i] = possible[character];
				else
					randcode[i] = passcode[i];
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			cout << "Window closed" << endl;
			Doexit = true;
		}
		if (Redraw == true && al_is_event_queue_empty(event_queue)) {
			cout << "Render section" << endl;
			Redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			for (int i = 0; i < 10; i++) {
				cout << randcode[i] << endl;
				al_draw_textf(font, al_map_rgb(255, 255, 255), (i * 48)+10, 240, 0, "%c", randcode[i]);
			}
			//al_draw_filled_rectangle(300, 300, 500, 500, al_map_rgb(200, 50, 100));
			al_flip_display();
		}
		
	}
	al_destroy_font(font);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);

}