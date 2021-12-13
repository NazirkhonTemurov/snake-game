#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool gameOver;
const int widht = 60;
const int height = 20;
int x, y, fruitx, fruity, score;
enum eDirection { stop = 0, left, right, up, down };
eDirection dir;

void setup() {
	gameOver = false;
	dir = stop;
	x = widht / 2;
	y = height / 2;
	fruitx = rand() % widht;
	fruity = rand() % height;
	score = 0;

}

void draw() {
	system("cls");
	for (int i = 0; i < widht+1; ++i) {
		cout << "#" ;
	}
	cout << endl;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < widht; ++j) {
			if (j == 0 || j == widht - 1)
				cout << "#";
				cout << " ";
		
	
			
		}
		cout << endl;
	}
	
	for (int i = 0; i < widht+1; ++i) {
		cout << "#";
	}
	cout << endl;
}

void input() {

}

void logic() {

}

int main(){
	setup();
    while (!gameOver) {
      draw();
      input();
      logic();
}

return 0;

}
