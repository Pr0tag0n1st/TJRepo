#include <ctime>
#include <string>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
using namespace std;
enum COLOR { RED, GREEN, BLUE, YELLOW, BLACK, WHITE, ORANGE, PURPLE, PINK, BROWN };
enum BODY { HEAD, SHOULDER, KNEE, TOE, ELBOW, THUMB, HEEL, WRIST, SHIN, FOREARM };
int main() {
	bool doexit = false;
	bool redraw = true;
	bool nextslide = false;
	int slot1 = rand() % 10;
	int slot2 = rand() % 10;
	string colors[10]{ "Head", "Shoulder", "Knee", "Toe", "Elbow", "Thumb", "Heel", "Wrist", "Shin", "Forearm"};
	string body[10]{ "Red", "Green", "Blue", "Yellow", "Black", "White", "Orange", "Purple", "Pink", "Brown" };
	srand(time(NULL));
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_acodec_addon();
	ALLEGRO_DISPLAY*display = al_create_display(800, 600);
	ALLEGRO_FONT*font = al_load_font("Action_Man.ttf", 48, 0);
	ALLEGRO_BITMAP*image = NULL;
	ALLEGRO_TIMER*timer = al_create_timer(0.02);
	ALLEGRO_SAMPLE*bgm = NULL;
	ALLEGRO_EVENT_QUEUE*event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_install_keyboard();
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_draw_textf(font, al_map_rgb(255, 255, 0), 400, 300, 0, "Let's play a game!");
	al_flip_display();
	al_rest(2.0);
	al_draw_textf(font, al_map_rgb(255, 255, 0), 400, 300, 0, "I'll call out a color and a body part!");
	al_flip_display();
	al_rest(2.0);
	al_draw_textf(font, al_map_rgb(255, 255, 0), 400, 300, 0, "Find something of that color and touch it with that body part!");
	al_flip_display();
	al_rest(2.0);
	al_draw_textf(font, al_map_rgb(255, 255, 0), 400, 300, 0, "Ready?");
	al_flip_display();
	al_rest(1.0);
	al_draw_textf(font, al_map_rgb(255, 255, 0), 400, 300, 0, "3!");
	al_flip_display();
	al_rest(1.0);
	al_draw_textf(font, al_map_rgb(255, 255, 0), 400, 300, 0, "2!");
	al_flip_display();
	al_rest(1.0);
	al_draw_textf(font, al_map_rgb(255, 255, 0), 400, 300, 0, "1!");
	al_flip_display();
	al_rest(1.0);
	al_start_timer(timer);
	
	while (!doexit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (nextslide = true) {
				slot1 = rand() % 10;
				slot2 = rand() % 10;
			}
			cout << slot1 << ", " << slot2 << endl;
			al_draw_textf(font, al_map_rgb(255, 255, 255), 400, 400, 0, "test");			al_draw_textf(font, al_map_rgb(255, 255, 255), 400, 400, 0, "test");
			al_draw_textf(font, al_map_rgb(255, 255, 255), 400, 500, 0, "test");
		}
		redraw = true;
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_SPACE:
				bool nextslide = true;
				break;
			case ALLEGRO_KEY_ESCAPE:
				bool doexit = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_SPACE:
				bool nextslide = false;
			}
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));


			al_flip_display();
		}
		
	}


	}

