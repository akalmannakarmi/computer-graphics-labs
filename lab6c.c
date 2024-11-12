#include<stdio.h>
// #include<conio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.14159

int maxx,maxy,midx,midy;

void axis(){
	cleardevice();
	line(midx,0,midx,maxy);
	line(0,midy,maxx,midy);
}
void rotateXY(int x1, int y1, int z, float angle) {
    float rad = angle * PI / 180; 
    int x2, y2;
    x2 = midx + (x1 - midx) * cos(rad) - (y1 - midy) * sin(rad);
    y2 = midy + (x1 - midx) * sin(rad) + (y1 - midy) * cos(rad); 
    bar3d(x2, y2, x2 + 10, y2 + 10, z, 1);
}

int main(){
    int x = 50, y = -100, z = 10;
    float angle;
    int gd = DETECT, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "");

    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy / 2;

    axis();
    bar3d(midx + x, midy + y, midx + x + 10, midy + y + 10, z, 1); 
    printf("Enter rotation angle (in degrees): ");
    scanf("%f", &angle);
    rotateXY(midx + x, midy + y, z, angle); 
    printf("After rotation");
	
    getchar();  
    getchar();  
    closegraph();
    return 0;
}