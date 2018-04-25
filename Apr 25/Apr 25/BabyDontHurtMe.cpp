//#include <allegro5/allegro.h>
//#include <allegro5/allegro_image.h>
//#include <allegro5/allegro_audio.h>
//#include <allegro5/allegro_acodec.h>
//#include<allegro5\allegro_primitives.h>
//#include <iostream>
//#include<math.h>
//using namespace std;
//	const float FPS = 60;
//	const int SCREEN_W = 640;
//	const int SCREEN_H = 480;
//	const int BOUNCER_SIZE = 32;
//int main() {
//	//from base code
//
//		ALLEGRO_DISPLAY *display = NULL;
//		ALLEGRO_EVENT_QUEUE *event_queue = NULL;
//		ALLEGRO_TIMER *timer = NULL;
//		ALLEGRO_BITMAP*face1 = NULL;
//		ALLEGRO_BITMAP *bouncer = NULL;
//		ALLEGRO_BITMAP*face2 = NULL;
//		ALLEGRO_BITMAP*face3 = NULL;
//		ALLEGRO_SAMPLE*Place = NULL;
//		float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
//		float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
//		float bouncer_dx = -4.0, bouncer_dy = 4.0;
//		bool redraw = true;
//
//		al_init();
//		al_init_image_addon();	
//		al_install_audio();
//		al_init_acodec_addon();
//		al_init_primitives_addon();
//		timer = al_create_timer(1.0 / FPS);
//		
//
//		display = al_create_display(SCREEN_W, SCREEN_H);
//		
//		bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
//	
//
//		al_set_target_bitmap(bouncer);
//
//		al_clear_to_color(al_map_rgb(255, 0, 255));
//
//		al_set_target_bitmap(al_get_backbuffer(display));
//
//		ALLEGRO_BITMAP*background = al_load_bitmap("WhatIsLove.jpg");
//
//		al_reserve_samples(1);
//		Place = al_load_sample("DejaVu.wav");
//		face1 = al_load_bitmap("Face1.jpg");
//
//		al_set_target_bitmap(face1);
//		al_convert_mask_to_alpha(face1, al_map_rgb(255, 255, 255));
//
//		face2 = al_load_bitmap("Face2.png");
//
//		al_set_target_bitmap(face2);
//		al_convert_mask_to_alpha(face2, al_map_rgb(255, 255, 255));
//
//
//		face3 = al_load_bitmap("Face3.png");
//
//		al_set_target_bitmap(face3);
//		al_convert_mask_to_alpha(face3, al_map_rgb(255, 255, 255));
//
//		/*ALLEGRO_TIMER*timer = al_create_timer(1 / 60);
//		ALLEGRO_EVENT_QUEUE*event_queue = NULL;
//		al_set_target_bitmap(al_get_backbuffer(display));
//		event_queue = al_create_event_queue();
//
//		al_register_event_source(event_queue, al_get_display_event_source(display));
//		al_register_event_source(event_queue, al_get_timer_event_source(timer));*/
//
//		/*float face1_x = screenw / 2;
//		float face1_y = screenh / 3;
//		float face2_x = screenw / 1.5;
//		float face2_y = screenh / 2;
//		float face3_x = screenw / 3;
//		float face3_y = screenh / 2;*/
//		al_play_sample(Place, 1.0, 0.0, 1.5, ALLEGRO_PLAYMODE_LOOP, NULL);
//
//		al_flip_display();
//
//		event_queue = al_create_event_queue();
//	
//		al_register_event_source(event_queue, al_get_display_event_source(display));
//
//		al_register_event_source(event_queue, al_get_timer_event_source(timer));
//
//		al_clear_to_color(al_map_rgb(0, 0, 0));
//
//		al_flip_display();
//
//		al_start_timer(timer);
//		//end base code//////////////////////////////////////////////////////////////////////////////
//
//
//	//int screenw = 800;
//	//int screenh = 640;
//	//al_init();
//	
//
//	//al_init_primitives_addon();
//	//bool redraw = true;
//	int delay = 0;
//	int a = 3;
//	int b = 5;
//	int angle = 40;
//	int radius = 2;
//	//ALLEGRO_DISPLAY*display = al_create_display(screenw, screenh);
//
//
//
//
//
//	//al_start_timer(timer);
//
//	while (1) {
//		//cout << "game loop started" << endl;
//
//		ALLEGRO_EVENT ev;
//		al_wait_for_event(event_queue, &ev);
//
//		if (ev.type == ALLEGRO_EVENT_TIMER) {
//			cout << "Timer is running" << endl;
//			redraw = true;
//		}
//
//		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
//			cout << "display close pressed!" << endl;
//			break;
//		}
//		if (redraw && al_is_event_queue_empty(event_queue)) {
//			cout << "render section is running" << endl;
//			redraw = false;
//			al_clear_to_color(al_map_rgb(0, 0, 0));
//			al_draw_filled_circle(50, 50, 50, al_map_rgb(200, 100, 100));
//			//al_draw_bitmap(background, 0, 0, 0);
//			//al_draw_bitmap(face1, face1_x, face1_y, 0);
//			//al_draw_bitmap(face2, face2_x, face2_y, 0);
//			//al_draw_bitmap(face3, face3_x, face3_y, 0);
//			al_flip_display();
//			cout << "Display flipped" << endl;
//		}
//	}
//}