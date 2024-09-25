#include<graphics.h>
#include<math.h>
// #include<conio.h>

int main(){
	int x0,y0,x1,y1,i=0;
	float delx,dely,len,x,y;
	int gr=DETECT,gm;
	printf("\n****** DDA Line Drawing Algorithm ***********");

	printf("\n Please enter the starting coordinate of x, y = ");
	scanf("%d %d", &x0,&y0);
	printf("\n Enter the final coordinate of x, y = ");
	scanf("%d %d",&x1,&y1);

	dely=abs(y1-y0);
	delx=abs(x1-x0);

	if(delx<dely){
		len = dely;
	}else{
		len=delx;
	}

	delx=(x1-x0)/len;
	dely=(y1-y0)/len;
	x=x0+0.5;
	y=y0+0.5;

	initgraph(&gr,&gm, NULL);
	do {
		putpixel(x,y,3);
		x=x+delx;
		y=y+dely;
		i++;
		delay(30);
	} while(i<=len);

	getchar();
	getchar();
	closegraph();
	return 0;
}