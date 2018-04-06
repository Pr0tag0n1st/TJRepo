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
	ALLEGRO_BITMAP*loadpic = NULL;
	

	al_set_target_backbuffer(display);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	FACE face1;
	FACE face2;
	FACE face3;
	FACE face4;
	FACE face5;
	FACE face6;
	face1.initFace(25, 75, 2, 2, al_load_bitmap("Mayo.png"));
	face2.initFace(75, 100, 2, 4, al_load_bitmap("Linguini.png"));
	face3.initFace(50, 50, 4, 2, al_load_bitmap("Stink.png"));
	face4.initFace(100, 100, 4, 4, al_load_bitmap("Spamus.png"));
	face5.initFace(150, 150, 8, 8, al_load_bitmap("Hyes.png"));
	face6.initFace(200, 150, 2, 8, al_load_bitmap("Toriyah.png"));
	vector<FACE>::iterator iter;
	faces.push_back(face1);
	faces.push_back(face2);
	faces.push_back(face3);
	faces.push_back(face4);
	faces.push_back(face5);
	faces.push_back(face6);
	ALLEGRO_BITMAP*mario = al_load_bitmap("Stink.png");
	al_draw_bitmap(mario, 10, 10, 0);
	al_flip_display();
	al_rest(3.0);
	while (1) {

		//walks through vector, prints and moves each face
		for (iter = faces.begin(); iter != faces.end(); iter++) {
			iter->printFace();
			iter->Movement();
			iter->printFace();
			iter->drawFace();

		}
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));



		//render section

	}
	}
void FACE::initFace(int x, int y, int movex, int movey, ALLEGRO_BITMAP*sample) {

	xpos = x;
	ypos = y;
	dx = movex;
	dy = movey;
	pic = sample;
}
void FACE::drawFace() {

	cout << "flag1" << endl;
	al_draw_bitmap(pic, xpos, ypos, 0);
	cout << "flag2" << endl;
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