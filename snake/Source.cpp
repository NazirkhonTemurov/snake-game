#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>//keyboard

using namespace std;

bool gameOver;
const int widht = 60;
const int height = 20;
int x, y, fruitx, fruity, score;
int tailX[100], teilY[100];
int nTail;
enum eDirection { stop = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void setup() {
    gameOver = false;
	dir = stop;
	x = widht / 2 -1;
	y = height / 2 -1;
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
          if (i == y && j == x) {
cout << "0";
		  } else if (i == fruity && j == fruitx) {
cout << "F";
              }else
cout << " ";	
      }
cout << endl;
	}
	
    for (int i = 0; i < widht+1; ++i) {
cout << "#";
	}
cout << endl;
cout << "Score: " << score << endl;
}

void input() {
	if (_kbhit()) {
      switch (_getch()) {
	  case'a':
	    dir = LEFT;
	  case'd':
	    dir = RIGHT;
	  case'w':
		dir = UP;
	  case's':
		dir = DOWN;
	  case'x':
	    gameOver = true;
	  }
	}
}

void logic() {
    switch (dir){
	  case stop:
	    break;
	  case LEFT:
	    --x;
	    break;
	  case RIGHT:
	    ++x;
	   break;
	  case UP:
	    --y;
	   break;
	  case DOWN:
	    ++x;
	    break;
	}

	if (x > widht || x < 0 || y > height || y < 0) {
	  gameOver = true;
	}

	if (x == fruitx && y == fruity) {
	  score += 10;
	  fruitx = rand() % widht;
	  fruity = rand() % height;
	}
}

int main(){
	setup();
    while (!gameOver) {
      draw();
      input();
      logic();
}
    }
