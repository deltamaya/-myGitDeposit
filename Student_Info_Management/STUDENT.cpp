#define _CRT_SECURE_NO_WARNINGS 1
#include "STUDENT.h"
#ifndef MAXN
	#define MAXN 50
#endif
using namespace std;
void menu() {
	cout << "Select:  " << endl;
	cout << "1. Insert info" << endl;
	cout << "2. Modify info" << endl;
	cout << "3. Delete info" << endl;
	cout << "4. Print chart" << endl;
	cout << "0. Quit" << endl;
}
stu* fread(){
	stu* head = new stu;
	stu* p=head;
	FILE* pf = fopen("stu_info.txt", "r");
	while (~fscanf(pf, "%d %s %d %d", &p->num, p->name, &p->math, &p->computer)) {
		stu* next = new stu;
		p ->next=next;
		p = p->next;
	}
	return head;
}

stu* In(stu*pre) {
	stu* in = new stu;
	system("cls");
	cout << "Input student's ID : ";
	cin >> pre->num;
	cout<< "Input student's name : ";
	cin >> pre->name;
	cout << "Input student's Math score : ";
	cin >> pre->math;
	cout << "Input student's Computer score : ";
	cin >> pre->computer;
	pre->next = in;
	cout << "\nInsert Successfully! " << endl;
	
	return pre->next;
}


void Modify(stu*head) {
	b:
	cout << "Input student's num: ";
	int num;
	cin >> num; 
	stu* p,*pre;
	for (p = head; p!= NULL; p = p->next) {
		if (p->num == num)break;
		pre = p;
	}
	if (p == NULL) {
		cout << "Do Not Exist!\n";
		goto b;
	}
again:
	system("cls");
	cout << "Select:" << endl;
	cout << "1.num" << endl;
	cout << "2.name" << endl;
	cout << "3.Math" << endl;
	cout << "4.Computer" << endl;
	int choice = 0;
	cin >> choice;
	if (choice ==1) {
		cout << "Input interger:";
		int tmp;
		cin >> tmp;
		p->num = tmp;
		cout << "\nModified successfully!\n";
	}
	else if (choice == 3) {
		cout << "Input interger:";
		int tmp;
		cin >> tmp;
		p->math = tmp;
		cout << "\nModified successfully!\n";
	}
	else if (choice == 4) {
		cout << "Input interger:";
		int tmp;
		cin >> tmp;
		p->computer = tmp;
		cout << "\nModified successfully!\n";
	}
	else if (choice == 2) {
		cout << "Input new name:";
			char n[20];
		cin >> n;
		strcpy(p->name, n);
		cout << "\nModified successfully!\n";
	}
	else {
		cout << "Invalid value!\n";
		goto again;
	}
	save(head);
}


stu* Del(stu*head) {
b:
	system("cls");
	cout << "Input student's num: ";
	int num;
	cin >> num;
	stu* p, * pre=head;
	for (p = head; p != NULL; p = p->next) {
		if (p->num == num)break;
		pre = p;
	}
	if (p == NULL) {
		cout << "Do Not Exist!\n";
		goto b;
	}
	if (p == head) {
		head = head->next;
	}
	else pre->next = p->next;
	cout << "Delete successfully!\n";
	save(head);
	return head;
}


void print_all(stu*head) {
	
	printf("__________________________________\n");
	printf("ID\t|Name\t|Math\t|Computer\n");
	FILE* pf = fopen("stu_info.txt", "r");
	stu* p;
	for (p = head; p->next!= NULL; p = p->next) {
		printf("__________________________________\n");
		printf("%d\t|%s\t|%d\t|%d\n", p->num, p->name, p->math, p->computer);
		printf("__________________________________\n");
	}
}





void print_stu(stu* ps) {
	printf("__________________________________\n");
	printf("%d\t|%s\t|%d\t|%d\n", ps->num,ps->name,ps->math,ps->computer);
	printf("__________________________________\n");
}

void save(stu* head) {
	FILE* pf = fopen("stu_info.txt", "w");
	for (stu* p = head; p->next != NULL; p = p->next) {
		fprintf(pf, "%d %s %d %d\n",p->num,p->name,p->math,p->computer);
	}
	fclose(pf);
}