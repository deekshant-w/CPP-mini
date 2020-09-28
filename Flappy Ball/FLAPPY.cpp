#include <iostream.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
void main ()
{
clrscr();
int a,b,c,d,e,f,g ;
clock_t start,end;
int gd= DETECT, gm;
initgraph(&gd, &gm, "c://tc//bgi//");
setfillstyle(1,CYAN);
bar(0,0,getmaxx(),getmaxy());
setfillstyle(1,YELLOW);
int fps=0;
b=250;
loop:
start = clock();
c=rand()%100;
for(a=0; a<=getmaxx(); a++)
	{
	fps++;
	a=a+1;
	setfillstyle(1,RED);
	bar(getmaxx()-a,0,getmaxx()-60-a,50+c);
	bar(getmaxx()-60-a,200+c,getmaxx()-a,getmaxy());
	setcolor(BLACK);
	circle(50,b+a,20);
	delay(10);
	setcolor(CYAN);
	circle(50,b+a,20);
	setfillstyle(1,CYAN);
	bar(getmaxx()-a,0,getmaxx()-60-a,50+c);
	bar(getmaxx()-60-a,200+c,getmaxx()-a,getmaxy());
	if(kbhit())
		{
		getch();
		b=b-50;
		}
	if(a+b>=getmaxy() || a+b<=0 )
		{
		exit(0);
		}
	if(getmaxx()-a-60<=65 )
		{
		if(b+a-5<=50+c || b+a-5>=200+c)
			{
			exit(0);
			}
		}
	end=clock();
	if(end-start>19)
		{
		gotoxy(1,1);
		cout<<"   ";
		gotoxy(1,1);
		cout<<fps;
		fps=0;
		start=clock();
		}
	}
b=b+a;
goto loop;
}
