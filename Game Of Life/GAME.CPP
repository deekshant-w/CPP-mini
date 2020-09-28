#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
int neigh(int x, int y , int pat[32][24]);
int temp[32][24];
union REGS in,out;
int callmouse()
{
in.x.ax=1;
int86(51,&in,&out);
return 1;
}
void mouseposi(int &xpos,int &ypos,int &click)
{
in.x.ax=3;
int86(51,&in,&out);
click=out.x.bx;
xpos=out.x.cx;
ypos=out.x.dx;
}
int mousehide()
{
in.x.ax=2;
int86(51,&in,&out);
return 1;
}
void setposi(int &xpos,int &ypos)
{
in.x.ax=4;
in.x.cx=xpos;
in.x.dx=ypos;
int86(51,&in,&out);
}

void plotter(int pat[32][24]){
int x,y;
rectangle(0,0,getmaxx(),getmaxy());
for(x=0;x<=640;x+=20){
	for(y=0;y<=480;y+=20){
		rectangle(x,y,x+20,y+20);
		}
	}
for(x=0;x<32;x++){
	for(y=0;y<24;y++){
		if(pat[x][y]==1){
			setfillstyle(1,RED);
			floodfill((x*20)+2,(y*20)+2,WHITE);
			}
		else if(pat[x][y]==2){
			setfillstyle(1,GREEN);
			floodfill((x*20)+2,(y*20)+2,WHITE);
			}
		else if(pat[x][y]==0){
			setfillstyle(1,BLACK);
			floodfill((x*20)+2,(y*20)+2,WHITE);
			}
		else{
		    setfillstyle(2,BLUE);
		    floodfill((x*20)+2,(y*20)+2,WHITE);
		    }
		}
	}

}

int neigh(int x, int y , int pat[32][24]){
	int n = 0;
	if(x==0 && y==0){
		if(pat[x][y+1]==1){
			n+=1;
			}
		if(pat[x+1][y]==1){
			n+=1;
			}

		if(pat[x+1][y+1]==1){
			n+=1;
			}
		}
	else if(x==31 && y==23){
		if(pat[x][y-1]==1){
			n+=1;
			}
		if(pat[x-1][y]==1){
			n+=1;
			}
		if(pat[x-1][y-1]==1){
			n+=1;
			}
		}
	else if(x==31 && y==0){
		if(pat[x][y+1]==1){
			n+=1;
			}
		if(pat[x-1][y]==1){
			n+=1;
			}
		if(pat[x-1][y+1]==1){
			n+=1;
			}
		}

	else if(x==0 && y==23){
		if(pat[x][y-1]==1){
			n+=1;
			}
		if(pat[x+1][y]==1){
			n+=1;
			}
		if(pat[x+1][y-1]==1){
			n+=1;
			}
		}
	else if(x==0){
		if(pat[x][y-1]==1){
			n+=1;
			}
		if(pat[x+1][y-1]==1){
			n+=1;
			}
		if(pat[x+1][y]==1){
			n+=1;
			}
		if(pat[x+1][y+1]==1){
			n+=1;
			}
		if(pat[x][y+1]==1){
			n+=1;
			}
		}


	else if(x==31){
		if(pat[x][y-1]==1){
			n+=1;
			}
		if(pat[x-1][y-1]==1){
			n+=1;
			}
		if(pat[x-1][y]==1){
			n+=1;
			}
		if(pat[x-1][y+1]==1){
			n+=1;
			}
		if(pat[x][y+1]==1){
			n+=1;
			}
		}

	else if(y==0){
		if(pat[x-1][y]==1){
			n+=1;
			}
		if(pat[x-1][y+1]==1){
			n+=1;
			}
		if(pat[x][y+1]==1){
			n+=1;
			}
		if(pat[x+1][y+1]==1){
			n+=1;
			}
		if(pat[x+1][y]==1){
			n+=1;
			}
		}

	else if(y==23){
		if(pat[x-1][y]==1){
			n+=1;
			}
		if(pat[x-1][y-1]==1){
			n+=1;
			}
		if(pat[x][y-1]==1){
			n+=1;
			}
		if(pat[x+1][y-1]==1){
			n+=1;
			}
		if(pat[x+1][y]==1){
			n+=1;
			}
		}
	  else{
		if(pat[x-1][y-1]==1){
		n+=1 ;
		}
		if(pat[x][y-1]==1){
		n+=1  ;
		}
		if(pat[x+1][y-1]==1){
		n+=1   ;
		}
		if(pat[x+1][y]==1){
		n+=1    ;
		}
		if(pat[x+1][y+1]==1){
		n+=1;
		}
		if(pat[x][y+1]==1){
		n+=1;
		}
		if(pat[x-1][y+1]==1){
		n+=1;
		}
		if(pat[x-1][y]==1){
		n+=1;
		}

		}
return(n);
}

void change(int arr[32][24]){
	int n;
	for(int x=0;x<32;x++){
		for(int y=0;y<24;y++){
			n = neigh(x,y,arr);
			if(arr[x][y] == 1){
				if(n<2){
					temp[x][y] = 0;
				}
				else if(n==2){
					temp[x][y] = 1;
				}
				else if(n==3){
					temp[x][y] = 1;
				}
				else if(n>3){
					temp[x][y] = 0;
				}
			}
			else if(temp[x][y] == 0 && n==3){
				temp[x][y] = 1;
			}
		}
	}
}


void main()
{
clrscr();
randomize();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi\\");
int x_a,y_a,a,b,cl,x,y,graph[32][24];
rectangle(0,0,getmaxx(),getmaxy());
for(x=0;x<32;x++){
	for(y=0;y<24;y++){
		graph[x][y]=0;
	}
}
for(x=0;x<32;x++){
	for(y=0;y<24;y++){
		temp[x][y]=0;
	}
}

plotter(graph);
a=100;
b=400;
setposi(a,b);
callmouse();
do
{
mouseposi(x,y,cl);
if(cl==1){
x_a = int(x/20);
y_a = int(y/20);
setfillstyle(1,RED);
bar(x_a*20,y_a*20,(x_a*20)+20,(y_a*20)+20);
graph[x_a][y_a] =1;
}
}while(!kbhit());
mousehide();
getch();
plotter(temp);
plotter(graph);

//for(int run=0;run<200;run++){
do{
	change(graph);

	//graph = temp
	for(x=0;x<32;x++){
		for(y=0;y<24;y++){
			graph[x][y] = temp[x][y];
		}
	}

	plotter(graph);
	}while(!kbhit());


getch();
}
