#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<dos.h>
#include<graphics.h>







struct save{
char uname[15];
char pwd[10];
char b[10][10];
int a[10][10];
};

char ch;
void text(char x[200])
{
for(int i=0;i<strlen(x);i++)
{
cout<<x[i];
delay(50);
}
}

void rules()
{
cout<<"                                Minesweeper"<<endl;
text("There is a 10x10 grid randomly filled with 13 mines");
text("\nThe aim of the game is to reveal all the tiles that do not contain mines ");
text("\nWhen a tile is opened, the number of mines in a 1 block radius are revealed");
text("\nUse this information to reveal all the tiles that do not contain the mines");
text("\nThe game ends if you hit a mine");
text("\nHave Fun!");
getch();
clrscr();
}
void reveal(int h,int n,int a[][10],char b[][10]){
for(int o=h-1,l=1;l<=3;l++,o++){
for(int p=n-1,e=1;e<=3;p++,e++){
if(a[o][p]!=1&&(o>=0&&o<10)&&(p>=0&&p<10)){
int ct=0;
for(int r=o-1,l=1;l<=3;l++,r++){
for(int w=p-1,e=1;e<=3;w++,e++){
if(a[r][w]==1&&(r>=0&&r<10)&&(w>=0&&w<10)&&(b[r][w]!='F')){ct++;}
}}
b[o][p]=48+ct;
}}}}

void minesweep()
{
clrscr();
int m=0;
begin:
clrscr();
int k;
int a[10][10]={0};
char b[10][10];
for(int j=0;j<10;j++){
for(int o=0;o<10;o++){
b[j][o]='X';
}}
randomize();
int z=random(10);
int x=random(10);
a[z][x]=1;
sect1:
{int z1=random(10);
int x1=random(10);
if(a[z1][x1]==1){goto sect1;}
a[z1][x1]=1;}
sect2:
{
int z2=random(10);
int x2=random(10);
if(a[z2][x2]==1){goto sect2;}
a[z2][x2]=1;

}
sect3:
{int z3=random(10);
int x3=random(10);
if(a[z3][x3]==1){goto sect3;}
a[z3][x3]=1;}
sect4:{
int z4=random(10);
int x4=random(10);
if(a[z4][x4]==1){goto sect4;}
a[z4][x4]=1;}
sect5:{
int z5=random(10);
int x5=random(10);
if(a[z5][x5]==1){goto sect5;}
a[z5][x5]=1;}
sect6:{
int z6=random(10);
int x6=random(10);
if(a[z6][x6]==1){goto sect6;}
a[z6][x6]=1;}
sect7:{
int z7=random(10);
int x7=random(10);
if(a[z7][x7]==1){goto sect7;}
a[z7][x7]=1;}
sect8:{
int z8=random(10);
int x8=random(10);
if(a[z8][x8]==1){goto sect8;}
a[z8][x8]=1;}
sect9:{
int z9=random(10);
int x9=random(10);
if(a[z9][x9]==1){goto sect9;}
a[z9][x9]=1;}
sect10:{
int z10=random(10);
int x10=random(10);
if(a[z10][x10]==1){goto sect10;}
a[z10][x10]=1;}
sect11:{
int z11=random(10);
int x11=random(10);
if(a[z11][x11]==1){goto sect11;}
a[z11][x11]=1;}
sect12:{
int z12=random(10);
int x12=random(10);
if(a[z12][x12]==1){goto sect12;}
a[z12][x12]=1;}

for(j=0;j<10;j++){
cout<<j+1<<" ";
for(int o=0;o<10;o++){
cout<<a[j][o]<<" ";
}
cout<<endl;
}
cout<<endl<<endl;
int dead=0;
if(m==0)
{int gd=DETECT,gm;
initgraph(&gd,&gm,"L:/TURBOC3/BGI/");
settextstyle(SANS_SERIF_FONT,0,6);
outtextxy(150,60,"WELCOME TO");
outtextxy(150,200,"MINESWEEPER");
getch();
closegraph();
char ch;
cout<<"Do you want to read the rules? Enter y/n";
ch=getch();
if(ch=='y')
rules();}
do{
textcolor(LIGHTRED);
clrscr();
textcolor(CYAN);
cprintf("                                Minesweeper");
cout<<endl<<endl;
/*
for(int j=0;j<10;j++){
for(int o=0;o<10;o++){
cout<<a[j][o]<<" ";
}
cout<<endl;}
cout<<endl<<endl;
*/
cout<<"                        1 2 3 4 5 6 7 8 9 10"<<endl<<endl;
for(j=0;j<10;j++){
cout<<"\t\t"<<j+1;
cout<<"\t";
for(int o=0;o<10;o++){
if(b[j][o]=='0') textcolor(GREEN);
else if(b[j][o]=='1') textcolor(YELLOW);
else if(b[j][o]=='2') textcolor(LIGHTRED);
else if(b[j][o]=='3') textcolor(MAGENTA);
else if(b[j][o]=='4') textcolor(RED);
else if(b[j][o]=='5') textcolor(BROWN);
else if(b[j][o]=='6') textcolor(LIGHTGRAY);
else if(b[j][o]=='F'||b[j][o]=='f') textcolor(WHITE);
else textcolor(LIGHTBLUE);
char s[3];
s[0]=b[j][o]; s[1]=' '; s[2]='\0';
cprintf(s);
}
cout<<endl;
}

int mine=0;
for(int f=0;f<10;f++){
for(int e=0;e<10;e++){
if(b[e][f]=='X'||b[e][f]=='F'){mine++;}}}
if(mine==13){
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"L:/TURBOC3/BGI/");
settextstyle(SANS_SERIF_FONT,0,45);
outtextxy(100,100,"You Win");

getch();
closegraph();
clrscr();

cout<<"\n				Do you want to play again <y/n>? ";
cin>>ch;
if(ch=='Y'||ch=='y')
{m++;
goto begin;
}
//getch();
else
exit(0);
}
int h,n;
cout<<endl<<endl;
cout<<"\t\t\t";
select:
int v;
cout<<"Enter 1 to reveal and 2 to flag, 3 to unflag, 4 to exit ,5 to save, 6 to resume a saved game"<<endl;
cin>>v;
if(v==1){
cout<<"\n\t\t\tEnter the row and column";
cout<<endl<<"\t\t\tEnter 20 20 to exit ";
values:
cin>>h>>n;
h--;
n--;
if(b[h][n]!='X'&&((h!=19)&&(n!=19))&&b[h][n]=='F')
{
cout<<"\n\t\t\tEnter coordinates again ";
goto values;
}
if((h<=-1||n<=-1)||(h>=10&&h!=19||n>=10&&n!=19))
{
cout<<"\n\t\t\tEnter coordinates again ";
goto values;
}
if(a[h][n]==1){
cout<<"\t\t\tyou hit a mine :(";
dead=1;
cout<<"\t\t\tDo you want to play again <y/n>? ";
cin>>ch;
if(ch=='Y'||ch=='y')
{
m++;
goto begin;}
//getch();
else
exit(0);

getch();exit(0);}
if(h==19){
exit(0);}
reveal(h,n,a,b);}
else if(v==2)
{
cout<<"Enter the row and column ";
jo:
cin>>h>>n;
h--;n--;
if(b[h][n]=='X'){
b[h][n]='F';
}
else
{
cout<<"Enter coordinates again ";
goto jo;
}}
else if(v==3){
cout<<"Enter the row and column ";
mo:
cin>>h>>n;
h--;n--;
if(b[h][n]=='F'){
b[h][n]='X';}
else
{
cout<<"To enter coordinates again press 1, to go back to selection press 2";int p;
cin>>p;
if(p==1)
{
cout<<"Enter coordinates again ";
goto mo;
}
if(p==2)
goto select;
}}


else if(v==4){
getch();
exit(0);}
else if(v==5){
save game;
for(int i=0;i<10;i++){
for(int j=0;j<10;j++){
game.a[i][j]=a[i][j];
game.b[i][j]=b[i][j];}}
cout<<"Enter name ";
gets(game.uname);
cout<<"\nEnter password ";
gets(game.pwd);
fstream f("save.dat",ios::in|ios::binary|ios::app|ios::out);
if(!f){ cout<<"Error "; return;}
f.write((char*)&game,sizeof(game));
f.close();
exit(1);
}

else if (v==6){
fstream f("save.dat",ios::in|ios::binary|ios::out);
save old;
char user[15],pass[15];
cout<<"Enter username ";
gets(user);
cout<<"\nEnter password ";
gets(pass);
int ct=0;
while(f.read((char*)&old,sizeof(old)))
{

if(!strcmpi(old.uname,user)&&!strcmpi(old.pwd,pass))
{
for(int i=0;i<10;i++){
for(int j=0;j<10;j++){
a[i][j]=old.a[i][j];
b[i][j]=old.b[i][j];}}
ct++;
clrscr();
cout<<"\t\t\t1 2 3 4 5 6 7 8 9 10"<<endl<<endl;
for(j=0;j<10;j++){
cout<<"\t\t"<<j+1;
cout<<"\t";
for(int o=0;o<10;o++){
if(b[j][o]=='0') textcolor(GREEN);
else if(b[j][o]=='1') textcolor(YELLOW);
else if(b[j][o]=='2') textcolor(LIGHTRED);
else if(b[j][o]=='3') textcolor(MAGENTA);
else if(b[j][o]=='4') textcolor(RED);
else if(b[j][o]=='5') textcolor(BROWN);
else if(b[j][o]=='6') textcolor(LIGHTGRAY);
else if(b[j][o]=='F'||b[j][o]=='f') textcolor(WHITE);
else textcolor(LIGHTBLUE);
char s[3];
s[0]=b[j][o]; s[1]=' '; s[2]='\0';
cprintf(s);
}
cout<<endl;
}
goto select;
}
else
{
fstream g("temp.dat",ios::binary|ios::out|ios::app);
if(!g){ cout<<"Error ";return;}
/*while(g.write((char*)&old,sizeof(old)));
remove("save.dat");
rename("temp.dat","save.dat")*/;

}
}
if(ct==0)cout<<"Save data not found ";
goto select;
}

}while(1);
}



int r;
long double score=0;
struct player{
public:
int ax,ay,bx,by,cx,cy;
player(){
ax=50;ay=400;bx=25;by=450;cx=75;cy=450;}
}pl;
long double fpsct=0;
int playeralive=1;

void playerdisp(){
{
/*int a[]={0,0,getmaxx(),0,getmaxx(),getmaxy(),0,getmaxy()};
setfillstyle(1,BLACK);
fillpoly(4,a);*/
   line(pl.ax, pl.ay,pl.cx,pl.cy);
   line(pl.bx, pl.by, pl.cx, pl.cy);
   line(pl.bx, pl.by, pl.ax, pl.ay);
   }
   }

int randomizer(){
srand(r);
int p = 40 + rand() % 400;
r=p;
return p;
}




class data{
public:
int lane1,lane2,lane3,lane4,lane5,lane6;
int lane1dead,lane2dead,lane3dead,lane4dead,lane5dead,lane6dead;
int lane1spawnframes,lane2spawnframes,lane3spawnframes,lane4spawnframes,lane5spawnframes,lane6spawnframes;
long double bulletdead;
long double bulletno;
data()
{
lane1=0,lane2=0,lane3=0,lane4=0,lane5=0;
lane1dead=0,lane2dead=0,lane3dead=0,lane4dead=0,lane5dead=0,lane6dead;
lane1spawnframes=0,lane2spawnframes=0,lane3spawnframes=0,lane4spawnframes=0,lane5spawnframes=0,lane6spawnframes=0;
bulletno=0;
bulletdead=0;
}}obj;

void spawnlane1(){
obj.lane1++;
obj.lane1spawnframes=0;
}


void spawnlane2(){
obj.lane2++;
obj.lane2spawnframes=0;
}


void spawnlane3(){
obj.lane3++;
obj.lane3spawnframes=0;
}


void spawnlane4(){
obj.lane4++;
obj.lane4spawnframes=0;
}

void spawnlane5(){
obj.lane5++;
obj.lane5spawnframes=0;
}



struct bullet{
int ax,ay,bx,by;
void init(int cx, int cy, int dx, int dy){
ax=cx;ay=cy;bx=dx;by=dy;
}
void disp(){
  line(ax, ay,bx,by);
}
void update(){
{ay-=10;by-=10;playerdisp();disp();delay(2);ay-=15;by-=15;}
if(by<30)obj.bulletdead++;
}

}bullet[1000];

struct enemylane1{
public:
float ax,ay,bx,by,cx,cy,count,red;
int alive;
float movespeed;
enemylane1(){
ax=50;ay=50;bx=25;by=5;cx=75;cy=5;
alive=1;
count=0;
randomize();
red=randomizer();
movespeed=randomizer()%3+2;
movespeed=movespeed/2;
}
void disp(){

   if(alive==1){
   if(red==1)setcolor(RED);
   line(ax, ay,cx,cy);
   line(bx, by, cx, cy);
   line(bx, by, ax, ay);
   if(red==1)setcolor(WHITE);
   }}

void update(){
ay+=movespeed;by+=movespeed;cy+=movespeed;playerdisp();disp();delay(2);ay+=movespeed;by+=movespeed;cy+=movespeed;
if(by>getmaxy()-50&&alive==1){obj.lane1dead++;if(red==1)playeralive=0;}
//obj.lane1spawnframes++;

for(int i=obj.bulletdead;i<obj.bulletno;i++){
if((bullet[i].bx>bx)&&(bullet[i].bx<cx)&&(bullet[i].by<ay)&&(bullet[i].by>by)){
{alive=0;score+=100;obj.lane1dead++;
obj.bulletdead++;
}
}}
if(alive==1){if(((pl.bx>bx&&pl.bx<cx||pl.cx>bx&&pl.cx<cx)&&(pl.ay<ay&&pl.ay>by))||(pl.cx>bx&&pl.cx<cx&&pl.cy>by&&pl.cy<ay))playeralive=0;}

}
}en1[100];
struct enemylane2{
public:
float ax,ay,bx,by,cx,cy,alive,red;
float movespeed;
enemylane2(){
ax=50+100;ay=50;bx=25+100;by=5;cx=75+100;cy=5;alive=1;
randomize();
red=randomizer()%3;
movespeed=randomizer()%3+2;
movespeed=movespeed/2;

}
void disp(){
{
  if(alive==1){
  if(red==1)setcolor(RED);
   line(ax, ay,cx,cy);
   line(bx, by, cx, cy);
   line(bx, by, ax, ay);
   if(red==1)setcolor(WHITE);
   }
   }}
void update(){
ay+=movespeed;by+=movespeed;cy+=movespeed;playerdisp();disp();delay(2);ay+=movespeed;by+=movespeed;cy+=movespeed;
if(by>getmaxy()-50){obj.lane2dead++;if(red==1)playeralive=0;}

//obj.lane2spawnframes++;
for(int i=obj.bulletdead;i<obj.bulletno;i++){
if((bullet[i].bx>bx)&&(bullet[i].bx<cx)&&(bullet[i].by<ay)&&(bullet[i].by>by)){
score+=100;
alive=0;
obj.lane2dead++;
obj.bulletdead++;
}}
if(alive==1){if(((pl.bx>bx&&pl.bx<cx||pl.cx>bx&&pl.cx<cx)&&(pl.ay<ay&&pl.ay>by))||(pl.cx>bx&&pl.cx<cx&&pl.cy>by&&pl.cy<ay))playeralive=0;}
}
}en2[100];

struct enemylane3{
public:
float ax,ay,bx,by,cx,cy,alive,red;
float movespeed;
enemylane3(){
ax=50+200;ay=50;bx=25+200;by=5;cx=75+200;cy=5;alive=1;
red=randomizer()%3;
movespeed=randomizer()%3+2;
movespeed=movespeed/2;
}
void disp(){
{
   if(alive==1){

  if(red==1)setcolor(RED);
   line(ax, ay,cx,cy);
   line(bx, by, cx, cy);
   line(bx, by, ax, ay);
   if(red==1)setcolor(WHITE);
   }
   }}
void update(){
ay+=movespeed;by+=movespeed;cy+=movespeed;playerdisp();disp();delay(2);ay+=movespeed;by+=movespeed;cy+=movespeed;
if(by>getmaxy()-50&&alive==1){obj.lane3dead++;if(red==1)playeralive=0;}
//obj.lane3spawnframes++;
if(alive==1){if(((pl.bx>bx&&pl.bx<cx||pl.cx>bx&&pl.cx<cx)&&(pl.ay<ay&&pl.ay>by))||(pl.cx>bx&&pl.cx<cx&&pl.cy>by&&pl.cy<ay))playeralive=0;}
for(int i=obj.bulletdead;i<obj.bulletno;i++){
if((bullet[i].bx>bx)&&(bullet[i].bx<cx)&&(bullet[i].by<ay)&&(bullet[i].by>by)){
score+=100;
alive=0;
obj.lane3dead++;
obj.bulletdead++;
}}}
}en3[100];


struct enemylane4{
public:
float ax,ay,bx,by,cx,cy,alive,red;
float movespeed;
enemylane4(){
ax=50+300;ay=50;bx=25+300;by=5;cx=75+300;cy=5;alive=1;
randomize();
red=randomizer()%3;
movespeed=randomizer()%3+2;
movespeed=movespeed/2;
}
void disp(){
{
   if(alive==1){
   if(red==1)setcolor(RED);
   line(ax, ay,cx,cy);
   line(bx, by, cx, cy);
   line(bx, by, ax, ay);
   if(red==1)setcolor(WHITE);
   }
   }}
void update(){
ay+=movespeed;by+=movespeed;cy+=movespeed;playerdisp();disp();delay(2);ay+=movespeed;by+=movespeed;cy+=movespeed;
if(alive==1){if(((pl.bx>bx&&pl.bx<cx||pl.cx>bx&&pl.cx<cx)&&(pl.ay<ay&&pl.ay>by))||(pl.cx>bx&&pl.cx<cx&&pl.cy>by&&pl.cy<ay))playeralive=0;}
if(by>getmaxy()-50){obj.lane4dead++;if(red==1)playeralive=0;}
//obj.lane4spawnframes++;
for(int i=obj.bulletdead;i<obj.bulletno;i++){
if((bullet[i].bx>bx)&&(bullet[i].bx<cx)&&(bullet[i].by<ay)&&(bullet[i].by>by)){
score+=100;
alive=0;
obj.lane4dead++;
obj.bulletdead++;
}}
}

}en4[100];

struct enemylane5{
public:
float ax,ay,bx,by,cx,cy,alive,red;
float movespeed;
enemylane5(){
ax=50+400;ay=50;bx=25+400;by=5;cx=75+400;cy=5;alive=1;
randomize();
red=randomizer()%3;
movespeed=randomizer()%3+2;
movespeed=movespeed/2;
}
void disp(){
{if(alive==1){
  if(red==1);
  setcolor(RED);
   line(ax, ay,cx,cy);
   line(bx, by, cx, cy);
   line(bx, by, ax, ay);
   if(red==1);
   setcolor(WHITE);
   }
   }}
void update(){
ay+=movespeed;by+=movespeed;cy+=movespeed;playerdisp();disp();delay(2);ay+=movespeed;by+=movespeed;cy+=movespeed;
if(by>getmaxy()-50&&alive==1){obj.lane5dead++;if(red==1)playeralive=0;}
//obj.lane5spawnframes++;
if(alive==1){if(((pl.bx>bx&&pl.bx<cx||pl.cx>bx&&pl.cx<cx)&&(pl.ay<ay&&pl.ay>by))||(pl.cx>bx&&pl.cx<cx&&pl.cy>by&&pl.cy<ay))playeralive=0;}
for(int i=obj.bulletdead;i<obj.bulletno;i++){
if((bullet[i].bx>bx)&&(bullet[i].bx<cx)&&(bullet[i].by<ay)&&(bullet[i].by>by)){
score+=100;
alive=0;
obj.lane5dead++;
obj.bulletdead++;
}}
}}en5[100];


struct enemylane6{
public:
float ax,ay,bx,by,cx,cy,alive,red;
float movespeed;
enemylane6 *next;
enemylane6(){
ax=50+500;ay=50;bx=25+500;by=5;cx=75+500;cy=5;
alive=1;
next=NULL;
red=randomizer()%3;
movespeed=randomizer()%3+2;
movespeed=movespeed/2;
}
void disp(){
{
   if(alive==1){
   if(red==1)setcolor(RED);
   line(ax, ay,cx,cy);
   line(bx, by, cx, cy);
   line(bx, by, ax, ay);
   if(red==1)setcolor(WHITE);
   }
   }}
void update(){
ay+=movespeed;by+=movespeed;cy+=movespeed;playerdisp();disp();delay(2);ay+=movespeed;by+=movespeed;cy+=movespeed;
if(by>getmaxy()-50)
{
enemylane6 *temp=queue.front;
queue.front=queue.front->next;
delete temp;
if(red==1)playeralive=0;}

//obj.lane6spawnframes++;
if(alive==1){if(((pl.bx>bx&&pl.bx<cx||pl.cx>bx&&pl.cx<cx)&&(pl.ay<ay&&pl.ay>by))||(pl.cx>bx&&pl.cx<cx&&pl.cy>by&&pl.cy<ay))playeralive=0;}
if(alive==1){
for(int i=obj.bulletdead;i<obj.bulletno;i++){
if((bullet[i].bx>bx)&&(bullet[i].bx<cx)&&(bullet[i].by<ay)&&(bullet[i].by>by)){
score+=100;
alive=0;
enemylane6 *temp=queue.front;
queue.front=queue.front->next;
delete temp;
obj.bulletdead++;
}}
}}
};

struct q
{
enemylane6 *front;
enemylane6 *rear;
q(){front=NULL;
rear=NULL;
}
}queue;

void spawnlane6(){
enemylane6 *node=new enemylane6;
if(queue.front==NULL){queue.front=node;queue.rear=node;}
else{queue.rear->next=node;queue.rear=node;}
obj.lane6spawnframes=0;
}

void spawnbullet(int x,int y){
obj.bulletno++;
bullet[obj.bulletno-1].init(x,y,x,y-50);
}
int dead=0;
void updateplayer(){

obj.lane1spawnframes++;
obj.lane2spawnframes++;
obj.lane3spawnframes++;
obj.lane4spawnframes++;
obj.lane5spawnframes++;
obj.lane6spawnframes++;



cout<<" Score: "<<score;
cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
if(kbhit()){
char ch=getch();
if(ch=='d'){if(pl.cx<getmaxx()-5){pl.ax+=10;pl.bx+=10;pl.cx+=10;playerdisp();delay(2);pl.ax+=10;pl.bx+=10;pl.cx+=10;}}
if(ch=='a'){if(pl.ax>30){pl.ax-=10;pl.bx-=10;pl.cx-=10;playerdisp();delay(2);pl.ax-=10;pl.bx-=10;pl.cx-=10;}}
if(ch=='w'){if(pl.by>50){pl.ay-=10;pl.by-=10;pl.cy-=10;playerdisp();delay(2);pl.ay-=10;pl.by-=10;pl.cy-=10;}}
if(ch=='s'){if(pl.by<getmaxy()-10){pl.ay+=10;pl.by+=10;pl.cy+=10;playerdisp();delay(2);pl.ay+=10;pl.by+=10;pl.cy+=10;}}
if(ch==27)exit(1);
//if(ch=='e')spawnlane1();
if(ch=='\r')spawnbullet(pl.ax,pl.ay);}
playerdisp();
return;
}
void refresh(){
int a[]={0,0,getmaxx(),0,getmaxx(),getmaxy(),0,getmaxy()};
setfillstyle(1,BLACK);
fillpoly(4,a);
}

void rules1945()
{
clrscr();
cout<<"                                 1945"<<endl;
text("Use WASD to move your plane around.");
text("\nPress Enter to shoot. ");
text("\nYour objective isddd to shoot as many enemy planes as possible.");
text("\nDon't let the red planes reach the end of the screen.");
text("\nDo not collide with any planes.");
text("\nHave Fun!");
getch();
clrscr();
}

void air(){
clrscr();
char ch;
cout<<"Do you want to read the rules? Enter y/n";
ch=getch();
if(ch=='y')rules1945();

fpsct++;
srand(time(NULL));
r= 40 + rand() % 400;
int gd = DETECT, gm;
initgraph(&gd, &gm, "L:\\TURBOC3\\BGI");
settextstyle(SANS_SERIF_FONT,0,6);
outtextxy(150,60,"WELCOME TO");
outtextxy(150,200,"   1945");
getch();

cout<<endl;
while(playeralive){
if((fmod(fpsct,randomizer())==0)&&obj.lane1spawnframes>60){
spawnlane1();}
if((fmod(fpsct,randomizer())==0)&&obj.lane2spawnframes>60){
spawnlane2();}
if((fmod(fpsct,randomizer())==0)&&obj.lane3spawnframes>60){
spawnlane3();}
if((fmod(fpsct,randomizer())==0)&&obj.lane4spawnframes>60){
spawnlane4();}
if((fmod(fpsct,randomizer())==0)&&obj.lane5spawnframes>60){
spawnlane5();}
if((fmod(fpsct,randomizer())==0)&&obj.lane6spawnframes>60){
spawnlane6();}

int a[]={0,0,getmaxx(),0,getmaxx(),getmaxy(),0,getmaxy()};
setfillstyle(1,BLACK);
fillpoly(4,a);
for(int i=obj.lane1dead;i<=obj.lane1;i++){
en1[i].update();
en1[i].disp();
}
for(i=obj.lane2dead;i<=obj.lane2;i++){
en2[i].update();
en2[i].disp();
}
for(i=obj.lane3dead;i<=obj.lane3;i++){
en3[i].update();
en3[i].disp();
}
for(i=obj.lane4dead;i<=obj.lane4;i++){
en4[i].update();
en4[i].disp();
}
for(i=obj.lane5dead;i<=obj.lane5;i++){
en5[i].update();
en5[i].disp();
}
for(enemylane6 *p=queue.front;p!=NULL;p=p->next){
p->update();
p->disp();
}
updateplayer();
for(i=obj.lane1dead;i<=obj.lane1;i++){
en1[i].disp();
}
for(i=obj.lane2dead;i<=obj.lane2;i++){
en2[i].disp();
}
for(i=obj.lane3dead;i<=obj.lane3;i++){
en3[i].disp();
}
for(i=obj.lane4dead;i<=obj.lane4;i++){
en4[i].disp();
}
for(i=obj.lane5dead;i<=obj.lane5;i++){
en5[i].disp();
}
for(p=queue.front;p!=NULL;p=p->next){
p->disp();
}
for(i=obj.bulletdead;i<obj.bulletno;i++){
bullet[i].update();
bullet[i].disp();
}

fpsct++;
delay(5);};

int a[]={0,0,getmaxx(),0,getmaxx(),getmaxy(),0,getmaxy()};
setfillstyle(1,BLACK);
fillpoly(4,a);
cout<<endl<<endl<<"\t\t\t\tYOU DIED";
}



void main(){
clrscr();
char ch;
int gd = DETECT, gm;
initgraph(&gd, &gm, "L:\\TURBOC3\\BGI");
settextstyle(SANS_SERIF_FONT,0,3);
outtextxy(200,80,"     WELCOME");
outtextxy(10,200,"ENTER 1 TO PLAY MINESWEEPER AND 2 TO PLAY 1945");
ch=getch();

if(ch=='1')minesweep();
if(ch=='2')air();
else
exit(0);

}
