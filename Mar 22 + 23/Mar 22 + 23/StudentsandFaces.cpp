#include <iostream>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class FACE {
public:
	void initFace(int wid, int hig, int x, int y, int movex, int movey, ALLEGRO_BITMAP*sample);
	void drawFace();
	void Movement();
private:
	int width;
	int height;
	int xpos;
	int ypos;
	int dx;
	int dy;
	ALLEGRO_BITMAP*pic;
};
int main() {
	al_init();
	al_init_image_addon();
	ALLEGRO_DISPLAY*display = al_create_display(600, 400);
	ALLEGRO_BITMAP*face = al_create_bitmap(50, 50);
	al_set_target_bitmap(face);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	ALLEGRO_TIMER*timer = al_create_timer(0.02);
	ALLEGRO_EVENT_QUEUE*event_queue = al_create_event_queue();
	bool redraw = true;
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_set_target_backbuffer(display);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	FACE face1;
	FACE face2;
	FACE face3;
	FACE face4;
	FACE face5;
	FACE face6;
	face1.initFace(50, 50, 25, 75, 2, 2, face);
	face2.initFace(50, 50, 75, 100, 2, 4, face);
	face3.initFace(50, 50, 50, 50, 4, 2, face);
	face4.initFace(50, 50, 100, 100, 4, 4, face);
	face5.initFace(50, 50, 150, 150, 8, 8, face);
	face6.initFace(50, 50, 200, 150, 2, 8, face);
	while (1) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			face1.Movement();
			face2.Movement();
			face3.Movement();
			face4.Movement();
			face5.Movement();
			face6.Movement();
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			face1.drawFace;
			face2.drawFace;
			face3.drawFace;
			face4.drawFace;
			face5.drawFace;
			face6.drawFace;
		}
	}


}
void FACE::initFace(int wid, int hig, int x, int y, int movex, int movey, ALLEGRO_BITMAP*sample) {
	width = wid;
	height = hig;
	xpos = x;
	ypos = y;
	dx = movex;
	dy = movey;
	ALLEGRO_BITMAP*pic = sample;
}
void FACE::drawFace() {
	al_draw_bitmap(pic, dx, dy, 0);
}

void FACE::Movement() {
	xpos += dx;
	ypos += dy;
	if (xpos < 0 || xpos + width > 600)
		dx *= -1;
	if (ypos < 0 || ypos + height > 400)
		dy *= -1;
}