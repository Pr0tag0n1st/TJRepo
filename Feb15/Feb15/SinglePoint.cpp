//made by TJ and Ferny
#include <allegro5/allegro.h>
#include <iostream>
using namespace std;
bool Collision(int x1, int y1, int x2, int y2);
int main() {
	int pixel1_x = 20;
	int pixel1_y = 20;
	int pixel2_x = 80;
	int pixel2_y = 80;
	int screensize = 100;
	bool redraw;
	bool doexit = false;
	bool p1keys[4]{ false, false, false, false };
	bool p2keys[4]{ false, false, false, false };
	al_init();
	al_install_keyboard();
	ALLEGRO_DISPLAY*display = al_create_display(screensize, screensize);
	ALLEGRO_BITMAP*pixel1 = al_create_bitmap(1, 1);
	ALLEGRO_BITMAP*pixel2 = al_create_bitmap(1, 1);
	ALLEGRO_EVENT_QUEUE*event_queue = al_create_event_queue();
	ALLEGRO_TIMER*timer = al_create_timer(0.02);
	al_set_target_bitmap(pixel1);
	al_clear_to_color(al_map_rgb(255, 200, 200));
	al_set_target_bitmap(pixel2);
	al_clear_to_color(al_map_rgb(200, 200, 255));
	al_set_target_backbuffer(display);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_start_timer(timer);
	al_flip_display();

	while (!doexit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (p1keys[0] == true && pixel1_y > 0)
				pixel1_y -= 1;
			if (p1keys[1] == true && pixel1_y < 100)
				pixel1_y += 1;
			if (p1keys[2] == true && pixel1_x > 0)
				pixel1_x -= 1;
			if (p1keys[3] == true && pixel1_x < 100)
				pixel1_x += 1;
			if (p2keys[0] == true && pixel2_y > 0)
				pixel2_y -= 1;
			if (p2keys[1] == true && pixel2_y < 100)
				pixel2_y += 1;
			if (p2keys[2] == true && pixel2_x > 0)
				pixel2_x -= 1;
			if (p2keys[3] == true && pixel1_x < 100)
				pixel2_x += 1;
			if (Collision(pixel1_x, pixel1_y, pixel2_x, pixel2_y) == true) {
				cout << "COLLISION" << endl;
				system("color 4A");
			}



			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case(ALLEGRO_KEY_UP):
				p1keys[0] = true;
				break;
			case(ALLEGRO_KEY_DOWN):
				p1keys[1] = true;
				break;
			case(ALLEGRO_KEY_LEFT):
				p1keys[2] = true;
				break;
			case(ALLEGRO_KEY_RIGHT):
				p1keys[3] = true;
				break;
			case(ALLEGRO_KEY_W):
				p2keys[0] = true;
				break;
			case(ALLEGRO_KEY_S):
				p2keys[1] = true;
				break;
			case(ALLEGRO_KEY_A):
				p2keys[2] = true;
				break;
			case(ALLEGRO_KEY_D):
				p2keys[3] = true;
				break;
			case(ALLEGRO_KEY_ESCAPE):
				doexit = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case(ALLEGRO_KEY_UP):
				p1keys[0] = false;
				break;
			case(ALLEGRO_KEY_DOWN):
				p1keys[1] = false;
				break;
			case(ALLEGRO_KEY_LEFT):
				p1keys[2] = false;
				break;
			case(ALLEGRO_KEY_RIGHT):
				p1keys[3] = false;
				break;
			case(ALLEGRO_KEY_W):
				p2keys[0] = false;
				break;
			case(ALLEGRO_KEY_S):
				p2keys[1] = false;
				break;
			case(ALLEGRO_KEY_A):
				p2keys[2] = false;
				break;
			case(ALLEGRO_KEY_D):
				p2keys[3] = false;
				break;
			}
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(pixel1, pixel1_x, pixel1_y, 0);
			al_draw_bitmap(pixel2, pixel2_x, pixel2_y, 0);
			al_flip_display();
		}
	}

}
bool Collision(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2)
		return true;
}