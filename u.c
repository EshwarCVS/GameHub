#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>


#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int length;
int bend_no;
int len;
char key;
void record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();

struct coordinate
{
 int x;;
 int y;
 int direction;
};

typedef struct coordinate coordinate;

coordinate head, bend[500],food,body[30];


void Board();
void PlayerX();
void PlayerO();
void Player_win();
void check();
int win=0,wrong_X=0,wrong_O=0,chk=0;

char name_X[30];
char name_O[30];
int pos_for_X[3][3];
int pos_for_O[3][3];
int pos_marked[3][3];

int main()
{
 int de;
 printf("\n ENTER THE GAME TO BE CHOOSEN \n 1. SNAKE GAME \n 2. TIC-TAC-TOE \n 3. HANG MAN \n");
 scanf("%d",de);
 switch(de)
 {
  case 1:
  {
   char key;
   Print();
   system("cls");
   load();
   length=5;
   head.x=25;
   head.y=20;
   head.direction=RIGHT;
   Boarder();
   Food(); 
   life=3;
   bend[0]=head;
   Move();  
  }
  break;
  case 2:
  {
   
	int i,ch,j;
	char ans;
/*	clrscr();
	printf("\n\t\t\t\tTIC TAC TOE");
	printf("\n\t\t\t\t");
	for(i=1;i<=11;i++)
	{
		delay(10000);
		printf("*");
	}*/
	do
	{
		printf("\n\t\t\t\tTIC TAC TOE");
		printf("\n\t\t\t\t");
		for(i=1;i<=11;i++)
		{
			//delay(10000);
			printf("*");
		}
		printf("\n1.Start The Game");
		printf("\n2.Quit The Game");
		printf("\nEnter your choice(1-2) : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				chk=0;
				win=0;
				for(i=1;i<=3;i++)
				{
					for(j=1;j<=3;j++)
					{
						pos_for_X[i][j]=0;
						pos_for_O[i][j]=0;
						pos_marked[i][j]=0;
					}
				}
				printf("\n\n");
				//clrscr();
				printf("\nEnter the name of the player playing for \'X\': ");
				fflush(stdin);
				gets(name_X);
				printf("\nEnter the name of the player playing for \'O\': ");
				fflush(stdin);
				gets(name_O);
				Board();
				for(;;)
				{
					if(win==1)
						break;
					check();
					if(chk==9)
					{
						printf("\n\t\t\tMATCH DRAWS!!");
						printf("\nPress any key....");
						break;
					}
					else
						chk=0;
					printf("\nTURN FOR %s:",name_X);
					PlayerX();
					do
					{
						if(wrong_X!=1)
							break;
						wrong_X=0;
						printf("\nTURN FOR %s:",name_X);
						PlayerX();
					}while(wrong_X==1);
					check();
					if(chk==9)
					{
						printf("\n\t\t\tMATCH DRAWS");
						printf("\nPress any key....");
						break;
					}
					else
						chk=0;
					printf("\nTURN FOR %s:",name_O);
					PlayerO();
					do
					{
						if(wrong_O!=1)
							break;
						wrong_O=0;
						printf("\nTURN FOR %s:",name_O);
						PlayerO();
					}while(wrong_O==1);

					}
				Board();
				if(win!=1)
				{
					printf("\n\t\t\tMATCH DRAWS!!");
					printf("\nPress any key.......");
				}
				getch();
				break;
			case 2:
				printf("\n\n\n\t\t\tThank You For Playing The Game.");
				printf("\n\t\t\t###############################");
				getch();

				break;
		}
		printf("\nWant To Play(Y/N) ? ");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y' || ans=='Y');
  }
  break;
  case 3:
  {
   
	char word[30],getit[30],*found;
	int score,loop,len,num,lup,om,luptimes,times,fitimes,ondtimes,antimes;
	luptimes=0;
	fitimes=0;
	ondtimes=0;
	//clrscr();
	printf("\n ENTER THE WORD: ");
	gets(word);
	score=0;
	num=0;
	om=0;

	len=strlen(word);
	//clrscr();
	char gname[70];
	printf("\n ENTER YOUR NAME: ");
	scanf("%s",gname);
	char h;
	printf("\n LET's START: ");
	h='_';
	printf("\n LOOK HERE: ");
	for(loop=0;loop!=len;loop++)
	{
		printf("\n %c ",h);
	}
	for(loop=0;loop!=len;loop++)
	{
		om=1;
		num=num+1;
		fitimes=0;
		ondtimes=0;
		printf("\n\n %d LETTER",num);
		scanf("%s",&getit[num]);
		found=strchr(word,getit[num]);
		if(found)
		{
			for(luptimes=0,antimes=1;luptimes!=len;luptimes++,antimes++)
			{
				if(getit[num]==word[luptimes])
				{
					fitimes++;
				}
				else
				{
					fitimes=fitimes;
				}
			}
			for(luptimes=num;luptimes!=0;luptimes--)
			{
				if(getit[num]==getit[luptimes])
				{
					ondtimes++;
				}
				else
				{
					ondtimes=ondtimes;
				}
			}
			if(fitimes>=ondtimes)
			{
				score=score+1;
				printf("\n OK\n");
				for(lup=0;getit[num]!=word[lup];lup++)
				{
					om++;
				}
				printf("\n POSITION: %d\n",om);
				printf("\n ===================\n");
			}
			else
			{
				score=score;
				printf("\n NOT AGAIN!\n");
			}
		}
		else
		{
			score=score;
			printf("\n NO\n");
		}
	}
	printf("\n THE WORD IS '%s'\n",word);
	printf("\n YOUR SCORE IS %d OUT OF %d",score,len);
	getch();
  }
  break;
 default:
 printf("\n ENTER THE CORRECT VALUE");
 break;
}
return 0;
}


void Move()
{
 int a,i;
 do{
    Food();
    fflush(stdin);
    len=0;
    for(i=0;i<30;i++)
    {
     body[i].x=0;
     body[i].y=0;
     if(i==length)
      break;
    }
    Delay(length);
    Boarder();
    if(head.direction==RIGHT)
     Right();
    else if(head.direction==LEFT)
     Left();
    else if(head.direction==DOWN)
     Down();
    else if(head.direction==UP)
     Up();
    ExitGame();
   }
   while(!kbhit());
    a=getch();
    if(a==27)
    {
     system("cls");
     exit(0);
    }
    key=getch();
    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))
    {
     bend_no++;
     bend[bend_no]=head;
     head.direction=key;
     if(key==UP)
      head.y--;
     if(key==DOWN)
      head.y++;
     if(key==RIGHT)
      head.x++;
     if(key==LEFT)
      head.x--;
     Move();
    }
    else if(key==27)
    {
     system("cls");
     exit(0);
    }
    else
    {
     printf("\a");
     Move();
    }
}

void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GotoXY(int x, int y)
{
 HANDLE a;
 COORD b;
 fflush(stdout);
 b.X = x;
 b.Y = y;
 a = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(a,b);
}

void load()
{
 int row,col,r,c,q;
 gotoxy(36,14);
 printf("loading...");
 gotoxy(30,15);
 for(r=1;r<=20;r++){
 for(q=0;q<=100000000;q++);//to display the character slowly
 printf("%c",177);}
 getch();
}

void Down()
{
 int i;
 for(i=0;i<=(head.y-bend[bend_no].y)&&len<length;i++)
 {
  GotoXY(head.x,head.y-i);
  {
   if(len==0)
    printf("v");
   else
    printf("*");
  }
  body[len].x=head.x;
  body[len].y=head.y-i;
  len++;
 }
 Bend();
 if(!kbhit())
  head.y++;
}

void Delay(long double k)
{
 Score();
 long double i;
 for(i=0;i<=(10000000);i++);
}

void ExitGame()
{
 int i,check=0;
 for(i=4;i<length;i++)   //starts with 4 because it needs minimum 4 element to touch its own body
 {
  if(body[0].x==body[i].x&&body[0].y==body[i].y)
  {
   check++;    //check's value increases as the coordinates of head is equal to any other body coordinate
  }
  if(i==length||check!=0)
   break;
 }
 if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0)
 {
  life--;
  if(life>=0)
  {
   head.x=25;
   head.y=20;
   bend_no=0;
   head.direction=RIGHT;
   Move();
  }
  else
  {
   system("cls");
   printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");
   record();
   exit(0);
  }
 }
}

void Food()
{
 if(head.x==food.x&&head.y==food.y)
 {
  length++;
  time_t a;
  a=time(0);
  srand(a);
  food.x=rand()%70;
  if(food.x<=10)
  food.x+=11;
  food.y=rand()%30;
  if(food.y<=10)
   food.y+=11;
 }
  else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
  {
   food.x=rand()%70;
   if(food.x<=10)
    food.x+=11;
    food.y=rand()%30;
     if(food.y<=10)
      food.y+=11;
  }
}

void Left()
{
 int i;
 for(i=0;i<=(bend[bend_no].x-head.x)&&len<length;i++)
 {
  GotoXY((head.x+i),head.y);
  {
   if(len==0)
    printf("<");
   else
    printf("*");
  }
  body[len].x=head.x+i;
  body[len].y=head.y;
  len++;
 }
 Bend();
 if(!kbhit())
  head.x--;
}

void Right()
{
 int i;
 for(i=0;i<=(head.x-bend[bend_no].x)&&len<length;i++)
 {  //GotoXY((head.x-i),head.y);
  body[len].x=head.x-i;
  body[len].y=head.y;
  GotoXY(body[len].x,body[len].y);
  {
   if(len==0)
    printf(">");
   else
    printf("*");
  }
   /*body[len].x=head.x-i;
     body[len].y=head.y;*/
  len++;
 }
 Bend();
 if(!kbhit())
  head.x++;
}

void Bend()
{
 int i,j,diff;
 for(i=bend_no;i>=0&&len<length;i--)
 {
  if(bend[i].x==bend[i-1].x)
  {
   diff=bend[i].y-bend[i-1].y;
   if(diff<0)
    for(j=1;j<=(-diff);j++)
    {
     body[len].x=bend[i].x;
     body[len].y=bend[i].y+j;
     GotoXY(body[len].x,body[len].y);
     printf("*");
     len++;
     if(len==length)
      break;
    }
   else if(diff>0)
    for(j=1;j<=diff;j++)
    {        /*GotoXY(bend[i].x,(bend[i].y-j));
             printf("*");*/
     body[len].x=bend[i].x;
     body[len].y=bend[i].y-j;
     GotoXY(body[len].x,body[len].y);
     printf("*");
     len++;
     if(len==length)
      break;
    }
   }
   else if(bend[i].y==bend[i-1].y)
   {
    diff=bend[i].x-bend[i-1].x;
    if(diff<0)
     for(j=1;j<=(-diff)&&len<length;j++)
     {
         /*GotoXY((bend[i].x+j),bend[i].y);
         printf("*");*/
       body[len].x=bend[i].x+j;
       body[len].y=bend[i].y;
       GotoXY(body[len].x,body[len].y);
       printf("*");
       len++;
       if(len==length)
        break;
      }
    else if(diff>0)
     for(j=1;j<=diff&&len<length;j++)
     { /*GotoXY((bend[i].x-j),bend[i].y);
        printf("*");*/
      body[len].x=bend[i].x-j;
      body[len].y=bend[i].y;
      GotoXY(body[len].x,body[len].y);
      printf("*");
      len++;
      if(len==length)
       break;
     }
   }
 }
}

void Boarder()
{
 system("cls");
 int i;
 GotoXY(food.x,food.y);   /*displaying food*/
 printf("F");
 for(i=10;i<71;i++)
 {
  GotoXY(i,10);
  printf("!");
  GotoXY(i,30);
  printf("!");
 }
 for(i=10;i<31;i++)
 {
  GotoXY(10,i);
  printf("!");
  GotoXY(70,i);
  printf("!");
 }
}

void Print()
{ //GotoXY(10,12);
 printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
 getch();
 system("cls");
 printf("\tGame instructions:\n");
 printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
 printf("\n\nPress any key to play game...");
 if(getch()==27)
  exit(0);
}

void record()
{
 char plname[20],nplname[20],cha,c;
 int i,j,px;
 FILE *info;
 info=fopen("record.txt","a+");
 getch();
 system("cls");
 printf("Enter your name\n");
 scanf("%[^\n]",plname);
 for(j=0;plname[j]!='\0';j++)
 { //to convert the first letter after space to capital
  nplname[0]=toupper(plname[0]);
  if(plname[j-1]==' '){
   nplname[j]=toupper(plname[j]);
   nplname[j-1]=plname[j-1];}
  else 
   nplname[j]=plname[j];
 }
 nplname[j]='\0';
   //*****************************
   //sdfprintf(info,"\t\t\tPlayers List\n");
 fprintf(info,"Player Name :%s\n",nplname);
    //for date and time
 time_t mytime;
 mytime = time(NULL);
 fprintf(info,"Played Date:%s",ctime(&mytime));
     //**************************
 fprintf(info,"Score:%d\n",px=Scoreonly());//call score to display score
    //fprintf(info,"\nLevel:%d\n",10);//call level to display level
  for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
   fprintf(info,"\n");
   fclose(info);
   printf("wanna see past records press 'y'\n");
   cha=getch();
   system("cls");
   if(cha=='y')
   {
    info=fopen("record.txt","r");
    do
    {
     putchar(c=getc(info));
    }while(c!=EOF);
   }
 fclose(info);
}

int Score()
{
 int score;
 GotoXY(20,8);
 score=length-5;
 printf("SCORE : %d",(length-5));
 score=length-5;
 GotoXY(50,8);
 printf("Life : %d",life);
 return score;
}

int Scoreonly()
{
 int score=Score();
 system("cls");
 return score;
}

void Up()
{
 int i;
 for(i=0;i<=(bend[bend_no].y-head.y)&&len<length;i++)
 {
  GotoXY(head.x,head.y+i);
  {
   if(len==0)
    printf("^");
   else
    printf("*");
  }
  body[len].x=head.x;
  body[len].y=head.y+i;
  len++;
 }
 Bend();
 if(!kbhit())
  head.y--;
}



void Board()
{
	int i,j;
	//clrscr();
	printf("\n\t\t\t\tTIC TAC TOE BOARD");
	printf("\n\t\t\t\t*****************");
	printf("\n\n\n");
	printf("\n\t\t\t    1\t      2\t        3");
	for(i=1;i<=3;i++)
	{
		printf("\n \t\t\t _____________________________");
		printf("\n \t\t\t¦\t  ¦\t   ¦\t     ¦");
		printf("\n\t\t%d\t",i);
		for(j=1;j<=3;j++)
		{

			if(pos_for_X[i][j]==1)
			{
				printf("    X");
				printf("     ");
			}
			else if(pos_for_O[i][j]==1)
			{
				printf("    O");
				printf("     ");
			}
			else
			{
				printf("          ");
				continue;
			}
		}
		printf("\n\t\t\t¦\t  ¦\t   ¦\t     ¦");
	}
	printf("\n\t\t\t------------------------------");
	Player_win();
}


void PlayerX()
{
	int row,col;
	if(win==1)
		return;
	printf("\nEnter the row no. : ");
	fflush(stdin);
	scanf("%d",&row);
	printf("Enter the column no. : ");
	fflush(stdin);
	scanf("%d",&col);
	if(pos_marked[row][col]==1 || row<1 || row>3 || col<1 || col>3)
	{
		printf("\nWRONG POSITION!! Press any key.....");
		wrong_X=1;
		getch();
		Board();
	}
	else
	{
		pos_for_X[row][col]=1;
		pos_marked[row][col]=1;
		Board();
	}
}
void PlayerO()
{
	int row,col;
	if(win==1)
		return;
	printf("\nEnter the row no. : ");
	scanf("%d",&row);
	printf("Enter the column no. : ");
	scanf("%d",&col);
	if(pos_marked[row][col]==1 || row<1 || row>3 || col<1 || col>3)
	{
		printf("\nWRONG POSITION!! Press any key....");
		wrong_O=1;
		getch();
		Board();
	}
	else
	{
		pos_for_O[row][col]=1;
		pos_marked[row][col]=1;
		Board();
	}
}
void Player_win()
{
	int i;
	for(i=1;i<=3;i++)
	{
		if(pos_for_X[i][1]==1 && pos_for_X[i][2]==1 && pos_for_X[i][3]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_X);
			printf("\nPress any key............");
			return;
		}
	}
	for(i=1;i<=3;i++)
	{
		if(pos_for_X[1][i]==1 && pos_for_X[2][i]==1 && pos_for_X[3][i]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_X);
			printf("\nPress any key............");
			return;
		}
	}
	if(pos_for_X[1][1]==1 && pos_for_X[2][2]==1 && pos_for_X[3][3]==1)
	{
		win=1;
		printf("\n\nRESULTL: %s wins!!",name_X);
		printf("\nPress any key......");
		return;
	}
	else if(pos_for_X[1][3]==1 && pos_for_X[2][2]==1 &&
pos_for_X[3][1]==1)
	{
        	win=1;
		printf("\n\nRESULT: %s wins!!",name_X);
                printf("\nPress any key.....");
		return;
	}

        for(i=1;i<=3;i++)
	{
		if(pos_for_O[i][1]==1 && pos_for_O[i][2]==1 && pos_for_O[i][3]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_O);
                        printf("\nPress any key.....");
			return;
		}
	}
	for(i=1;i<=3;i++)
	{
		if(pos_for_O[1][i]==1 && pos_for_O[2][i]==1 && pos_for_O[3][i]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_O);
                        printf("\nPress any key.....");
			return;
		}
	}
	if(pos_for_O[1][1]==1 && pos_for_O[2][2]==1 && pos_for_O[3][3]==1)
	{
		win=1;
		printf("\n\nRESULT: %s wins!!",name_O);
		printf("\nPress any key.....");
		return;
	}
	else if(pos_for_O[1][3]==1 && pos_for_O[2][2]==1 &&
pos_for_O[3][1]==1)
	{
        	win=1;
		printf("\n\nRESULT: %s wins!!",name_O);
                printf("\nPress any key.....");
		return;
	}
}
void check()
{
	int i,j;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			if(pos_marked[i][j]==1)
				chk++;
			else
				continue;
		}
	}
}





 