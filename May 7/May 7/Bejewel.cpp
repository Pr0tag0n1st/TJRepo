#include <iostream>
#include <ctime>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
using namespace std;
const int Size = 60;
void clear(int map[10][10]);
const int FPS = 50;
void GemFall(int map[10][10]);
void MapFill(int map[10][10]);
//void GemSwap(int map[10][10], bool selected, int GemSlotX, int GemSlotY);

int main() {
	cout << "flag1" << endl;
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_mouse(); 
	al_install_keyboard();
	srand(time(NULL));
	ALLEGRO_DISPLAY *Display = al_create_display(600, 600);
	ALLEGRO_EVENT_QUEUE *Event_Queue = al_create_event_queue();
	ALLEGRO_TIMER *Timer = al_create_timer(1.0/FPS);
	ALLEGRO_BITMAP *Emerald = al_load_bitmap("Emerald.png");
	ALLEGRO_BITMAP *Diamond = al_load_bitmap("Diamond.png");
	ALLEGRO_BITMAP *Ruby = al_load_bitmap("Ruby.png");
	ALLEGRO_BITMAP *Sapphire = al_load_bitmap("Sapphire.png");
//	ALLEGRO_BITMAP *Amethyst = al_load_bitmap("Amethyst.png");
	cout << "flag2" << endl;
	bool Redraw = true;
	bool Doexit = false;
	int cursor_x;
	int cursor_y;
	int boxX;
	int boxY;
	int snapX;
	int snapY;

	bool clicked = false;

	al_convert_mask_to_alpha(Emerald, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(Diamond, al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(Ruby, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(Sapphire, al_map_rgb(255, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(Display));
	cout << "flag3" << endl;
	al_register_event_source(Event_Queue, al_get_display_event_source(Display));
	al_register_event_source(Event_Queue, al_get_timer_event_source(Timer));
	al_register_event_source(Event_Queue, al_get_keyboard_event_source());
	al_register_event_source(Event_Queue, al_get_mouse_event_source());
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
		for (int j = 0; j < 10; j++) {
			cout << Map[j][i];
		}
	cout << endl;
	}
	while (!Doexit) {

		ALLEGRO_EVENT ev;
		al_wait_for_event(Event_Queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			Redraw = true;
			clear(Map);
			MapFill(Map);
			GemFall(Map);

		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			cursor_x = ev.mouse.x;
			cursor_y = ev.mouse.y;
		}

		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			clicked = true;
			boxX = cursor_x;
			boxY = cursor_y;
			snapX = boxX % 60;
			snapY = boxY % 60;
			boxX -= snapX;
			boxY -= snapY;
			
				}
			
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		
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
					
					
					if (Map[j][i] == 1) {
						al_draw_bitmap(Emerald, j * Size, i * Size, 0);
					}
					if (Map[j][i] == 2) {
						al_draw_bitmap(Diamond, j * Size, i * Size, 0);
					}
					if (Map[j][i] == 3) {
						al_draw_bitmap(Ruby, j * Size, i * Size, 0);
					}
					if (Map[j][i] == 4) {
						al_draw_bitmap(Sapphire, j * Size, i * Size, 0);
					}
					// if (Map[j][i] == 5){
					//		al_draw_bitmap(Sapphire, j * Size, i * Size, 0);
					//}
					if (clicked) {
						al_draw_rectangle(boxX, boxY, boxX + Size, boxY + Size, al_map_rgb(255, 255, 255), 4);
					}
				}
			}
			al_flip_display();
		}



	}

	
	al_destroy_bitmap(Emerald);
	al_destroy_bitmap(Diamond);
	al_destroy_bitmap(Ruby);
	al_destroy_bitmap(Sapphire);
	al_destroy_timer(Timer);
	al_destroy_display(Display);
	al_destroy_event_queue(Event_Queue);
	return 0;
}
void clear(int map[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
	/*		for (int c = 0; c < 10; c++) {
				while (map[i][j] == map[i + c][j] || map[i][j] == map[i][j + c]) {
					if (map[i][j] == map[i + c][j]) {
						for (int w = 0; w < c; w++)
							map[i + w][j] = 0;
					}
					if (map[i][j] == map[i][j + c]) {
						for (int w = 0; w < c; w++)
							map[i][j + w] = 0;
					}
				}
			}*/
			if (map[i][j] == map[i][j + 1] && map[i][j] == map[i][j + 2] ||
				map[i][j] == map[i][j + 1] && map[i][j] == map[i][j + 2] && map[i][j] == map[i][j + 3] || 
				map[i][j] == map[i][j + 1] && map[i][j] == map[i][j + 2] && map[i][j] == map[i][j + 3] && map[i][j] == map[i][j + 5]) {
				
				if (map[i][j] != map[i][j + 3]) {
					map[i][j] = 0;
					map[i][j + 1] = 0;
					map[i][j + 2] = 0;
				}
				
				else if (map[i][j] != map[i][j + 4]) {
					map[i][j] = 0;
					map[i][j + 1] = 0;
					map[i][j + 2] = 0;
					map[i][j + 3] = 0;
				}
				else {
					map[i][j] = 0;
					map[i][j + 1] = 0;
					map[i][j + 2] = 0;
					map[i][j + 3] = 0;
					map[i][j + 4] = 0;
				}
			}

			if (map[i][j] == map[i + 1][j] && map[i][j] == map[i + 2][j]||
				map[i][j] == map[i + 1][j] && map[i][j] == map[i + 2][j] && map[i][j] == map[i + 3][j]||
				map[i][j] == map[i + 1][j] && map[i][j] == map[i + 2][j] && map[i][j] == map[i + 3][j] && map[i][j] == map[i + 4][j]) {



				if (map[i][j] != map[i + 3][j]) {
					map[i][j] = 0;
					map[i][j + 1] = 0;
					map[i][j + 2] = 0;
				}

				else if (map[i][j] != map[i + 4][j]) {
					map[i][j] = 0;
					map[i][j + 1] = 0;
					map[i][j + 2] = 0;
					map[i][j + 3] = 0;
				}
				else {
					map[i][j] = 0;
					map[i][j + 1] = 0;
					map[i][j + 2] = 0;
					map[i][j + 3] = 0;
					map[i][j + 4] = 0;
				}
			}
		}
	}
}

void GemFall(int map[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 0) {
				map[i][j] = map[i][j-1];
				map[i][j-1] = 0;


			}
		}
	}
}

void MapFill(int map[10][10]) {

		for (int i = 0; i < 10; i++) {
			if (map[i][0] == 0) {
				map[i][0] = rand() % 4 + 1;
			}
		}
	
}

//void GemSwap(int map[10][10], bool selected, int GemSlotX, int GemSlotY) {
//	if (selected == true) {
//		for (int i = 0; i < 10; i++)
//			for (int j = 0; j < 10; j++) {
//				map[GemSlotX / Size][GemSlotY / Size] = map[i][j];
//				int Placeholderslot[i][j] = map[i][j];
//				if (map[i][j] == Placeholderslot[i + 1][j] ||
//					map[i][j] == Placeholderslot[i - 1][j] || 
//					map[i][j] == Placeholderslot[i + 1][j + 1] || 
//					map[i][j] == Placeholderslot[i + 1][j - 1] || )
//					
//			}
//	}
//	 
//}