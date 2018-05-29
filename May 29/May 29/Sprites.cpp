#include<iostream>
#include <allegro5/allegro.h>
#include<allegro5\allegro_image.h>

using namespace std;

const float FPS = 60;
const int player_SIZE = 32;
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE
};
enum directions { RIGHT, LEFT, UP, DOWN };

int main()
{

	//player sprite info
	const int maxFrame = 8; //this is the width of your sprite sheet in number of frames 
	int curFrame = 0;
	int frameCount = 0;
	int frameDelay = 5; //this speeds up or slows down the "feet"
	int frameWidth = 32; //make sure these match with your individual frame sizes
	int frameHeight = 48;
	int dir = RIGHT;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *player = NULL;

	//player starting position
	int player_x = 300;
	int player_y = 300;

	bool key[5] = { false, false, false, false , false };
	bool redraw = true;
	bool doexit = false;

	//set up Allegro
	al_init();
	al_init_image_addon();
	al_install_keyboard();

	display = al_create_display(800, 800);
	timer = al_create_timer(1.0 / FPS);

	player = al_load_bitmap("link.png");
	al_convert_mask_to_alpha(player, al_map_rgb(255, 0, 255)); //obnoxious pink is a great background color

	al_set_target_bitmap(al_get_backbuffer(display));

	//create event queue and set it up to look for close window buttons, timer ticks, and keyboard input
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	//start the game
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);

	//game loop
	while (!doexit)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			//SPRITE MOVEMENT:
			//if any key has been pressed, move across the sprite sheet (render section chooses which row)
			if (key[KEY_UP] || key[KEY_DOWN] || key[KEY_LEFT] || key[KEY_RIGHT] || !key[KEY_UP] || !key[KEY_DOWN] || !key[KEY_LEFT] || !key[KEY_RIGHT]) {

				frameCount++; //tick the delay counter

				if (frameCount >= frameDelay) { //has enough time passed?

					curFrame++; //move to the next frame in the sprite sheet

					frameCount = 0;//reset the delay timer

					if (curFrame >= maxFrame) //have we moved off the edge of the sprite sheet?

						curFrame = 0; //go back to the beginning of the sheet
				}
			}

			//normal character movement, independent of sprites
			if (key[KEY_UP]) {
				dir = UP;
				player_y -= 4.0;

			}

			if (key[KEY_DOWN]) {
				dir = DOWN;
				player_y += 4.0;

			}

			if (key[KEY_LEFT]) {
				dir = LEFT;
				player_x -= 4.0;

			}

			if (key[KEY_RIGHT]) {
				dir = RIGHT;
				player_x += 4.0;

			}

			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;

			case ALLEGRO_KEY_SPACE:
				key[KEY_SPACE] = true;
				break;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			case ALLEGRO_KEY_SPACE:
				key[KEY_SPACE] = false;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			//draw_bitmap_region draws only parts of a given bitmap, in this case, one frame of our animation at a time.
			//notice that we start lower on the sheet and draw different rows based on the direction...
			if (dir == RIGHT)
				al_draw_bitmap_region(player, curFrame * frameWidth, 48, frameWidth, frameHeight, player_x, player_y, 0);
			if (dir == LEFT)
				al_draw_bitmap_region(player, curFrame * frameWidth, 0, frameWidth, frameHeight, player_x, player_y, 0);
			if (dir == UP)
				al_draw_bitmap_region(player, curFrame * frameWidth, 48 * 2, frameWidth, frameHeight, player_x, player_y, 0);
			if (dir == DOWN)
				al_draw_bitmap_region(player, curFrame * frameWidth, 48 * 3, frameWidth, frameHeight, player_x, player_y, 0);

			al_flip_display();
		}
	}

	al_destroy_bitmap(player);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}