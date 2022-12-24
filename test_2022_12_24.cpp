#include <stdio.h>
#include <easyx.h>
#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment (lib,"winmm.lib")
void BGM() {
	mciSendString("open ./Roses.mp3",0,0,0);
	mciSendString("play ./Roses.mp3", 0, 0, 0);
}
void button(int x, int y, int w, int h, const char* t) {
	solidrectangle(x, y, x + w, y + h);
	settextcolor(BLACK);
	settextstyle(30, 0, "Î¢ÈíÑÅºÚ");
	setbkmode(TRANSPARENT);
	char text[50];
	strcpy(text, t);
	int dx = (w-textwidth(text))/2+x;
	int dy = (h - textheight(text)) / 2 + y;
	outtextxy(dx, dy, t);
}
int main() {
	BGM();
	
	/*initgraph(640, 480,SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(RGB(255, 0, 0));
	setlinecolor(RGB(255, 0, 0));
	fillcircle(50, 50, 50);
	setfillcolor(BLACK);
	setlinecolor(BLACK);
	solidrectangle(100, 100, 200, 200);
	settextcolor(RGB(176, 35, 41));
	settextstyle(50,0,"Î¢ÈíÑÅºÚ");
	setbkmode(TRANSPARENT);
	outtextxy(100, 100, "TTTTTEXT");
	getchar();
	closegraph();*/
	initgraph(640, 480,SHOWCONSOLE);
	HWND g = GetHWnd();
	SetWindowText(g, "LOVELOVELOVE");
	int ok=MessageBox(g, "ÎÒ°®Äã", "ÌáÊ¾",MB_OKCANCEL);
	if (ok == IDOK)printf("yes\n");
	else printf("NO\n");
	int x = 50, y = 50;
	while (1) {
		BeginBatchDraw();
	setfillcolor(RGB(121, 21, 21));
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	IMAGE img;
	loadimage(&img, "./tt.jpg",250,250);
	putimage(0, 0, &img);
	button(300, 300, 200, 50, "RESET");
	ExMessage msg;
	
		fillcircle(x, y, 20);
		FlushBatchDraw();
		
		if (GetAsyncKeyState(VK_UP)|| GetAsyncKeyState('W')) {
			y --;
		}
		if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
			y ++;
		}
		if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
			x --;
		}
		if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
			x ++;
		}
		if (_kbhit()) {
			char key = _getch();
			
			/*switch (key)
			{
			case 72:
			case 'w':
			case 'W':
				y -= 5;
				break;
			case 80:
			case 's':
			case 'S':
				y += 5;
				break;
			case 75:
			case 'a':
			case 'A':
				x -= 5;
				break;
			case 77:
			case 'd':
			case 'D':
				x += 5;
				break;
			}*/
		}
		    
			if (peekmessage(&msg, EM_MOUSE)) {
				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					if (msg.x >= 300 && msg.x <= 500 && msg.y >= 300 && msg.y <= 350) {
						printf("pushed\n");
						x = 50; y = 50;
						
					}
					break;
				case WM_RBUTTONDOWN:
					if (msg.x >= 300 && msg.x <= 500 && msg.y >= 300 && msg.y <= 350) {
						goto end;

					}
				default:
					break;
				}
			}
		
	}
	EndBatchDraw();
	getchar();
	end:
	closegraph();

	return 0;

}
