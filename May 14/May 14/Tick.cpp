#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
using namespace std;
int main() {
	cout << "flag1" << endl;
	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	int size = 200;
	bool clicked = false;
	int turnorder = 1;
	ALLEGRO_DISPLAY*display = al_create_display(630, 700);
	ALLEGRO_BITMAP*X = al_load_bitmap("tictactoeX.png");
	ALLEGRO_BITMAP*O = al_load_bitmap("tictactoeO.png");
	ALLEGRO_FONT*font = al_create_builtin_font();
	ALLEGRO_EVENT_QUEUE*event_queue = al_create_event_queue();
	int Grid[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Grid[i][j] = 0;
		}
	}
	bool Redraw = true;
	bool Doexit = false;
	al_set_target_bitmap(al_get_backbuffer(display));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	cout << "flag2" << endl;

	while (!Doexit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			Redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_PAD_1:
				
				if (turnorder == 1 && Grid[2][0] == 0) {
					Grid[2][0] = 1;
					cout << "Placed an X" << endl;
					turnorder = 2;
				}
				if (turnorder == 2 && Grid[2][0] == 0) {
					cout << "Placed an O" << endl;
					Grid[2][0] = 2;
					turnorder = 1;
				}
				if (Grid[2][0] != 0) {
					cout << "Can't do that" << endl;
				}
			case ALLEGRO_KEY_PAD_2:

				if (turnorder == 1 && Grid[2][1] == 0) {
					Grid[2][1] = 1;
					cout << "Placed an X" << endl;
					turnorder = 2;
				}
				if (turnorder == 2 &&Grid[2][1] == 0) {
					cout << "Placed an O" << endl;
					Grid[2][1] = 2;
					turnorder = 1;
				}
				if (Grid[2][1] != 0) {
					cout << "Can't do that" << endl;
				}
			case ALLEGRO_KEY_PAD_3:

				if (turnorder == 1 && Grid[2][2] == 0) {
					Grid[2][2] = 1;
					cout << "Placed an X" << endl;
					turnorder = 2;
				}
				if (turnorder == 2 && Grid[2][2] == 0) {
					cout << "Placed an O" << endl;
					Grid[2][2] = 2;
					turnorder = 1;
				}
				if (Grid[2][2] != 0) {
					cout << "Can't do that" << endl;
				}
			case ALLEGRO_KEY_PAD_4:
				if (turnorder == 1 && Grid[1][0] == 0) {
					Grid[1][0] = 1;
					cout << "Placed an X" << endl;
					turnorder = 2;
				}
				if (turnorder == 2 && Grid[1][0] == 0) {
					cout << "Placed an O" << endl;
					Grid[1][0] = 2;
					turnorder = 1;
				}
				if (Grid[1][0] != 0) {
					cout << "Can't do that" << endl;
				}
			case ALLEGRO_KEY_PAD_5:
				if (turnorder == 1 && Grid[1][1] == 0) {
					Grid[1][1] = 1;
					cout << "Placed an X" << endl;
					turnorder = 2;
				}
				if (turnorder == 2 && Grid[1][1] == 0) {
					cout << "Placed an O" << endl;
					Grid[1][1] = 2;
					turnorder = 1;
				}
				if (Grid[1][1] != 0) {
					cout << "Can't do that" << endl;
				}
			case ALLEGRO_KEY_PAD_6:
				if (turnorder == 1 && Grid[1][2] == 0) {
					Grid[1][2] = 1;
					cout << "Placed an X" << endl;
					turnorder = 2;
				}
				if (turnorder == 2 && Grid[1][2] == 0) {
					cout << "Placed an O" << endl;
					Grid[1][2] = 2;
					turnorder = 1;
				}
				if (Grid[1][2] != 0) {
					cout << "Can't do that" << endl;
				}
			case ALLEGRO_KEY_PAD_7:
				if (turnorder == 1 && Grid[0][0] == 0) {
					Grid[0][0] = 1;
					cout << "Placed an X" << endl;
					turnorder = 2;
				}
				if (turnorder == 2 && Grid[0][0] == 0) {
					cout << "Placed an O" << endl;
					Grid[0][0] = 2;
					turnorder = 1;
				}
				if (Grid[0][0] != 0) {
					cout << "Can't do that" << endl;
				}
			case ALLEGRO_KEY_PAD_8:
				if (turnorder == 1 && Grid[0][1] == 0) {
					Grid[0][1] = 1;
					cout << "Placed an X" << endl;
					turnorder = 2;
				}
				if (turnorder == 2 && Grid[0][1] == 0) {
					cout << "Placed an O" << endl;
					Grid[0][1] = 2;
					turnorder = 1;
				}
				if (Grid[0][1] != 0) {
					cout << "Can't do that" << endl;
				}
			case ALLEGRO_KEY_PAD_9:
				if (turnorder == 1 && Grid[0][2] == 0) {
					Grid[0][2] = 1;
					cout << "Placed an X" << endl;
					turnorder = 2;
				}
				if (turnorder == 2 && Grid[0][2] == 0) {
					cout << "Placed an O" << endl;
					Grid[0][2] = 2;
					turnorder = 1;
				}
				if (Grid[0][2] != 0) {
					cout << "Can't do that" << endl;
				}
			}
		}
	
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			Doexit = true;
		}
		else if (Redraw && al_is_event_queue_empty(event_queue)) {
			Redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			cout << "flag3" << endl;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
				
						al_draw_rectangle(i * size+10 , j * size + 10 , i * size + size, j * size + size, al_map_rgb(255, 255, 255), 5);
					if (Grid[i][j] == 1) {
						al_draw_bitmap(X, i*size+10, j*size+10, 0);
					}
					else if (Grid[i][j] == 2) {
						al_draw_bitmap(O, i*size+10, j*size+10, 0);
					}
					
				}
			}
			al_flip_display();
		}
	}
	al_destroy_bitmap(X);
	al_destroy_bitmap(O);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}
