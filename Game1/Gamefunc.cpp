#include <iostream>
#include "game1.h"

using namespace std;
int main() {
	int choice = 0;
	do{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 0: 
			cout << "ÓÎÏ·ÍË³ö" << endl; break;
		case 1:
			game(); break;
		default:
			cout << "ÊäÈë´íÎó" << endl; break;
			
		}
	} while (choice);
return 0;
}