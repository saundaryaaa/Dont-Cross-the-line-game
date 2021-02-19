#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
char ch1,ch2,ch='a';
int m,n;
int gta=35;
void direc();
void right1();
void right2();
void down1();
void down2();
void left1();
void left2();
void up1();
void up2();
void draw();
void check(int op);
void win1();
void win2();
void name();
void menu();
void help();
void about();
void lvl();
struct cood
{
  int x;
  int y;
}head1,tail1,head2,tail2;
char a[200][200];
char p1[20],p2[20];
void main()
{
  int gd=DETECT,gm,i,j;
  char cho;
  initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
  head1.x=129;
  head1.y=239;
  tail1.x=129;
  tail1.y=239;
  head2.x=509;
  head2.y=239;
  tail2.x=509;
  tail2.y=239;
  for(i=0;i<200;i++)
  {
    for(j=0;j<200;j++)
    {
      a[i][j]='a';
    }
  }
  setbkcolor(BLACK);
  setcolor(YELLOW);
  rectangle(5,5,634,474);
  rectangle(6,6,633,473);
  settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,7);
  outtextxy(200,250,"DON'T CROSS THE LINE");
  delay(2500);
  cleardevice();
  menu();
  cleardevice();
  rectangle(5,5,634,474);
  rectangle(6,6,633,473);
  rectangle(119,64,519,414);
  setlinestyle(SOLID_LINE, 0, 2);
  right1();
  left2();
  draw();
  getch();
  closegraph();
}


void direc(char ele)
{
if(ele=='d' && ch1!='a'){
	right1();
	ch1='d';}
else if(ele=='s' && ch1!='w'){
	down1();
	ch1='s'; }
else if(ele=='a' && ch1!='d'){
	left1();
	ch1='a';}
else if(ele=='w' && ch1!='s'){
	up1();
	ch1='w'; }
else if(ele=='j' && ch2!='l'){
	 left2();
	 ch2='j';}
else if(ele=='k'&& ch2!='i'){
	down2();
	ch2='k';}
else if(ele=='l' && ch2!='j'){
	right2();
	ch2='l'; }
else if(ele=='i'&& ch2!='k'){
	up2();
	ch2='i';}
else if(ele=='y')
	exit(0);
}


void right1()
{
 head1.x=head1.x+1;
 check(2);
 m=4;
}

void right2()
{
 head2.x=head2.x+1;
 check(6);
 n=4;
}

void left1()
{
   head1.x=head1.x-1;
   check(4);
   m=2;
 }

void left2()
{
 head2.x=head2.x-1;
 check(8);
 n=2;
}

void down1()
{
 head1.y=head1.y+1;
 check(1);
 m=3;
}

void down2()
{
 head2.y=head2.y+1;
 check(5);
  n=3;
}
void up1()
{
 head1.y=head1.y-1;
 check(3);
 m=1;
}

void up2()
{
 head2.y=head2.y-1;
 check(7);
 n=1;
}


void draw()
{
char ch;
ch1='d';
ch2='j';
while(1)
  {
  setcolor(CGA_YELLOW);
  circle(head1.x,head1.y,0.5);
  setcolor(CGA_RED);
  circle(head2.x,head2.y,0.5);
  if(kbhit())
  {
     ch=getch();
     direc(ch);
  }
  direc(ch2);
  direc(ch1);
  delay(gta);
}
}


void check(int op)
{
  int i,j,k,l;
  if(head1.x<119||head1.x>519||head1.y<64||head1.y>414)
  {
    win2();
  }
  if(head2.x<119||head2.x>519||head2.y<64||head2.y>414)
  {
    win1();
  }
  i=(int)(head1.x-50)/2;
  j=(int)(head1.y-50)/2;
  k=(int)(head2.x-50)/2;
  l=(int)(head2.y-50)/2;
  switch(op)
  {
    case 1:if(a[j+1][i]=='b'){win2();}break;
    case 2:if(a[j][i+1]=='b'){win2();}break;
    case 3:if(a[j-1][i]=='b'){win2();}break;
    case 4:if(a[j][i-1]=='b'){win2();}break;
    case 5:if(a[l+1][k]=='b'){win1();}break;
    case 6:if(a[l][k+1]=='b'){win1();}break;
    case 7:if(a[l-1][k]=='b'){win1();}break;
    case 8:if(a[l][k-1]=='b'){win1();}break;
  }
  a[j][i]='b';
  a[l][k]='b';
}

void win1()
{
  delay(3000);
  cleardevice();
  rectangle(5,5,634,474);
  rectangle(6,6,633,473);
  outtextxy(200,200,"PLAYER 1 WINS!!!");
  outtextxy(400,400,"press any key to return...");
  getch();
  closegraph();
  main();
}

void win2()
{
  delay(3000);
  cleardevice();
  rectangle(5,5,634,474);
  rectangle(6,6,633,473);
  outtextxy(200,200,"PLAYER 2 WINS!!!");
  outtextxy(400,400,"press any key to return...");
  getch();
  closegraph();
  main();
}


void menu()
{
  char f;
  setbkcolor(BLACK);
  setcolor(YELLOW);
  rectangle(5,5,634,474);
  rectangle(6,6,633,473);
  settextstyle(TRIPLEX_SCR_FONT, HORIZ_DIR,1);
  outtextxy(70,70,"DON'T CROSS THE LINE");
  outtextxy(250,200,"1) NEW GAME");
  outtextxy(250,220,"2) LEVEL");
  outtextxy(250,240,"3) HELP");
  outtextxy(250,260,"4) ABOUT");
  outtextxy(250,280,"5) EXIT");
  f=getch();
  switch(f)
  {
    case '1':break;
    case '3':help();menu();break;
    case '4':about();menu();break;
    case '2':lvl();menu();break;
    case '5':exit(0);
    default:menu();
  }
}

void help()
{
  int FONT;
  cleardevice();
  rectangle(5,5,634,474);
  rectangle(6,6,633,473);
  gotoxy(30,2);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  outtextxy(70,70,"RULES:");
  settextstyle(FONT,HORIZ_DIR,3);
  outtextxy(205,100,"DO NOT TOUCH THE BOUNDARY LINE");
  outtextxy(205,130,"DO NOT TOUCH THE OPPONENT");
  outtextxy(205,160,"DO NOT OVERLAP ON YOUR OWN PATH");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  outtextxy(70,250,"CONTROLS:");
  settextstyle(FONT,HORIZ_DIR,3);
  outtextxy(205,280,"W,A,S,D KEYS FOR PLAYER 1");
  outtextxy(205,310,"I,J,K,L KEYS FOR PLAYER 2");
  outtextxy(400,400,"press any key to return...");
  getch();
  cleardevice();
}

void about()
{
  int FONT;
  cleardevice();
  rectangle(5,5,634,474);
  rectangle(6,6,633,473);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  outtextxy(265,50,"!!!DISCLAIMER!!!");
  settextstyle(FONT,HORIZ_DIR,3);
  outtextxy(75,100,"THE CONCEPT OF THIS GAME IS INSPIRED FROM A MINI GAME IN GTA 5");
  outtextxy(300,280,"THIS GAME IS CREATED BY,");
  outtextxy(300,300,"STUDENTS OF BE CSE");
  outtextxy(340,320,"PUNEET SG18337");
  outtextxy(340,340,"SAUNDARYA SG18344");
  outtextxy(340,360,"SAURABH SG18345");
  outtextxy(400,400,"press any key to return...");
  getch();
  cleardevice();
}

void lvl()
{
  char GTA5;
  cleardevice();
  rectangle(5,5,634,474);
  rectangle(6,6,633,473);
  outtextxy(70,70,"SELECT YOUR LEVEL");
  outtextxy(250,200,"1) EASY");
  outtextxy(250,220,"2) MEDIUM");
  outtextxy(250,240,"3) DIFFUCULT");
  GTA5=getch();
  switch(GTA5)
  {
    case '1':gta=gta+10;break;
    case '2':gta=gta;break;
    case '3':gta=gta-10;break;
    default:gta=gta;
  }
  cleardevice();
}
