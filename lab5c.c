#include <stdio.h>
#include <graphics.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main() {
    int gd = DETECT, gm;

    int x1 = 100, y1 = 200;
    int x2 = 250, y2 = 250;
    int x3 = 200, y3 = 100;
    
    float sx, sy;

    printf("Enter the scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);

    initgraph(&gd, &gm, (char *)"");
    printf("Triangle before scaling\n");
    drawTriangle(x1, y1, x2, y2, x3, y3);
    
    int new_x1 = x1 * sx;
    int new_y1 = y1 * sy;
    int new_x2 = x2 * sx;
    int new_y2 = y2 * sy;
    int new_x3 = x3 * sx;
    int new_y3 = y3 * sy;

    printf("Triangle after scaling\n");
    drawTriangle(new_x1, new_y1, new_x2, new_y2, new_x3, new_y3);

    getchar();
    getchar();
    closegraph();
    return 0;
}