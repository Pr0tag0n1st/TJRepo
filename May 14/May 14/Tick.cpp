#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
using namespace std;
const float FPS = 60;
int clear(int map[3][3]);
int main() {
	cout << "flag1" << endl;
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	int size = 200;
	int xscore = 0;
	int oscore = 0;
	int tiescore = 0;
	bool player1 = true;
	bool player2 = false;
	ALLEGRO_DISPLAY*display = al_create_display(610, 700);
	ALLEGRO_BITMAP*X = al_load_bitmap("tictactoeX.png");
	ALLEGRO_BITMAP*O = al_load_bitmap("tictactoeO.png");
	ALLEGRO_FONT*font = al_load_font("Diner.ttf", 48, 0);
	ALLEGRO_TIMER *timer = al_create_timer(1.0/60);
	ALLEGRO_BITMAP*dino = al_load_bitmap("DinoStudios.jpg");
	if (timer == NULL) cout << "timer is dumb.";

	bool key[9] = { false, false, false, false, false, false, false, false, false };//ADDED BY MO, EXPAND AND USE IN TIMER SECTION

	int Grid[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Grid[i][j] = 0;
		}
	}
	bool Redraw = true;
	bool Doexit = false;	
	al_set_target_bitmap(al_get_backbuffer(display));

	ALLEGRO_EVENT_QUEUE*event_queue = al_create_event_queue();
	if (event_queue == NULL)cout << "event queue is NULL" << endl;

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_clear_to_color(al_map_rgb(0, 0, 0));
	

	al_draw_bitmap(dino, 0, 0, 0);
	al_flip_display();
	al_rest(2);

	for (int i = 255; i > 0; i -= 5) {
		al_draw_tinted_bitmap(dino, al_map_rgb(i, i, i), 0, 0, 0);
		al_rest(0.05);
		al_flip_display();
	}
	//cout << "flag2" << endl;

	
	al_start_timer(timer);

	al_flip_display();


	while (!Doexit) {
		//cout << "game loop started" << endl;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		//cout << "checking for timer event" << endl;
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			Redraw = true;
			//cout << "timer section. Redraw is " <<Redraw<< endl;
			if (key[0] == true) {
				key[0] = false;

				if (Grid[0][2] == 0) {
					if (player1 == true) {


						cout << "Placed an X" << endl;
						Grid[0][2] = 1;
						cout << "Changed value" << endl;
						player1 = false;
						player2 = true;
						cout << "Player2's turn" << endl;
					}
					else if (player2 == true) {
						cout << "Placed an O" << endl;
						Grid[0][2] = 2;
						player1 = true;
						player2 = false;
					}
				}

				else if (Grid[0][2] != 0) {
					cout << "Can't do that" << endl;
				}
			}

			if (key[1] == true) {
				key[1] = false;

				if (Grid[1][2] == 0) {
					if (player1 == true) {

						Grid[1][2] = 1;
						cout << "Placed an X" << endl;
						player1 = false;
						player2 = true;
					}
					else if (player2 == true) {
						Grid[1][2] = 2;
						cout << "Placed an X" << endl;
						player1 = true;
						player2 = false;
					}
					else if (Grid[2][1] != 0) {
						cout << "Can't do that" << endl;
					}

				}
			}

			if (key[2] == true) {
				key[2] = false;

				if (Grid[2][2] == 0) {
					if (player1 == true) {

						Grid[2][2] = 1;
						cout << "Placed an X" << endl;
						player1 = false;
						player2 = true;
					}
					else if (player2 == true) {
						cout << "Placed an O" << endl;
						Grid[2][2] = 2;
						player1 = true;
						player2 = false;
					}
					else if (Grid[2][0] != 0) {
						cout << "Can't do that" << endl;
					}
				}
			}

			if (key[3] == true) {
				key[3] = false;
				if (Grid[0][1] == 0) {
					if (player1 == true) {
						Grid[0][1] = 1;
						cout << "Placed an X" << endl;
						player1 = false;
						player2 = true;
					}
					else if (player2 == true) {
						cout << "Placed an O" << endl;
						Grid[0][1] = 2;
						player1 = true;
						player2 = false;
					}
					else if (Grid[0][1] != 0) {
						cout << "Can't do that" << endl;
					}
				}
			}
			if (key[4] == true) {
				key[4] = false;

				if (Grid[1][1] == 0) {
					if (player1 == true) {

						Grid[1][1] = 1;
						cout << "Placed an X" << endl;
						player1 = false;
						player2 = true;
					}

					else if (player2 == true) {
						cout << "Placed an O" << endl;
						Grid[1][1] = 2;
						player1 = true;
						player2 = false;
					}
					else if (Grid[1][1] != 0) {
						cout << "Can't do that" << endl;
					}
				}
			}

			if (key[5] == true) {
				key[5] = false;

				if (Grid[2][1] == 0) {
					if (player1 == true) {
						Grid[2][1] = 1;
						cout << "Placed an X" << endl;
						player1 = false;
						player2 = true;
					}
					else if (player2 == true) {
						cout << "Placed an O" << endl;
						Grid[2][1] = 2;
						player1 = true;
						player2 = false;
					}
					else if (Grid[2][1] != 0) {
						cout << "Can't do that" << endl;
					}
				}
			}

			if (key[6] == true) {
				key[6] = false;

				if (Grid[0][0] == 0) {
					if (player1 == true) {
						Grid[0][0] = 1;
						cout << "Placed an X" << endl;
						player1 = false;
						player2 = true;
					}
					else if (player2 == true) {
						cout << "Placed an O" << endl;
						Grid[0][0] = 2;
						player1 = true;
						player2 = false;
					}
					else if (Grid[0][0] != 0) {
						cout << "Can't do that" << endl;
					}
				}
			}

			if (key[7] == true) {
				key[7] = false;

				if (Grid[1][0] == 0) {
					if (player1 == true) {

						Grid[1][0] = 1;
						cout << "Placed an X" << endl;
						player1 = false;
						player2 = true;
					}
					else if (player2 == true) {
						cout << "Placed an O" << endl;
						Grid[1][0] = 2;
						player1 = true;
						player2 = false;
					}
					else if (Grid[1][0] != 0) {
						cout << "Can't do that" << endl;
					}
				}
			}
			if (key[8] == true) {
				key[8] = false;

				if (Grid[2][0] == 0) {
					if (player1 == true) {

						Grid[2][0] = 1;
						cout << "Placed an X" << endl;
						player1 = false;
						player2 = true;
					}
					else if (player2 == true) {
						cout << "Placed an O" << endl;
						Grid[2][0] = 2;
						player1 = true;
						player2 = false;
					}
					else if (Grid[2][0] != 0) {
						cout << "Can't do that" << endl;
					}
				}
			}
			if (clear(Grid) == 1) {
				xscore += 1;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						Grid[i][j] = 0;
						
					}
				}
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_textf(font, al_map_rgb(255, 255, 255), 300, 450, 0, "Player 1 wins!");
				al_flip_display();
				al_rest(3.0);
			}
			else if (clear(Grid) == 2){
				oscore += 1; 
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						Grid[i][j] = 0;
					}
				}
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_textf(font, al_map_rgb(255, 255, 255), 300, 450, 0, "Player 2 wins!");
				al_flip_display();
				al_rest(3.0);
				}
				

		}//end timer section

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			cout << "key pressed";
			switch (ev.keyboard.keycode) {

			case ALLEGRO_KEY_A:
				cout << "A Pressed!" << endl;
				break;

			case ALLEGRO_KEY_PAD_1:
				key[0] = true;

				break;

			case ALLEGRO_KEY_PAD_2:
				key[1] = true;
				break;

			case ALLEGRO_KEY_PAD_3:
				key[2] = true;

				break;

			case ALLEGRO_KEY_PAD_4:
				key[3] = true;

				break;

			case ALLEGRO_KEY_PAD_5:
				key[4] = true;

				break;

			case ALLEGRO_KEY_PAD_6:
				key[5] = true;

				break;

			case ALLEGRO_KEY_PAD_7:
				key[6] = true;

				break;

			case ALLEGRO_KEY_PAD_8:
				key[7] = true;

				break;

			case ALLEGRO_KEY_PAD_9:
				key[8] = true;

				break;

			case ALLEGRO_KEY_ESCAPE:
				Doexit = true;

			}
		}

	
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			cout << "key released" << endl;
			switch (ev.keyboard.keycode) {
		
			case ALLEGRO_KEY_PAD_1:
				key[0] = false;
				break;

			case ALLEGRO_KEY_PAD_2:
				key[1] = false;
				break;

			case ALLEGRO_KEY_PAD_3:
				key[2] = false;				
				break;

			case ALLEGRO_KEY_PAD_4:
				key[3] = false;
				break;

			case ALLEGRO_KEY_PAD_5:
				key[4] = false;
				break;

			case ALLEGRO_KEY_PAD_6:
				key[5] = false;
				break;

			case ALLEGRO_KEY_PAD_7:
				key[6] = false;
				break;

			case ALLEGRO_KEY_PAD_8:
				key[7] = false;
				break;

			case ALLEGRO_KEY_PAD_9:
				key[8] = false;
				break;
			}
		}
	
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			cout << "window closed";
			Doexit = true;
		}

		if (Redraw == true && al_is_event_queue_empty(event_queue)) {
			//cout << "Reached Render" << endl;
			Redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_textf(font, al_map_rgb(255, 255, 255), 50, 700, 0, "X:%d", xscore);
			al_draw_textf(font, al_map_rgb(255, 255, 255), 550, 700, 0, "O:%d", oscore);
			al_draw_textf(font, al_map_rgb(255, 255, 255), 300, 700, 0, "Draw:%d", tiescore);
			//cout << "flag3" << endl;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
				
						al_draw_rectangle(i * size+10 , j * size + 10 , i * size + size, j * size + size, al_map_rgb(255, 255, 255), 10);
					if (Grid[i][j] == 1) {
						al_draw_bitmap(X, i*size+5, j*size+5, 0);
					}
					else if (Grid[i][j] == 2) {
						al_draw_bitmap(O, i*size+5, j*size+5, 0);
					}
					
				}
			}

			al_flip_display();
		}
	}//end game loop
	al_destroy_bitmap(X);
	al_destroy_bitmap(O);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}

int clear(int map[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[i][j] != 0) {
				if (map[i][j] == map[i + 1][j] &&
					map[i][j] == map[i + 2][j] ||
					map[i][j] == map[i][j + 1] &&
					map[i][j] == map[i][j + 2] ||
					map[i][j] == map[i + 1][j + 1] &&
					map[i][j] == map[i + 2][j + 2] ||
					map[i][j] == map[i][j - 1] &&
					map[i][j] == map[i][j - 2]
					) {
					cout << "Someone wins!" << endl;
					if (map[i][j] == 1) {
						cout << "Player1!" << endl;
						return 1;
			
					}
					else if (map[i][j] == 2) {
						cout << "Player2!" << endl;
						return 2;
						
					}



				}
				//else if (map[i][j] != map[i + 1][j] &&
				//	map[i][j] != map[i + 2][j] ||
				//	map[i][j] != map[i][j + 1] &&
				//	map[i][j] != map[i][j + 2] ||
				//	map[i][j] != map[i + 1][j + 1] &&
				//	map[i][j] != map[i + 2][j + 2] ||
				//	map[i][j] != map[i][j - 1] &&
				//	map[i][j] != map[i][j - 2]){
				//	cout << "Nobody wins!" << endl;
				//	for (int i = 0; i < 3; i++) {
				//		for (int j = 0; j < 3; j++) {
				//			map[i][j] = 0;
				//		}
				//	}
				}
			}
		}
	}
