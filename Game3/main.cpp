
#include "game.h"
#pragma comment (lib,"winmm.lib")
int main() {
	srand((unsigned int)time(NULL));
	initgraph(1600, 900);
	BGM();
	HWND wnd = GetHWnd();
	SetWindowText(wnd, "PAC MAN");
	ExMessage msg;
	bool replay = false;
	again:
	menu();
	replay = false;
	while (1) {
		
		if (peekmessage(&msg,EM_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				if (msg.x > 650 && msg.x < 950 && msg.y>400 && msg.y < 500) {
					replay=game();
					if (replay)goto again;
					else return 0;
				}
				else if (msg.x > 650 && msg.x < 950 && msg.y>600 && msg.y < 700) {
					closegraph();
					return 0;
				}
				break;
			}
		}
	}
	return 0;
}