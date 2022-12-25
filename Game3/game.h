#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <easyx.h>
#include <time.h>
#include <stdlib.h>
#include <mmsystem.h>
#include <assert.h>

#define BNUM 10
void menu();
bool game();
void buttony();
void BGM();
typedef struct bean {
	int x;
	int y;
	bool exsit=true;
	bean* next = NULL;
};