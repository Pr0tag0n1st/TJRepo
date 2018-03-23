#include <iostream>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;
class FACE {
public:
	void initFace(int x, int y, int movex, int movey, ALLEGRO_BITMAP*sample);
	void drawFace();
	void Movement();
	void printFace();
private:

	int xpos;
	int ypos;
	int dx;
	int dy;
	ALLEGRO_BITMAP*pic;
};
int main() {
	vector<FACE> faces;
	al_init();
	al_init_image_addon();
	ALLEGRO_DISPLAY*display = al_create_display(600, 400);
	cout << "flag1" << endl;
	ALLEGRO_BITMAP*mario = al_load_bitmap("Mayo.png");
	ALLEGRO_BITMAP*luigi = al_load_bitmap("Linguini.png");
	ALLEGRO_BITMAP*link = al_load_bitmap("Stink.png");
	ALLEGRO_BITMAP*samus = al_load_bitmap("Spamus.png");
	ALLEGRO_BITMAP*falcon = al_load_bitmap("Hyes.png");
	ALLEGRO_BITMAP*fox = al_load_bitmap("Toriyah.png");
	ALLEGRO_TIMER*timer = al_create_timer(0.02);
	ALLEGRO_EVENT_QUEUE*event_queue = al_create_event_queue();
	bool redraw = true;
	cout << "Flag2" << endl;
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
	cout << "Flag3" << endl;
	face1.initFace(25, 75, 2, 2, mario);
	face2.initFace(75, 100, 2, 4, luigi);
	face3.initFace(50, 50, 4, 2, link);
	face4.initFace(100, 100, 4, 4, samus);
	face5.initFace(150, 150, 8, 8, falcon);
	face6.initFace(200, 150, 2, 8, fox);
	vector<FACE>::iterator iter;
	faces.push_back(face1);
	faces.push_back(face2);
	faces.push_back(face3);
	faces.push_back(face4);
	faces.push_back(face5);
	faces.push_back(face6);
	cout << "flag4" << endl;
	al_start_timer(timer);
	while (1) {
		cout << "flag4.5" << endl;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		cout << "flag4.75" << endl;
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			cout << "flag5" << endl;
			for (iter = faces.begin(); iter != faces.end(); iter++) {
				iter->Movement();
				iter->printFace();
			}
			cout << "flag6" << endl;
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			cout << "flag7" << endl;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			for (iter = faces.begin(); iter != faces.end(); iter++) {
				iter->drawFace();
			}
			al_flip_display();
		}
	}


}
void FACE::initFace(int x, int y, int movex, int movey, ALLEGRO_BITMAP*sample) {

	xpos = x;
	ypos = y;
	dx = movex;
	dy = movey;
	ALLEGRO_BITMAP*pic = sample;
}
void FACE::drawFace() {
	al_draw_bitmap(pic, xpos, ypos, 0);
}
void FACE::printFace() {
	cout << "Face is at:" << xpos << ", " << ypos << ", going " << dx << ", " << dy << " units per frame." << endl;
}
void FACE::Movement() {
	xpos += dx;
	ypos += dy;
	if (xpos < 0 || xpos > 600)
		dx *= -1;
	if (ypos < 0 || ypos > 400)
		dy *= -1;
}