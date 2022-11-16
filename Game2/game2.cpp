#include "game2.h"
#define _CRT_SECURE_NO_WARNINGS 1
int win = ROW * COL - EZ_MINE;

void init_board(char mine[][COLS], char fill) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			mine[i][j] = fill;
		}
	}
}
void check(char mine[][COLS], char show[][COLS], int x, int y) {
	int cnt= (mine[x-1][y-1]+mine[x-1][y]+mine[x-1][y+1]+
		     mine[x][y-1]+mine[x][y+1]+
			mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1]-8*'0');
	show[x][y] = cnt+'0';
	win--;
	if (cnt == 0 && show[x - 1][y - 1] == '*'&&mine[x-1][y-1]!='1'&&x-1>=1&&x-1<=ROW&&y-1>=1&&y-1<=COL)check(mine, show, x - 1, y - 1);
	if (cnt == 0 && show[x - 1][y ] == '*' && mine[x - 1][y ] != '1' && x-1 >= 1 && x-1 <= ROW && y >= 1 && y <= COL)check(mine, show, x - 1, y );
	if (cnt == 0 && show[x - 1][y + 1] == '*' && mine[x - 1][y + 1] != '1' && x-1 >= 1 && x-1 <= ROW && y+1 >= 1 && y+1 <= COL)check(mine, show, x - 1, y + 1);
	if (cnt == 0 && show[x ][y - 1] == '*' && mine[x ][y - 1] != '1' && x >= 1 && x <= ROW && y-1 >= 1 && y-1 <= COL)check(mine, show, x , y - 1);
	if (cnt == 0 && show[x ][y + 1] == '*' && mine[x ][y + 1] != '1' && x >= 1 && x <= ROW && y+1 >= 1 && y+1 <= COL)check(mine, show, x , y + 1);
	if (cnt == 0 && show[x + 1][y - 1] == '*' && mine[x + 1][y - 1] != '1' && x+1 >= 1 && x+1 <= ROW && y-1 >= 1 && y-1 <= COL)check(mine, show, x +1, y - 1);
	if (cnt == 0 && show[x + 1][y ] == '*' && mine[x + 1][y ] != '1' && x+1 >= 1 && x+1 <= ROW && y >= 1 && y <= COL)check(mine, show, x +1, y );
	if (cnt == 0 && show[x +1][y + 1] == '*' && mine[x + 1][y + 1] != '1' && x+1 >= 1 && x+1 <= ROW && y+1 >= 1 && y+1 <= COL)check(mine, show, x +1, y + 1);
	return;
}
void setMine(char mine[][COLS], int num) {
	int cnt = 0;
	while (cnt<num) {
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		if (mine[x][y] != '1') { mine[x][y] = '1'; cnt++; }
		else continue;
	}
}
void printBoard(char show[][COLS]) {
	printf("--------------------------------\n");
	for (int j = 0; j <= COL; j++)printf("%d |", j);
	printf("\n");
	for (int i = 1; i <= ROW; i++) {
		printf("%d |", i);
		for (int j = 1; j <= COL; j++) {
			printf("%c  ", show[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------------\n");
}

void game() {
	srand((unsigned int)time(NULL));
	int num = EZ_MINE;//更改游戏难度
	char mine[ROWS][COLS] = { 0 };
	init_board(mine, '0');
	setMine(mine, num);
	char show[ROWS][COLS] = { 0 };
	init_board(show, '*');
	
	while (win) {
		int x = 0, y = 0;
	//	printBoard(mine);
		printBoard(show);
		printf( "请输入要排查的坐标：");
		scanf_s("%d%d", &x, &y);
		if (mine[x][y] != '1') {
			if (show[x][y] != '*') {
				printf("已经排查过了\n");
				continue;
			}
			check(mine, show,x, y);			
			
			
		}
		else {
			
			printBoard(mine);
			printf("你寄了\n");
			break;
		}
	//	time_t delay = 0.1*CLOCKS_PER_SEC;
	//	time_t now = clock();
	//	while (clock() - now < delay);
	}
	if (win == 0) {
		printBoard(mine);
		printf("你赢了\n");
	}
}
void menu() {
	printf("*************************\n");
	printf("*******   1.play   ******\n");
	printf("*******   0.exit   ******\n");
	printf("*************************\n");
	
}