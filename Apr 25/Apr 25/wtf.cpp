#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include<allegro5\allegro_primitives.h>
#include<math.h>

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;

int main() {


	//variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP*face1 = NULL;
	ALLEGRO_BITMAP*face2 = NULL;
	ALLEGRO_BITMAP*face3 = NULL;
	ALLEGRO_SAMPLE*Place = NULL;
	ALLEGRO_BITMAP*background = NULL;
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	bool redraw = true;
	int delay = 0;
	int a = 0;
	int b = 0;
	int angle = 10;
	int radius = 10;

	float face1_x = SCREEN_W / 10;
	float face1_y = SCREEN_H / 4;
	float face2_x = SCREEN_W / 1.5;
	float face2_y = SCREEN_H / 5;
	float face3_x = SCREEN_W / 3;
	float face3_y = SCREEN_H / 5;

	//initializations
	al_init();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_init_primitives_addon();
	timer = al_create_timer(1.0 / FPS);

	//load all your stuff
	display = al_create_display(SCREEN_W, SCREEN_H);
	background = al_load_bitmap("WhatIsLove.jpg");
	al_reserve_samples(1);
	Place = al_load_sample("DejaVu.wav");
	face1 = al_load_bitmap("Face1.jpg");

	al_set_target_bitmap(face1);
	al_convert_mask_to_alpha(face1, al_map_rgb(255, 255, 255));

	face2 = al_load_bitmap("Face2.png");
	al_set_target_bitmap(face2);
	al_convert_mask_to_alpha(face2, al_map_rgb(255, 255, 255));


	face3 = al_load_bitmap("Face3.png");
	al_set_target_bitmap(face3);
	al_convert_mask_to_alpha(face3, al_map_rgb(255, 255, 255));


	//get your event queue ready to roll
	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));


	//actually starting the game
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	al_play_sample(Place, 1.0, 0.0, 1.5, ALLEGRO_PLAYMODE_LOOP, NULL);

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			face1_x += a + cos(angle)*radius;
			face1_y -= b + sin(angle)*radius;
			face2_x -= a + cos(angle)*radius;
			face2_y += b + sin(angle)*radius;
			face3_x += a + cos(angle)*radius;
			face3_y += b + sin(angle)*radius;
			
			if (delay % 5 == 0)
				angle = angle+3;
			delay++;


			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));


			al_draw_filled_circle(50, 50, 50, al_map_rgb(200, 100, 100));
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_bitmap(face1, face1_x, face1_y, 0);
			al_draw_bitmap(face2, face2_x, face2_y, 0);
			al_draw_bitmap(face3, face3_x, face3_y, 0);
			al_flip_display();
		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}