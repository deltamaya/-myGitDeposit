#include <iostream>
#include <time.h>
#include<stdlib.h>
using namespace std;
#define COL 3
#define ROW 3

void menu() {
	printf("****************************\n");
	printf("*******1.play  0.exit*******\n");
	printf("****************************\n");
	cout << "�����룺";

}
void print_board(char b[][COL]) {
	int i=0, j=0;
	printf("   ");
	for (j = 0; j < COL; j++) {
		printf(" %d ", j+1);
		if (j < COL - 1)printf(" ");
		
	}printf(" y \n");
	for (i = 0; i < ROW; i++) {
		printf(" %d ", i + 1);
		for (j = 0; j < COL; j++) {
			printf(" %c ",b[i][j]);
			if (j < COL - 1)printf("|");
		}
		printf("\n");
		if (i < ROW - 1) {
			printf("   ");
			for (j = 0; j < COL; j++) {
				printf("---");
				if (j < COL - 1)printf("|");
			}
			printf("\n");
		}
		
	}
	printf(" x \n");
}
void init_board(char b[][COL]) {
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++)b[i][j] = ' ';
	}
}
char check(char b[][COL]) {
	int i = 0, j = 0;
	int f = 0;
	for (i = 0; i < ROW; i++) {
		if (b[i][0] == b[i][1] && b[i][0] == b[i][2] && b[i][0] != ' ')return b[i][0];		
	}
	for (j = 0; j < COL; j++) {
		if (b[0][j] == b[1][j] && b[1][j] == b[2][j] && b[0][j] != ' ')return b[0][j];
	}
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] != ' ')return b[0][0];
	if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[1][1] != ' ')return b[1][1];
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			if (b[i][j] == ' ')return 'c';
		}
	}
	return 'b';
}
void player_move(char b[][COL]) {
	int r = 0, c = 0;
	recin:
	cout << "������壬�������������x y:";
	cin >> r >> c;
	if (b[r - 1][c - 1] != ' ') {
		cout << "����Ƿ���" << endl;
		goto recin;
	}
	b[r-1][c-1] = '*';
}
void computer_move(char b[][COL]) {
	int r = 0, c = 0;
	
	recin:
	r = rand() % 3;
	c = rand() % 3;
	if (b[r][c] != ' ')goto recin;
	b[r][c] = '&';
}
void game() {
	srand(time(NULL));
	char b[ROW][COL]={0};
	init_board(b);
	while (check(b)=='c') {
		print_board(b);
		player_move(b);
		print_board(b);
		if (check(b) == '*') {
			cout << "��һ�ʤ��" << endl;
			break;
		}
		else if (check(b) == 'b') {
			cout << "ƽ�֣�" << endl;
			break;
		}cout << "��������" << endl;
		clock_t delay = 1 * CLOCKS_PER_SEC;
		clock_t now = clock();
		while (clock() - now < delay);
		computer_move(b);
		if (check(b) == '&') {
			cout << "���ʧ�ܣ�" << endl;
			print_board(b);
			break;
		}
		else if (check(b) == 'b') {
			print_board(b);
			cout << "ƽ�֣�" << endl;
			break;
		}
	}
}