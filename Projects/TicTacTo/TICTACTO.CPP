#include<iostream.h>
#include<dos.h>
#include<ctype.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdio.h>
int main()
{
	clrscr();
	char p1[20],p2[20],ch,winner;
	int no,a,b,i,j,attempt;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C|\TURBOC3\BGI");

	setcolor(LIGHTCYAN);
	settextstyle(4,0,8);
	outtextxy(80,130,"Noughts");
	outtextxy(300,200,"&");
	outtextxy(320,270,"Crosses");
	getch();

	cleardevice();
	setcolor(LIGHTRED);
	settextstyle(4,0,5);
	outtextxy(150,50,"About the game: ");
	setcolor(LIGHTBLUE);
	settextstyle(2,0,6);
	outtextxy(20,150," This is a famous TIC TAC TOE game. This game is of 2 players");
	outtextxy(20,170," X and O, who takes turns making the spaces in a 3x3 grid.");
	outtextxy(20,190," The player who succeeds in placing three of their marks");
	outtextxy(20,210," in a horizontal, vertical, or diagnol row wins the game.");
	getche();

	cleardevice();
	setcolor(LIGHTRED);
	settextstyle(4,0,5);
	outtextxy(100,50,"Rules for playing the game");
	setcolor(LIGHTBLUE);
	settextstyle(2,0,6);
	outtextxy(30,160,"- 1st player gets \'X\' and 2nd player gets \'O\'");
	outtextxy(30,190,"- You have to only press the no. and enter key nothing else");
	outtextxy(30,210,"  to put a \'X\' or \'O\' on the board");
	outtextxy(30,240,"- Players can only play simultaneosly");
	outtextxy(30,270,"- One player can\'t move two times");
	outtextxy(30,300,"- No illegal move can be made");
	outtextxy(30,330,"- If a move is done you cannot overwrite it");

	getch();
	cleardevice();
	closegraph();

	//constream cout;
	//setclr(LIGHTCYAN);
	cout<<"\n ******************************************************************************";
	cout<<"\n\n\t\t\t     BOARD PATTERN";
	cout<<"\n\n ******************************************************************************";

	a=0;
	int board[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			a++;
			board[i][j]=a;
		}
	}
	cout<<"\n\n\n\t\t\t       |     |     ";
	cout<<"\n\t\t\t    "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  ";
	cout<<"\n\t\t\t  _____|_____|_____";
	cout<<"\n\t\t\t       |     |     ";
	cout<<"\n\t\t\t    "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  ";
	cout<<"\n\t\t\t  _____|_____|_____";
	cout<<"\n\t\t\t       |     |     ";
	cout<<"\n\t\t\t    "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  ";
	cout<<"\n\t\t\t       |     |     ";

	cout<<"\n\n\n You have to only  press numbers (1 to 9) and enter according to the position    on the board where you have to put mark assinged to you whether it is \'O\' \n or \'X\'.";
	getch();

	clrscr();
	for(b=0;b<101;b++)
	{
		clrscr();
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t     LOADING  ";
		cout<<b<<"%";
		delay(70);
	}
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t      Press any key to continue";
	getche();

	play:
	clrscr();
	cout<<"\n\n\n\n\n\t  Enter the name of the Player 1: ";
	gets(p1);
	p1[0]=_toupper(p1[0]);
	cout<<"\n\t  Enter the name of the Player 2: ";
	gets(p2);
	p2[0]=_toupper(p2[0]);
	cout<<"\n\n\t  According to the game: \n\t\t   "<<p1<<" (Player 1) gets \'X\'\n\t\t   "<<p2<<"(Player 2) gets \'O\'";
	getch();

	int go=0;
	char board1[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			a++;
			board1[i][j]=' ';
		}
	}
	for(attempt=0;attempt<9;attempt++)
	{
		str:
		clrscr();
		cout<<"\n\n\n\n\n\t\t\t       |     |     ";
		cout<<"\n\t\t\t    "<<board1[0][0]<<"  |  "<<board1[0][1]<<"  |  "<<board1[0][2]<<"  ";
		cout<<"\n\t\t\t  _____|_____|_____";
		cout<<"\n\t\t\t       |     |     ";
		cout<<"\n\t\t\t    "<<board1[1][0]<<"  |  "<<board1[1][1]<<"  |  "<<board1[1][2]<<"  ";
		cout<<"\n\t\t\t  _____|_____|_____";
		cout<<"\n\t\t\t       |     |     ";
		cout<<"\n\t\t\t    "<<board1[2][0]<<"  |  "<<board1[2][1]<<"  |  "<<board1[2][2]<<"  ";
		cout<<"\n\t\t\t       |     |     ";

		if(attempt % 2 == 0)
		{
			cout<<"\n\n\n\n\n\t\t  Its "<<p1<<" (Player 1) turn, enter choice: ";
			cin>>no;
			if(no<=3)
			{
				b=no-1;
				if(board1[0][b]!=' ')
				{
					cout<<"\n\t\t  The block is already filled \n\t\t  Try again";
					getch();
					goto str;
				}
				board1[0][b]='X';
			}
			else if(no>=4 && no<=6)
			{
				b=no-4;
				if(board1[1][b]!=' ')
				{
					cout<<"\n\t\t  The block is already filled \n\t\t  Try again";
					getch();
					goto str;
				}
				board1[1][b]='X';
			}
			else if(no>=7 && no<=9)
			{
				b=no-7;
				if(board1[2][b]!=' ')
				{
					cout<<"\n\t\t  The block is already filled \n\t\t  Try again";
					getch();
					goto str;
				}
				board1[2][b]='X';
			}
			else
			{
				cout<<"\n\t\t  Invalid choice \n\t\t  Try again";
				getch();
				goto str;
			}
		}
		else
		{
			cout<<"\n\n\n\n\n\t\t  Its "<<p2<<" (Player 2) turn, enter choice: ";
			cin>>no;
			if(no<=3)
			{
				b=no-1;
				if(board1[0][b]!=' ')
				{
					cout<<"\n\t\t  The block is already filled \n\t\t  Try again";
					getch();
					goto str;
				}
				board1[0][b]='O';
			}
			else if(no>=4 && no<=6)
			{
				b=no-4;
				if(board1[1][b]!=' ')
				{
					cout<<"\n\t\t  The block is already filled \n\t\t  Try again";
					getch();
					goto str;
				}
				board1[1][b]='O';
			}
			else if(no>=7 && no<=9)
			{
				b=no-7;
				if(board1[2][b]!=' ')
				{
					cout<<"\n\t\t  The block is already filled \n\t\t  Try again";
					getch();
					goto str;
				}
				board1[2][b]='O';
			}
			else
			{
				cout<<"\n\t\t  Invalid choice \n\t\t  Try again";
				getch();
				goto str;
			}
		}
		if(attempt>=3)
		{

					// Diagnols //

			if(board1[0][0]==board1[1][1] && board1[1][1]==board1[2][2] && board1[0][0]!=' ')
			{
				winner=board1[0][0];
				go++;
			}
			else if(board1[0][2]==board1[1][1] && board1[1][1]==board1[2][0] && board1[0][2]!=' ')
			{
				winner=board1[0][2];
				go++;
			}

					// Rows //

			else if(board1[0][0]==board1[0][1] && board1[0][1]==board1[0][2] && board1[0][0]!=' ')
			{
				winner=board1[0][0];
				go++;
			}
			else if(board1[2][0]==board1[2][1] && board1[2][1]==board1[2][2] && board1[2][0]!=' ')
			{
				winner=board1[2][0];
				go++;
			}

					// Columns //

			else if(board1[0][0]==board1[1][0] && board1[1][0]==board1[2][0] && board1[0][0]!=' ')
			{
				winner=board1[0][0];
				go++;
			}
			else if(board1[0][2]==board1[1][2] && board1[0][2]==board1[2][2] && board1[0][2]!=' ')
			{
				winner=board1[0][2];
				go++;
			}

					// Middle //

			else if(board1[0][1]==board1[1][1] && board1[1][1]==board1[2][1] && board1[0][1]!=' ')
			{
				winner=board1[0][1];
				go++;
			}
			else if(board1[1][0]==board1[1][1] && board1[1][1]==board1[1][2]&& board1[1][0]!=' ')
			{
				winner=board1[1][0];
				go++;
			}
		}
		if(go==1)
		{
			if(winner=='X')
			{
				clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t "<<p1<<" (Player 1) wins the game";
				getch();
				goto end;
			}
			else
			{
				clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t "<<p2<<"(Player 2) wins the game";
				getch();
				goto end;
			}
		}
	}
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t It\'s a Draw, Nobody wins";
	getch();

	end:
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t    Do you want to play again(y/n) ";
	cin>>ch;
	if(ch=='y'|| ch=='Y')
	{
		goto play;
	}
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t  THANK YOU FOR PLAYING";

	getch();
	return(0);
}
