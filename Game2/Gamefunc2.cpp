#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

#include "game2.h"
using namespace std;
int main() {
	int choice = 0;
	do {
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			game(); 
			break;
		case 2:
			cout << "�˳���Ϸ" << endl; 
			break;
		default:
			cout << "ѡ���������ѡ��" << endl;
			break;
		}
	} while (choice);
	
	return 0 ^ 0;
}