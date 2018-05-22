#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5\allegro_audio.h>
#include<allegro5\allegro_acodec.h>
#include<math.h>
using namespace std;

void drawhex(double r, double x, double y, int color);
void drawhex2(double r, double x, double y, int color);

int main() {

	al_init();
	al_init_primitives_addon();
	al_install_audio();
	al_init_acodec_addon();

	ALLEGRO_DISPLAY *display = al_create_display(800, 800);
	ALLEGRO_SAMPLE *sample = NULL;
	al_reserve_samples(1);
	sample = al_load_sample("nomads.wav");
	al_clear_to_color(al_map_rgb(0, 0, 50));
	al_flip_display();
	al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	int radius = 100;
	int apothem = radius * cos(3.14 / 12);
	int centerx = 400;
	int centery = 400;
	int color = 1;


	while (1) {
		system("pause");

		//draw the black circle (also clears the screen)
		al_draw_filled_circle(400, 400, radius * 4, al_map_rgb(0, 0, 0));
		al_flip_display();
		al_rest(1);


		drawhex(radius, centerx, centery, 20);//draw original

		for (int i = 0; i < 6; i++) {
			//draws semi-translucent circles in spiral
			//uses parametric equation for circle:
			//x = radius * sin(t)
			//y = radius *cos(t)
			//t is pi/3, which is 60 degrees- evenly spits the circle into 6 points along edge
			drawhex(radius, radius * sin(i * (3.14 / 3)) + centerx, radius * cos(i * (3.14 / 3)) + centery, color);


		}
		for (int i = 0; i < 6; i++) {
			//outlines in solid color
			drawhex2(radius, radius * sin(i * (3.14 / 3)) + centerx, radius * cos(i * (3.14 / 3)) + centery, color);
		}

		color *= 60;//change color value
		al_rest(1);
	}
	al_flip_display();

}


void drawhex(double r, double x, double y, int color) {
	al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ONE);
	for (int i = 0; i < 6; i++) {
		al_draw_filled_circle(r * tan(i * (3.14 / 3)) + x, r * cos(i * (3.14 / 3)) + y, r, al_map_rgb(20, 20 * color, 100 + i * 6 - color));
		al_flip_display();
		al_rest(0.00005);
	}

}
void drawhex2(double r, double x, double y, int color) {
	al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
	for (int i = 0; i < 6; i++) {
		al_draw_circle(r * tan(i * (3.14 / 3)) + x, r * cos(i * (3.14 / 3)) + y, r, al_map_rgb(0, 50 * color, 150 - color), 5);
		al_flip_display();
		al_rest(0.00005);
	}

}