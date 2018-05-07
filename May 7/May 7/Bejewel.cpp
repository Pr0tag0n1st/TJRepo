#include <iostream>
#include <ctime>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
using namespace std;
const int Size = 40;
int main() {
	cout << "flag1" << endl;
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	srand(time(NULL));
	ALLEGRO_DISPLAY *Display = al_create_display(600, 600);
	ALLEGRO_EVENT_QUEUE *Event_Queue = al_create_event_queue();
	ALLEGRO_TIMER *Timer = al_create_timer(.01);
	ALLEGRO_BITMAP *Emerald = al_load_bitmap("Emerald.png");
	ALLEGRO_BITMAP *Diamond = al_load_bitmap("Diamond.png");
	ALLEGRO_BITMAP *Ruby = al_load_bitmap("Ruby.png");
	ALLEGRO_BITMAP *Sapphire = al_load_bitmap("Sapphire.png");
	cout << "flag2" << endl;
	bool Redraw = true;
	bool Doexit = false;

	al_convert_mask_to_alpha(Emerald, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(Diamond, al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(Ruby, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(Sapphire, al_map_rgb(255, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(Display));
	cout << "flag3" << endl;
	al_register_event_source(Event_Queue, al_get_display_event_source(Display));
	al_register_event_source(Event_Queue, al_get_timer_event_source(Timer));
	al_register_event_source(Event_Queue, al_get_keyboard_event_source());
	cout << "flag4" << endl;
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(Timer);
	int Map[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Map[i][j] = rand() % 4 + 1;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << Map[i][j];
		cout << endl;
	}
	while (!Doexit) {

		ALLEGRO_EVENT ev;
		al_wait_for_event(Event_Queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			Redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				Doexit = true;
				break;
			}
		}
		if (Redraw && al_is_event_queue_empty(Event_Queue)) {
			Redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					//	al_draw_rectangle(i*50,j*50, i*50+50, j*50+50, al_map_rgb(50,80,90), 3);
					if (Map[j][i] == 1) {
						al_draw_bitmap(Emerald, j * 60, i * 60, 0);
					}
					if (Map[j][i] == 2) {
						al_draw_bitmap(Diamond, j * 60, i * 60, 0);
					}
					if (Map[j][i] == 3) {
						al_draw_bitmap(Ruby, j * 60, i * 60, 0);
					}
					if (Map[j][i] == 4) {
						al_draw_bitmap(Sapphire, j * 60, i * 60, 0);
					}
				}
			}
			al_flip_display();
		}



	}

	system("pause");
	al_destroy_bitmap(Emerald);
	al_destroy_bitmap(Diamond);
	al_destroy_bitmap(Ruby);
	al_destroy_bitmap(Sapphire);
	al_destroy_timer(Timer);
	al_destroy_display(Display);
	al_destroy_event_queue(Event_Queue);
	return 0;
}