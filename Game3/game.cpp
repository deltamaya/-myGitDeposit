#include "game.h"
int remain = BNUM;
int s = 1;
int board[16][16] = {
	{-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0},
	{0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0},
	{0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0},
	{0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
	{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
	{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
	{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
	{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int copy[16][16] = {
	{-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0},
	{0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0},
	{0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0},
	{0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
	{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
	{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
	{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
	{0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
void initboard() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			board[i][j] = copy[i][j];
		}
	}
}
void buttony(int x, int y, int w, int h, const char* t) {
	setfillcolor(YELLOW);
	settextcolor(BLACK);
	settextstyle(50, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	setlinecolor(YELLOW);
	solidrectangle(x, y, x + w, y + h);
	char text[50];
	strcpy(text, t);
	int len = textwidth(text);
	int hei = textheight(text);
	outtextxy(x+(w-len)/2, y+(h-hei)/2, t);
}
void BGM() {
	mciSendString("open ./BGM.mp3", 0, 0, 0);
	mciSendString("play ./BGM.mp3 repeat", 0, 0, 0);
}
void menu() {
	setbkcolor(RGB(70, 203, 255));	
	cleardevice();
	settextstyle(200, 0,NULL);
	settextcolor(YELLOW);
	int len = textwidth("P A C  M A N");
	outtextxy((1600-len)/2, 100, "P A C  M A N");
	buttony(650, 400,300,100, "开始游戏");
	buttony(650, 600, 300, 100, "退出游戏");
}

void showmap() {
	setlinecolor(BLACK);
	setlinestyle(0,50);
	rectangle(375, 25, 1225, 875);
	buttony(50, 50, 200, 100, "退出");
	setlinestyle(0, 5);
	buttony(1350, 50, 200, 100,"得分:");
	char score[5];
	itoa(s, score, 10);
	buttony(1350, 150, 200, 100,score );
	int i, j;
	
	for (i = 0; i < 16; i++) {
		for (j = 0; j < 16; j++) {
			if (board[i][j] == 0) {
				setfillcolor(WHITE);
				solidcircle(j * 50 + 425, i * 50 + 75, 10);
			}
			else if (board[i][j] == 1) {
				setfillcolor(BLUE);
				solidrectangle(j * 50 + 400, i * 50 + 50, j * 50 + 50+400, i * 50 + 50+50);
			}
			else {
				;
			}
		}
	}
}
void showplayer(int x ,int y) {
	cleardevice();
	showmap();
	setfillcolor(YELLOW);
	solidcircle(x, y, 25);

}
void showmob(int ex, int ey) {
	setfillcolor(RGB(255, 49, 0));
	solidroundrect(ex - 25, ey - 25, ex + 25, ey + 25,10,10);
}
bool inmap(int x, int y) {
	if (x >= 425 && x <= 1175 && y >= 75 && y <= 825)return true;
	else return false;
}
bool check(int x, int y, int ex, int ey) {
	if (abs(x - ex) <= 25 && abs(y - ey) <= 25)return true;
	else return false;
}
//bool dfs(int ei, int ej, int i, int j, int dir) {
//	bool ret = 0;
//	if (ei - 1 >= 0 && copy[ei - 1][ej] == 0) {
//		if (ei - 1 == i && ej == j)return 1;
//		copy[ei][ej] = -1;
//		ret |= dfs(ei - 1, ej, i, j, 1);
//		copy[ei][ej] = 0;
//	}
//	if (ei + 1 < 16 && copy[ei + 1][ej] == 0) {
//		if (ei + 1 == i && ej == j)return 2;
//		copy[ei][ej] = -1;
//		ret |= dfs(ei + 1, ej, i, j, 2);
//		copy[ei][ej] = 0;
//	}
//	if (ej - 1 >= 0 && copy[ei][ej - 1] == 0) {
//		if (ei == i && ej - 1 == j)return 3;
//		copy[ei][ej] = -1;
//		ret |= dfs(ei, ej - 1, i, j, 3);
//		copy[ei][ej] = 0;
//	}
//	if (ei + 1 < 16 && copy[ei][ej + 1] == 0) {
//		if (ei == i && ej + 1 == j)return 4;
//		copy[ei][ej] = -1;
//		ret |= dfs(ei, ej + 1, i, j, 4);
//		copy[ei][ej] = 0;
//	}
//	return ret;
//}
//int oridir(int ei, int ej, int i, int j) {
//	bool ret = 0;
//	if (ei - 1 >= 0 && copy[ei - 1][ej] ==0) {
//		if (ei - 1 == i && ej == j)return 1;
//		copy[ei][ej] = -1;
//		ret=dfs(ei - 1, ej, i, j,1);
//		copy[ei][ej] = 0;
//		if (ret)return 1;
//	}
//	if (ei + 1 < 16 && copy[ei + 1][ej] == 0) {
//		if (ei + 1 == i && ej == j)return 2;
//		copy[ei][ej] = -1;
//		ret=dfs(ei + 1, ej, i, j,2);
//		copy[ei][ej] = 0;
//		if (ret)return 1;
//	}
//	if (ej - 1 >= 0 && copy[ei][ej-1] == 0) {
//		if (ei  == i && ej -1== j)return 3;
//		copy[ei][ej] = -1;
//		ret=dfs(ei, ej-1, i, j,3);
//		copy[ei][ej] = 0;
//		if (ret)return 1;
//	}
//	if (ei +1<16 && copy[ei][ej+1] == 0) {
//		if (ei== i && ej +1== j)return 4;
//		copy[ei][ej] = -1;
//		ret=dfs(ei, ej+1, i, j,4);
//		copy[ei][ej] = 0;
//		if (ret)return 1;
//	}
//	return ret;
//}
void mobmove(int &ex,int& ey,int& ei, int& ej,int i,int j,int m) {
	int dir = 0;
	if (i > ei && board[ei + 1][ej] != 1)dir = 1;
	else if (i < ei && board[ei - 1][ej] != 1)dir = 2;
	else if (j < ej && board[ei][ej - 1] != 1)dir = 3;
	else if (j > ej && board[ei][ej + 1] != 1)dir = 4;
	if (dir == 1) {
		ex++;
		if (m == 49)ei++;
	}
	else if (dir == 2) {
		ex--;
		if (m == 49)ei--;
	}
	else if (dir == 3) {
		ey--;
		if (m == 49)ej--;
	}
	else if (dir == 4) {
		ey++;
		if (m == 49)ej++;
	}
}
bool game() {
	rep:
	initboard();
	int l = 0, r = 0, u = 0, d = 0;
	HWND wnd = GetHWnd();
	cleardevice();
	showmap(); 
	s = 0;
	//生成豆子链表
	//for (int i = 0; i < BNUM; i++) {
	//	bean* next = new bean;
	//	int bx = (rand() % 750) + 425;
	//	int by = (rand() % 750) + 75;
	//	if (i == 0) {
	//		head = next;
	//		head->x = bx;
	//		head->y = by;
	//		p = head;
	//	}
	//	else {
	//		next->x = bx;
	//		next->y = by;
	//		p->next = next;
	//		p = p->next;
	//	}
	//}
	int hp = 1; int x = 425, y = 75;
	int i = 0, j = 0; 
	int ex = 1175, ey = 825;
	int ei = 15, ej = 15;
	BeginBatchDraw();
	while (hp) {
		FlushBatchDraw();
		showplayer(x, y);
		showmob(ex, ey);
		//showbean(head);
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				if (msg.x > 50 && msg.x < 250 && msg.y>50 && msg.y < 150) {
					EndBatchDraw();
					return true;

				}
				break;
			}
		}
		if (s >= 135) {
			int ok = MessageBox(wnd, "你赢了!\n选择 确定 退出游戏\n选择 取消 返回菜单", "恭喜！", MB_OKCANCEL);
			if (ok == IDOK)break;
			else {
				EndBatchDraw();
				return true;
			}
		}
		char k;
		if (_kbhit()) {
			k = _getch();
			switch (k) {
			case 72:
			case 'W':
				l = 0, r = 0, u = 1, d = 0;
				break;
			case 80:
			case 'S':
				l = 0, r = 0, u = 0, d = 1;
				break;
			case 75:
			case 'A':
				l = 1, r = 0, u = 0, d = 0;
				break;
			case 77:
			case 'D':
				l = 0, r = 1, u = 0, d = 0;
				break;
			}
		}
		
		int mobdir = 0;
		//玩家左移逻辑
		if (l && !r && !u && !d && x > 425 && board[i][j - 1] != 1) {
			j--;
			int dir = 0;
			if (i > ei && board[ei + 1][ej] != 1)dir = 1;
			else if (i < ei && board[ei - 1][ej] != 1)dir = 2;
			else if (j < ej && board[ei][ej - 1] != 1)dir = 3;
			else if (j > ej && board[ei][ej + 1] != 1)dir = 4;
			for (int m = 0; m < 50; m++) {
				x--;
				if (dir == 1) {
					ey++;
					if (m == 49)ei++;
				}
				else if (dir == 2) {
					ey--;
					if (m == 49)ei--;
				}
				else if (dir == 3) {
					ex--;
					if (m == 49)ej--;
				}
				else if (dir == 4) {
					ex++;
					if (m == 49)ej++;
				}
				FlushBatchDraw();
				showplayer(x, y);
				showmob(ex, ey);
				if (check(x, y, ex, ey)) {
					hp--;
					break;
				}
				Sleep(2);
				if (peekmessage(&msg, EM_MOUSE)) {
					switch (msg.message) {
					case WM_LBUTTONDOWN:
						if (msg.x > 50 && msg.x < 250 && msg.y>50 && msg.y < 150) {
							EndBatchDraw();
							return true;

						}
						break;
					}
				}
				if (_kbhit()) {
					k = _getch();
					switch (k) {
					case 72:
					case 'W':
						l = 0, r = 0, u = 1, d = 0;
						break;
					case 80:
					case 'S':
						l = 0, r = 0, u = 0, d = 1;
						break;
					case 75:
					case 'A':
						l = 1, r = 0, u = 0, d = 0;
						break;
					case 77:
					case 'D':
						l = 0, r = 1, u = 0, d = 0;
						break;
					}
				}

			}
			if (board[i][j] == 0) { board[i][j] = -1; s++; }
		}
		//玩家右移逻辑
		else if (!l && r && !u && !d && x < 1175 && board[i][j + 1] != 1) {
			j++;
			int dir = 0;
			if (i > ei && board[ei + 1][ej] != 1)dir = 1;
			else if (i < ei && board[ei - 1][ej] != 1)dir = 2;
			else if (j < ej && board[ei][ej - 1] != 1)dir = 3;
			else if (j > ej && board[ei][ej + 1] != 1)dir = 4;
			for (int m = 0; m < 50; m++) {
				x++;
				if (dir == 1) {
					ey++;
					if (m == 49)ei++;
				}
				else if (dir == 2) {
					ey--;
					if (m == 49)ei--;
				}
				else if (dir == 3) {
					ex--;
					if (m == 49)ej--;
				}
				else if (dir == 4) {
					ex++;
					if (m == 49)ej++;
				}
				FlushBatchDraw();
				showplayer(x, y);
				showmob(ex, ey);
				if (check(x, y, ex, ey)) {
					hp--;
					break;
				}
				Sleep(2);
				if (peekmessage(&msg, EM_MOUSE)) {
					switch (msg.message) {
					case WM_LBUTTONDOWN:
						if (msg.x > 50 && msg.x < 250 && msg.y>50 && msg.y < 150) {
							EndBatchDraw();
							return true;

						}
						break;
					}
				}
				if (_kbhit()) {
					k = _getch();
					switch (k) {
					case 72:
					case 'W':
						l = 0, r = 0, u = 1, d = 0;
						break;
					case 80:
					case 'S':
						l = 0, r = 0, u = 0, d = 1;
						break;
					case 75:
					case 'A':
						l = 1, r = 0, u = 0, d = 0;
						break;
					case 77:
					case 'D':
						l = 0, r = 1, u = 0, d = 0;
						break;
					}
				}
			}
			if (board[i][j] == 0) {
				board[i][j] = -1; s++;
			}
		}
		//玩家上移逻辑
		else if (!l && !r && u && !d && y > 75 && board[i - 1][j] != 1) {
			i--;
			int dir = 0;
			if (i > ei && board[ei + 1][ej] != 1)dir = 1;
			else if (i < ei && board[ei - 1][ej] != 1)dir = 2;
			else if (j < ej && board[ei][ej - 1] != 1)dir = 3;
			else if (j > ej && board[ei][ej + 1] != 1)dir = 4;
			for (int m = 0; m < 50; m++) {
				y--;
				if (dir == 1) {
					ey++;
					if (m == 49)ei++;
				}
				else if (dir == 2) {
					ey--;
					if (m == 49)ei--;
				}
				else if (dir == 3) {
					ex--;
					if (m == 49)ej--;
				}
				else if (dir == 4) {
					ex++;
					if (m == 49)ej++;
				}
				FlushBatchDraw();
				showplayer(x, y); showmob(ex, ey);
				Sleep(2);
				if (check(x, y, ex, ey)) {
					hp--;
					break;
				}
				if (peekmessage(&msg, EM_MOUSE)) {
					switch (msg.message) {
					case WM_LBUTTONDOWN:
						if (msg.x > 50 && msg.x < 250 && msg.y>50 && msg.y < 150) {
							EndBatchDraw();
							return true;

						}
						break;
					}
				}
				if (_kbhit()) {
					k = _getch();
					switch (k) {
					case 72:
					case 'W':
						l = 0, r = 0, u = 1, d = 0;
						break;
					case 80:
					case 'S':
						l = 0, r = 0, u = 0, d = 1;
						break;
					case 75:
					case 'A':
						l = 1, r = 0, u = 0, d = 0;
						break;
					case 77:
					case 'D':
						l = 0, r = 1, u = 0, d = 0;
						break;
					}
				}
			}
			if (board[i][j] == 0) {
				board[i][j] = -1; s++;
			}
		}
		//玩家下移逻辑
		else if (!l && !r && !u && d && y < 825 && board[i + 1][j] != 1) {
			i++;
			int dir = 0;
			if (i > ei && board[ei + 1][ej] != 1)dir = 1;
			else if (i < ei && board[ei - 1][ej] != 1)dir = 2;
			else if (j < ej && board[ei][ej - 1] != 1)dir = 3;
			else if (j > ej && board[ei][ej + 1] != 1)dir = 4;

			for (int m = 0; m < 50; m++) {
				y++;
				if (dir == 1) {
					ey++;
					if (m == 49)ei++;
				}
				else if (dir == 2) {
					ey--;
					if (m == 49)ei--;
				}
				else if (dir == 3) {
					ex--;
					if (m == 49)ej--;
				}
				else if (dir == 4) {
					ex++;
					if (m == 49)ej++;
				}
				FlushBatchDraw();
				showplayer(x, y);
				showmob(ex, ey);
				Sleep(2);
				if (check(x, y, ex, ey)) {
					hp--;
					break;
				}
				if (peekmessage(&msg, EM_MOUSE)) {
					switch (msg.message) {
					case WM_LBUTTONDOWN:
						if (msg.x > 50 && msg.x < 250 && msg.y>50 && msg.y < 150) {
							EndBatchDraw();
							return true;

						}
						break;
					}
				}
				if (_kbhit()) {
					k = _getch();
					switch (k) {
					case 72:
					case 'W':
						l = 0, r = 0, u = 1, d = 0;
						break;
					case 80:
					case 'S':
						l = 0, r = 0, u = 0, d = 1;
						break;
					case 75:
					case 'A':
						l = 1, r = 0, u = 0, d = 0;
						break;
					case 77:
					case 'D':
						l = 0, r = 1, u = 0, d = 0;
						break;
					}
				}
			}
			if (board[i][j] == 0) {
				board[i][j] = -1; s++;
			}
		}

	}
	if (hp == 0) {
		int ok = MessageBox(wnd, "你输了!\n选择 确定 重新开始\n选择 取消 返回菜单", "遗憾！", MB_OKCANCEL);
		if (ok == IDOK) {
			goto rep;
		}
		else {
			EndBatchDraw();
			return true;
		}
	}
	EndBatchDraw();
	closegraph();
	return false;
}