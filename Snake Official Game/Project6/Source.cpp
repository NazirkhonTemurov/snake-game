/*****************************
* Автор:    Темуров Назирхон *
* Название: Игра Змейка      *
* Дата:     22.12.2021       *
*****************************/

#include <iostream>
#include <cstdlib>
#include <conio.h>//keyboard

using namespace std;


bool gameOver;
const int widht = 60;
const int height = 20;
int x, y, fruitx, fruity, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { stop = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void setup() {
  gameOver = false;
  dir = stop;
  x = widht / 2 - 1;
  y = height / 2 - 1;
  fruitx = rand() % widht;
  fruity = rand() % height;
  score = 0;
}

void draw() {
  system("cls");
  for (int i = 0; i < widht + 1; ++i) {
    cout << "#";
  }

  cout << endl;
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < widht; ++j) {
      if (j == 0 || j == widht - 1) {
        cout << "#";
      }
      if (i == y && j == x) {
        cout << "0";
      } else if (i == fruity && j == fruitx) {
        cout << "F";
      } else {
		  bool print = false;
		  for (int k = 0; k < nTail; ++k) {
			  if (tailX[k] == j && tailY[k] == i) {
				  print = true;
				  cout << "*";
			  }
		  }
		  if (!print) {
			  cout << " ";
		  }
      }
    }
    cout << endl;
  }

  for (int i = 0; i < widht + 1; ++i) {
    cout << "#";
  }
  cout << endl;
  cout << "Score: " << score << endl;
}

void input() {
  if (_kbhit()) {
    switch (_getch()) {
    case 'a':
      dir = LEFT;
      break;
    case 'd':
      dir = RIGHT;
      break;
    case 'w':
      dir = UP;
    case 's':
      dir = DOWN;
      break;
    case 'x':
      gameOver = true;
	  break;
    }
  }
}

void logic() {
	int prevX = tailX[0];
	int prevY = tailY[0]; 
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; ++i) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
	}
  switch (dir) {
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
    ++y;
    break;
  }

  if (x >= widht - 1)
	  x = 0;
  else if (x < 0)
	  x = widht - 2;

  if (y >= height)
	  y = 0;
  else if (y < 0)
	  x = height - 1;

  for (int i = 0; i < nTail; ++i) {
	  if (tailX[i] == x && tailY[i] == y) {
		  gameOver = true;
	  }
  }
  if (x == fruitx && y == fruity) {
    score += 10;
    fruitx = rand() % widht;
    fruity = rand() % height;
	++nTail;
  }
}

int main() {
  setup();
  while (!gameOver) {
    draw();
    input();
    logic();
  }
  return 0;
}