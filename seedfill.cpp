#include<graphics.h>
#include<iostream>
using namespace std;

void floodFill(int x, int y, int old, int fill)
{
	int current;
	current=getpixel(x,y);
	if(current==old)
	{
		putpixel(x,y,fill);
		delay(5);
		floodFill(x+1,y,old,fill);
		floodFill(x-1,y,old,fill);
		floodFill(x, y+1,old,fill);
		floodFill(x,y-1,old,fill);
	}
}

int main()
{
		int x,y,o=0;
		int gDriver=DETECT,gmode;
		initgraph(&gDriver,&gmode, NULL);
		rectangle(100,100,150,200);
		x=(100+150)/2;
		y=(100+200)/2;
		floodFill(x,y,o,4);
		getch();
		closegraph();
return 0;
}
