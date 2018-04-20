#include <iostream>
#include <string>
using namespace std;
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

class ROOM {
public:
	void roomInit(ALLEGRO_BITMAP*roomimage, string ID, int x, int y, int w, int h, ALLEGRO_FONT*fonttype);
	void roomDraw();
	void roomSelect();
	bool roomCollide(int cx, int cy);
private:
	ALLEGRO_BITMAP * image;
	string id;
	int xPos;
	int yPos;
	int width;
	int height;
	ALLEGRO_FONT*typeface;
};


int main() {
	bool redraw = true;
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	double cursor_x = 0;
	double cursor_y = 0;
	ALLEGRO_DISPLAY*display = al_create_display(1000, 600);
	ALLEGRO_EVENT_QUEUE*event_queue = al_create_event_queue();
	ALLEGRO_TIMER*timer = al_create_timer(1.0 / 60);
	ALLEGRO_BITMAP*roomtype = NULL;
	ALLEGRO_FONT*font = al_create_builtin_font();
	ROOM diner;
	ROOM water;
	ROOM power;
	ROOM space;
	diner.roomInit(al_load_bitmap("eatingbois.jpg"), "DINER", 25, 25, 508, 99, font);
	water.roomInit(al_load_bitmap("waterbois.jpg"), "WATER", 25, 200, 519, 128, font);
	space.roomInit(al_load_bitmap("livingbois.jpg"), "SPACE", 600, 25, 370, 111, font);
	power.roomInit(al_load_bitmap("powerbois.jpg"), "POWER", 400, 400, 381, 109, font);
	al_install_mouse();
	al_set_target_bitmap(al_get_backbuffer(display));
	al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);

	while (1) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			cursor_x = ev.mouse.x;
			cursor_y = ev.mouse.y;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			diner.roomDraw();
			power.roomDraw();
			water.roomDraw();
			space.roomDraw();
			al_flip_display();
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (diner.roomCollide(ev.mouse.x, ev.mouse.y) == true) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				diner.roomSelect();
			}
			if (power.roomCollide(ev.mouse.x, ev.mouse.y) == true) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				power.roomSelect();
			}
			if (water.roomCollide(ev.mouse.x, ev.mouse.y) == true) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				water.roomSelect();
			}
			if (space.roomCollide(ev.mouse.x, ev.mouse.y) == true) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				space.roomSelect();
			}
		}



		
	}
	al_destroy_bitmap(roomtype);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;

}

void ROOM::roomInit(ALLEGRO_BITMAP*roomimage, string ID, int x, int y, int w, int h, ALLEGRO_FONT * FONTTYPE) {
	image = roomimage;
	id = ID;
	xPos = x;
	yPos = y;
	width = w;
	height = h;
	typeface = FONTTYPE;

}

void ROOM::roomDraw() {
	al_draw_bitmap(image, xPos, yPos, 0);
}

void ROOM::roomSelect() {

	al_draw_rectangle(xPos, yPos, xPos + width, yPos + height, al_map_rgb(0, 255, 0), 5);
	al_draw_textf(typeface, al_map_rgb(0, 255, 0), xPos + (width/2), yPos + height+5, 1, "%s", id.c_str());
	
}

bool ROOM::roomCollide(int cx, int cy) {
	if ((cx > xPos) &&
		(cx < xPos + width) &&
		(cy > yPos) &&
		(cy < yPos + height))
		return true;
	else
		return false;
}