#include <iostream>
using namespace std;
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main() {
	int screenw = 800;
	int screenh = 600;
	srand(time(NULL));
	int red = rand() % 255;
	int green = rand() % 255;
	int blue = rand() % 255;
	bool redraw = true;
	al_init();
	al_init_primitives_addon();
	double bouncer_x = 0;
	double bouncer_y = 0;
	ALLEGRO_DISPLAY*display = al_create_display(screenw, screenh);
	ALLEGRO_EVENT_QUEUE*event_queue = al_create_event_queue();
	ALLEGRO_TIMER*timer = al_create_timer(1.0 / 60);
	ALLEGRO_BITMAP*bouncer = al_create_bitmap(32, 32);
	al_install_mouse();
	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_set_target_bitmap(al_get_backbuffer(display));
	al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);

	while (1) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			bouncer_x = ev.mouse.x;
			bouncer_y = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			red = rand() % 255;
			green = rand() % 255;
			blue = rand() % 255;
			if (bouncer_x < screenw / 2 && bouncer_y > screenh / 2) {
				al_draw_filled_rectangle(0, screenh / 2, screenw / 2, screenh, (al_map_rgb(red, green, blue)));
			}
			else if (bouncer_x < screenw / 2 && bouncer_y < screenh / 2) {
				al_draw_filled_rectangle(0, 0, screenw / 2, screenh / 2, (al_map_rgb(red, green, blue)));
			}
			else if (bouncer_x > screenw / 2 && bouncer_y < screenh / 2) {
				al_draw_filled_rectangle(screenw / 2, screenh/2, screenw, 0, (al_map_rgb(red, green, blue)));
			}
			else if (bouncer_x > screenw / 2 && bouncer_y > screenh / 2) {
				al_draw_filled_rectangle(screenw / 2, screenh / 2, screenw, screenh, (al_map_rgb(red, green, blue)));
			}

		}
		//else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		//	break;
		//}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_flip_display();
		}
	}
	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;

}