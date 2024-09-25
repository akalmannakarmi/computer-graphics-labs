#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawCheckerboard(int rows, int cols, int cellSize) {
	int i, j;
	int x1, y1, x2, y2;
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);

	for (i=0; i< rows; i++) {
		for (j = 0; j<cols; j++) {
			x1 = j * cellSize;
			y1 = i * cellSize;
			x2=x1 + cellSize;
			y2=y1;
			int dx = x2 - x1;
			int dy = y2 - y1;
			int steps = abs(dx) > abs(dy) ? abs(dx): abs(dy);
			float xIncrement = (float)dx/(float)steps;
			float yIncrement = (float)dy / (float)steps;
			float x = x1, y=y1;

			putpixel(round(x), round(y), WHITE);
			for (int k = 0; k < steps; k++) {
				x += xIncrement;
				y += yIncrement;
				putpixel(round(x), round(y), WHITE);
			}

			x2 = x1;
			y2 = y1 + cellSize;
			dx = x2 - x1;
			dy = y2 - y1;
			steps= abs(dx) > abs(dy) ? abs(dx): abs(dy);
			xIncrement = (float)dx/(float)steps;
			yIncrement = (float)dy/(float)steps;
			x = x1;
			y = y1;

			putpixel(round(x), round(y), WHITE);
			for (int k = 0; k < steps; k++) {
				x += xIncrement;
				y += yIncrement;
				putpixel(round(x), round(y), WHITE);
			}
		}
	}
	delay(10000);
	closegraph();
}

int main() {
	int rows = 16;
	int cols = 16;
	int cellSize = 64;
	drawCheckerboard(rows, cols, cellSize);
	return 0;
}