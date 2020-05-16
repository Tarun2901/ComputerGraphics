#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<bits/stdc++.h>
#include <SDL/SDL.h> 
using namespace std;

int fact(int n)
{
    if(n>1)
        return n*fact(n-1);
    else
        return 1;
}

void bezier(int px[], int py[], int n)
{
    float u,x,y,b;

    putpixel(px[0],py[0],WHITE);

    int nfact=fact(n-1);

    for(u=0.0001;u<1;u+=0.0001)
    {
        x=0;
        y=0;

        for(int i=0;i<n;i++)
        {
            b=(nfact*pow(1-u,n-1-i)*pow(u,i))/(fact(n-1-i)*fact(i));

            x+=b*px[i];
            y+=b*py[i];
        }

        putpixel(x,y,WHITE);
    }

    putpixel(px[n-1],py[n-1],WHITE);
}

void k1(int x, int y, int n){
    int x1[4] = {x, x-n, x-n, x};
    int y1[4] = {y, y-n, y+n, y};
    bezier(x1,y1,4);
}
void k2(int x, int y, int n){
    int x1[4] = {x, x-n, x-n, x};
    int y1[4] = {y, y-n-10, y+n+10, y};
    bezier(x1,y1,4);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    const int n = 4;
    int px[4], py[4];

    // Ta
    
    px[0] = 65, px[1] =27 , px[2] = 44, px[3] = 138;
    py[0] = 281, py[1] = 179, py[2] = 147, py[3] = 149;
    bezier(px,py,4);
    line(138,65,138,281);
    
    //Ru
     px[0] = 220, px[1] =263, px[2] = 276, px[3] = 206;
    py[0] = 65, py[1] = 75, py[2] = 130, py[3] = 149;
    bezier(px,py,4);
    line(206,149,255,281);
     k1(240,160,25);
     line(240,160,250,185);
    //N
    px[0] = 310, px[1] =320, px[2] = 403, px[3] = 409;
    py[0] = 65, py[1] = 204, py[2] = 201, py[3] = 65;
    bezier(px,py,4);
    line(430,65,430,281);
 
    line(50,65,460,65);
    getch();
    return 0;
}
