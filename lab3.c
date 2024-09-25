#include <stdio.h>
#include <graphics.h>

void drawCircle(int x_center, int y_center, int radius) {
	int x = radius;
	int y = 0;
	int err = 0;
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "");
	putpixel(x_center + x, y_center - y, WHITE);
	putpixel(x_center - x, y_center - y, WHITE);
	putpixel(x_center + y, y_center + x, WHITE);
	putpixel(x_center - y, y_center + x, WHITE); 

	if (radius > 0) {
		putpixel(x_center - x, y_center + y, WHITE);
		putpixel(x_center + x, y_center + y, WHITE);
		putpixel(x_center - y, y_center - x, WHITE);
		putpixel(x_center + y, y_center - x, WHITE);
	}

	err = 1 - radius;
	while (x > y) {
		if (err < 0) {
			y++;
			err += 2 * y + 1;
		}
		if (err >= 0) {
			x--;
			err -= 2*x + 1;
		}
		if (x < y) {
			break;
		}
		putpixel(x_center + x, y_center - y, WHITE);
		putpixel(x_center - x, y_center - y, WHITE);
		putpixel(x_center + y, y_center + x, WHITE);
		putpixel(x_center - y, y_center + x, WHITE); 
		if (x != y) {
			putpixel(x_center + y, y_center - x, WHITE);
			putpixel(x_center - y, y_center - x, WHITE);
			putpixel(x_center + x, y_center + y, WHITE);
			putpixel(x_center - x, y_center + y, WHITE);
		}
	}
	getchar();
	getchar();
	closegraph();
}
int main() {
	int x_center, y_center, radius;
	printf("Enter the center coordinates (x y): ");
	scanf("%d %d", &x_center, &y_center);
	printf("Enter the radius: ");
	scanf("%d", &radius);
	drawCircle(x_center, y_center, radius);
	return 0;
}