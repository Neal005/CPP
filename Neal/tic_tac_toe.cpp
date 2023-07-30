#include<stdio.h>
#include<windows.h>
#define debug 0
typedef struct
{
	int x,y;
} cell;

typedef struct
{
	cell A[9];
} Locate;

int table[3][3],win_player1=0,win_player2=0,win_AI=0,who_win=0,win=1,n=3,cache_x[100],cache_o[100];
Locate locate;

void reset()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			table[i][j]=0;
			
	win=1;
	who_win=0;
	
	for(int i=0;i<100;i++)
	{
		cache_x[i]=0;
		cache_o[i]=0;
	}
}

void init()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			table[i][j]=0;
	
	int count=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			locate.A[count].x=i;locate.A[count].y=j;
			count++;
		}
	
	for(int i=0;i<100;i++)
	{
		cache_x[i]=0;
		cache_o[i]=0;
	}
}

void init_cell(cell* c)
{
	c->x=c->y=-1;
}

int xy_to_num(int x,int y)
{
	return (n*x)+y+1;
}

void print_table(int AI)
{
	for(int i=0;i<(((n*3)+2)/2);i++) printf(" "); printf("\t");
	printf("***TIC TAC TOE***");
	if(AI)
	{
		printf("\n\n\t\tA.I\n\n\t   ");
	}
	else
	{
		printf("\n\n\t   ");
	}
	printf("   ");
	for(int i=1;i<n;i++)
	{
		printf("|");
		if(i<n) printf("   ");
	}
	printf("\n\t   ");
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(table[j][i]==0)
			{
				if(i+1+n*j<=9) printf(" %d ",i+1+n*j);
				else printf("...");
				if(i<n-1) printf("|");
			}
			if(table[j][i]==1)
			{
				printf(" X ");
				if(i<n-1) printf("|");
			}
			if(table[j][i]==2)
			{
				printf(" O ");
				if(i<n-1) printf("|");
			}
		}
		if(j<n-1)
		{
			printf("\n\t  ____");
			for(int i=1;i<n;i++)
			{
				printf("|");
				if(i<n) printf("___");
			}
			printf("_\n\t   ");
			if(n<=3)
			{
				printf("   ");
				for(int i=1;i<n;i++)
				{
					printf("|");
					if(i<n) printf("   ");
				}
				printf("\n\t   ");
			}
		}
	}
	printf("\n\t      ");
	for(int i=1;i<n;i++)
	{
		printf("|");
		if(i<n) printf("   ");
	}
	printf("\n");
	printf("\n\n\t\t\t                                              made by Nguyen Le Hoang Luc - Neal\n");
}

void check_win(int x, int y, int player)
{
	int count=0;
	//X
	for(int i=1;i<3;i++) 
		if(table[x][y+i]==player) if(y+i<3&&y+i>-1) count++;
	if(count==2)
	{
		who_win=player;
		return;
	}
	//if(count==1) warning=1;
	
	count=0;
	for(int i=-1;i>-3;i--)
		if(table[x][y+i]==player) if(y+i<3&&y+i>-1) count++;
	if(count==2)
	{
		who_win=player;
		return;
	}
	//if(count==1) warning=1;
	
	count=0;
	for(int i=-1;i<3;i+=2)
		if(table[x][y+i]==player) if(y+i<3&&y+i>-1) count++;
	if(count==2)
	{
		who_win=player;
		return;
	}
	//if(count==1) warning=1;

	//Y
	count=0;
	for(int i=1;i<3;i++) 
		if(table[x+i][y]==player) if(x+i<3&&x+i>-1) count++;
	if(count==2)
	{
		who_win=player;
		return;
	}
	//if(count==1) warning=1;
	
	count=0;
	for(int i=-1;i>-3;i--) 
		if(table[x+i][y]==player) if(x+i<3&&x+i>-1) count++;
	if(count==2)
	{
		who_win=player;
		return;
	}
	//if(count==1) warning=1;
	
	count=0;
	for(int i=-1;i<3;i+=2) 
		if(table[x+i][y]==player) if(x+i<3&&x+i>-1) count++;
	if(count==2)
	{
		who_win=player;
		return;
	}
	//if(count==1) warning=1;
	
	//X&Y
	count=0;
	for(int i=1;i<3;i++) 
		if(table[x+i][y+i]==player) if(x+i<3&&x+i>-1) count++;
	if(count==2)
	{
		who_win=player;
		return;
	}
	//if(count==1) warning=1;
	
	count=0;
	for(int i=-1;i>-3;i--) 
		if(table[x+i][y+i]==player) if(x+i<3&&x+i>-1) count++;
	if(count==2)
	{
		who_win=player;
		return;
	}
	//if(count==1) warning=1;
	
	count=0;
	for(int i=-1;i<3;i+=2) 
		if(table[x+i][y+i]==player) if(x+i<3&&x+i>-1) count++;
	if(count==2)
	{
		who_win=player;
		return;
	}
	//if(count==1) warning=1;
	
	//Y&X
	count=0;
	for(int i=1;i<3;i++)
		if(table[x+i][y-i]==player) if(x+i<3&&x+i>-1&&y-i>-1&&y-i<3) count++;
	if(count==2)
	{
		who_win=player;
		return;
	}
	//if(count==1) warning=1;
	
	count=0;
	for(int i=-1;i>-3;i--) 
	{
		if(table[x+i][y-i]==player) if(x+i<3&&x+i>-1&&y-i>-1&&y-i<3) count++;
	}
	if(count==2)
	{
		who_win=player;
		return;
	}
	//if(count==1) warning=1;
	
	count=0;
	for(int i=-1;i<3;i+=2) 
		if(table[x+i][y-i]==player) if(x+i<3&&x+i>-1&&y-i>-1&&y-i<3) count++;
	if(count==2)
	{
		who_win=player;
		return;
	}
	//if(count==1) warning=1;
}

void turn(int AI,int player)
{
	int stop;
	char numchar='0';
	int num=0;
	do
	{
		stop=1;
		if(player==1) printf("\n __________\n|          |\n| Player X |\n|__________|\n");
		else printf("\n __________\n|          |\n| Player O |\n|__________|\n");
		printf("\nChoose cell: "); fflush(stdin); scanf("%c",&numchar); fflush(stdin);
		if(numchar<'1'||numchar>'9')
		{
			if(!debug) system("cls");
			if(AI) print_table(1);
			else print_table(0);
			fflush(stdin);
			printf("Number is error!\n",numchar);
		}
		else
		{
			
			if(numchar=='1') num=1;if(numchar=='2') num=2;if(numchar=='3') num=3;if(numchar=='4') num=4;
			if(numchar=='5') num=5;if(numchar=='6') num=6;if(numchar=='7') num=7;if(numchar=='8') num=8;
			if(numchar=='9') num=9;
			
			if(table[locate.A[num-1].x][locate.A[num-1].y]!=0)
			{
				if(!debug) system("cls");
				if(AI) print_table(1);
				else print_table(0);
				fflush(stdin);
				printf("The cell is chosen! Please choose again!\n");
			}
			else stop=0;
		}
	} while(stop);
	if(table[locate.A[num-1].x][locate.A[num-1].y]==0)
	{
		table[locate.A[num-1].x][locate.A[num-1].y]=player;	
		if(player==1)
		{
			cache_x[0]++;
			cache_x[cache_x[0]]=num;
		}
		if(player==2)
		{
			cache_o[0]++;
			cache_o[cache_o[0]]=num;
		}
		if(!debug) system("cls");
		if(AI) print_table(1);
		else print_table(0);
		fflush(stdin);
	}
	check_win(locate.A[num-1].x,locate.A[num-1].y,player);
}

void AI_turn(int num, int lucuto, int* turn_done,int player)
{
	cell c;
	init_cell(&c);
	int x=locate.A[num-1].x;
	int y=locate.A[num-1].y;
	
	//X
	int count=0;
	for(int i=1;i<3;i++)
	{
		if(table[x][y+i]==0&&y+i<3&&y+i>-1)
		{
			c.x=x;
			c.y=y+i;
		}
		if(table[x][y+i]==player) if(y+i<3&&y+i>-1) count++;
	}
	if(count==1&&c.x>-1&&c.x<3&&c.y>-1&&c.y<3)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}
	
	count=0;
	for(int i=-1;i>-3;i--)
	{
		if(table[x][y+i]==0&&y+i<3&&y+i>-1)
		{
			c.x=x;
			c.y=y+i;
		}
		if(table[x][y+i]==player) if(y+i<3&&y+i>-1) count++;
	}
	if(count==1&&c.x>-1&&c.x<3&&c.y>-1&&c.y<3)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}
	
	count=0;
	for(int i=-1;i<3;i+=2)
	{
		if(table[x][y+i]==0&&y+i<3&&y+i>-1)
		{
			c.x=x;
			c.y=y+i;
		}
		if(table[x][y+i]==player) if(y+i<3&&y+i>-1) count++;
	}
	if(count==1&&c.x>-1&&c.x<3&&c.y>-1&&c.y<3)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}

	//Y
	count=0;
	for(int i=1;i<3;i++) 
	{
		if(table[x+i][y]==0&&x+i<3&&x+i>-1)
		{
			c.x=x+i;
			c.y=y;
		}
		if(table[x+i][y]==player) if(x+i<3&&x+i>-1) count++;
	}
	if(count==1&&c.x>-1&&c.x<3&&c.y>-1&&c.y<3)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}
	
	count=0;
	for(int i=-1;i>-3;i--) 
	{
		if(table[x+i][y]==0&&x+i<3&&x+i>-1)
		{
			c.x=x+i;
			c.y=y;
		}
		if(table[x+i][y]==player) if(x+i<3&&x+i>-1) count++;
	}
	if(count==1&&c.x>-1&&c.x<3&&c.y>-1&&c.y<3)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}
	
	count=0;
	for(int i=-1;i<3;i+=2) 
	{
		if(table[x+i][y]==0&&x+i<3&&x+i>-1)
		{
			c.x=x+i;
			c.y=y;
		}
		if(table[x+i][y]==player) if(x+i<3&&x+i>-1) count++;
	}
	if(count==1&&c.x>-1&&c.x<3&&c.y>-1&&c.y<3)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}
	
	//X&Y
	count=0;
	for(int i=1;i<3;i++) 
	{
		if(table[x+i][y+i]==0&&x+i<3&&x+i>-1)
		{
			c.x=x+i;
			c.y=y+i;
		}
		if(table[x+i][y+i]==player) if(x+i<3&&x+i>-1) count++;
	}
	if(count==1&&c.x>-1&&c.x<3&&c.y>-1&&c.y<3)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}
	
	count=0;
	for(int i=-1;i>-3;i--) 
	{
		if(table[x+i][y+i]==0&&x+i<3&&x+i>-1)
		{
			c.x=x+i;
			c.y=y+i;
		}
		if(table[x+i][y+i]==player) if(x+i<3&&x+i>-1) count++;
	}
	if(count==1&&c.x>-1&&c.x<3&&c.y>-1&&c.y<3)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}
	
	count=0;
	for(int i=-1;i<3;i+=2) 
	{
		if(table[x+i][y+i]==0&&x+i<3&&x+i>-1)
		{
			c.x=x+i;
			c.y=y+i;
		}
		if(table[x+i][y+i]==player) if(x+i<3&&x+i>-1) count++;
	}
	if(count==1&&c.x>-1&&c.x<3&&c.y>-1&&c.y<3)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}
	
	//Y&X
	count=0;
	for(int i=1;i<3;i++)
	{
		if(table[x+i][y-i]==0&&x+i<3&&x+i>-1&&y-i>-1&&y-i<3)
		{
			c.x=x+i;
			c.y=y-i;
		}
		if(table[x+i][y-i]==player) if(x+i<3&&x+i>-1&&y-i>-1&&y-i<3) count++;
	}
	if(count==1&&c.x>-1&&c.x<3&&c.y>-1&&c.y<3)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}
	
	count=0;
	for(int i=-1;i>-3;i--) 
	{
		if(table[x+i][y-i]==0&&x+i<3&&x+i>-1&&y-i>-1&&y-i<3)
		{
			c.x=x+i;
			c.y=y-i;
		}
		if(table[x+i][y-i]==player) if(x+i<3&&x+i>-1&&y-i>-1&&y-i<3) count++;
	}
	if(count==1&&c.x>-1&&c.x<3&&c.y>-1&&c.y<3)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}
	
	count=0;
	for(int i=-1;i<3;i+=2) 
	{
		if(table[x+i][y-i]==0&&x+i<3&&x+i>-1&&y-i>-1&&y-i<3)
		{
			c.x=x+i;
			c.y=y-i;
		}
		if(table[x+i][y-i]==player) if(x+i<3&&x+i>-1&&y-i>-1&&y-i<3) count++;
	}
	if(count==1&&c.x>-1&&c.x<3&&c.y>-1&&c.y<3)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}
	
	if(cache_x[0]==1)
	{
		table[c.x][c.y]=2;
		cache_o[0]++;
		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
		*turn_done=1;
		check_win(c.x,c.y,2);
		return;
	}
//	if(player==2&&cache_o[0]==lucuto)
//	{
//		table[c.x][c.y]=2;
//		cache_o[0]++;
//		cache_o[cache_o[0]]=xy_to_num(c.x,c.y);
//		*turn_done=1;
//		check_win(c.x,c.y,2);
//		return;
//	}
}

void normal()
{
	print_table(0);
	int count=1,stop_count=1;
	who_win=0;
	do
	{
		for(int i=1;i<=2;i++)
		{
			turn(0,i);
			count++;
			if(count==n*n+1||who_win!=0) break;
		}
		if(count>n*n) stop_count=0;
		if(who_win!=0)
		{
			if(who_win==1) printf("\n*PLAYER X WON!*\n\n");
			if(who_win==2) printf("\n*PLAYER O WON!*\n\n");
			win=0;
		}
	} while(stop_count&&win);
	if(count>n*n&&who_win==0) printf("\n\t    *DRAWN!*\n\n");
}

void AI()
{
	print_table(1);
	int count=1,stop_count=1;
	who_win=0;
	do
	{
		for(int i=1;i<=2;i++)
		{
			if(i==1) turn(1,i);
			else
			{
				if(count<3)
				{
					int turn_done=0;
					for(int j=cache_o[0];j>0;j--)
					{
						if(turn_done) break;
						AI_turn(cache_o[j],j,&turn_done,2);
					}
					for(int j=cache_x[0];j>0;j--)
					{
						if(turn_done) break;
						AI_turn(cache_x[j],j,&turn_done,1);
					}
				}
				else
				{
					int turn_done=0;
					for(int j=cache_x[0];j>0;j--)
					{
						if(turn_done) break;
						AI_turn(cache_x[j],j,&turn_done,1);
					}
					for(int j=cache_o[0];j>0;j--)
					{
						if(turn_done) break;
						AI_turn(cache_o[j],j,&turn_done,2);
					}
				}
			}
			//warning=0;
			system("cls");
			print_table(1);
			count++;
			if(count==n*n+1||who_win!=0) break;
		}
		if(count>n*n) stop_count=0;
		if(who_win!=0)
		{
			if(who_win==1) printf("\n*PLAYER X WON!*\n\n");
			if(who_win==2) printf("\n*A.I WON!*\n\n");
			win=0;
		}
	} while(stop_count&&win);
	if(count>n*n&&who_win==0) printf("\n\t    *DRAWN!*\n\n");
}

int main()
{
	char chose='0';
	init();
	cell c;
	init_cell(&c);
	do
	{
		printf("\t          ***TIC TAC TOE***\n\n");
		printf("\t1. Normal\n\t2. A.I\n\t3. Quit\n\nChoose: "); fflush(stdin); scanf("%c",&chose);
		if(chose=='1'||chose=='2')
		{
			system("cls");
			char again='1';
			do
			{
				if(chose=='1') normal();
				if(chose=='2') AI();
				do
				{
					printf("     1. Again\t     2. Menu\nchoose: "); fflush(stdin); scanf("%c",&again);
					if(again!='1'&&again!='2') printf("Error number!\n");
				} while(again!='2'&&again!='1');
				if(again=='1')
				{
					system("cls");
					reset();
				}
				else
				{
					system("cls");
					reset();
				}
			} while(again=='1');
		}
		if(chose!='1'&&chose!='2'&&chose!='3') printf("*Error number, please chose again!");
	} while(chose!='3');
}