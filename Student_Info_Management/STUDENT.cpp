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
	cout << "5. Sort by ID" << endl;
	cout << "6. Find student" << endl;
	cout << "0. Quit" << endl;
}
stu* fread(){
	stu* head = new stu;
	stu* ret = head;
	int f = 0;
	FILE* pf = fopen("stu_info.txt", "r");
	int num, math, computer; char name[20];
	while (~fscanf(pf, "%d %s %d %d", &num, name, &math, &computer)) {
		if (f == 0) {
			f = 1;
			head->num = num; head->math = math; head->computer = computer;
			strcpy(head->name, name);
		}
		else {
			stu* p = new stu;
			p->num = num; p->math = math; p->computer = computer;
			strcpy(p->name, name);
			head->next = p;
			head = head->next;
		}
	}
	return ret;
}

stu* In(stu*pre) {
	stu* in = new stu;
	system("cls");
	cout << "Input student's ID : ";
	cin >> in->num;
	cout<< "Input student's name : ";
	cin >> in->name;
	cout << "Input student's Math score : ";
	cin >> in->math;
	cout << "Input student's Computer score : ";
	cin >> in->computer;
	pre->next = in;
	cout << "\nInsert Successfully! " << endl;
	
	return in;
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
	cout << "1.ID" << endl;
	cout << "2.name" << endl;
	cout << "3.Math" << endl;
	cout << "4.Computer" << endl;
	int choice = 0;
	cin >> choice;
	if (choice ==1) {
		cout << "Input integer:";
		int tmp;
		cin >> tmp;
		p->num = tmp;
		cout << "\nModified successfully!\n";
	}
	else if (choice == 3) {
		cout << "Input integer:";
		int tmp;
		cin >> tmp;
		p->math = tmp;
		cout << "\nModified successfully!\n";
	}
	else if (choice == 4) {
		cout << "Input integer:";
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
	for (p = head; p!= NULL; p = p->next) {
		printf("__________________________________\n");
		printf("%d\t|%s\t|%d\t|%d\n", p->num, p->name, p->math, p->computer);
		printf("__________________________________\n");
	}
}





void print_stu(stu* head) {
	system("cls");
	b:
	cout << "Input student's ID: ";
	int tmp;
	cin >> tmp;
	for (stu* ps = head; ps!=NULL; ps = ps->next) {
		if (ps->num == tmp) {
			printf("Name: %s\n", ps->name);
			printf("ID: %d\n", ps->num);
			printf("Math: %d\n", ps->math);
			printf("Computer: %d\n", ps->computer);
			return;
		}
	}
	cout << "Invalid!\n";
	goto b;;
}

void save(stu* head) {
	FILE* pf = fopen("stu_info.txt", "w");
	for (stu* p = head; p!= NULL; p = p->next) {
		fprintf(pf, "%d %s %d %d\n",p->num,p->name,p->math,p->computer);
	}
	fclose(pf);
}


stu* merge(stu* h1, stu* h2) {
	stu* ret, * p1 = h1, * p2 = h2, * m;
	if (h1->num >= h2->num) {
		ret = h2;
		p2 = h2->next;
		while (p1 && p2) {
			if (p1->num >= p2->num) {
				h2->next = p2;
				p2 = p2->next;
				h2 = h2->next;
			}
			else {
				stu* next = h2->next;
				h2->next = p1;
				h2 = h2->next;
				p1 = p1->next;
			}
		}
		if (!p1) {
			h2->next = p2;
		}
		else {
			h2->next = p1;
		}
	}
	else {
		ret = h1;
		p1 = h1->next;
		while (p1 && p2) {
			if (p1->num >= p2->num) {
				h1->next = p2;
				p2 = p2->next;
				h1 = h1->next;
			}
			else {
				stu* next = h1->next;
				h1->next = p1;
				h1 = h1->next;
				p1 = p1->next;
			}
		}
		if (!p1) {
			h1->next = p2;
		}
		else {
			h1->next = p1;
		}
	}
	return ret;
}
stu* div(stu* head) {
	if (!head->next)return head;
	stu* slow = head, * fast = head;
	for (fast = head; fast->next && fast->next->next; fast = fast->next->next) {
		slow = slow->next;
	}
	fast = slow->next;
	slow->next = NULL;
	slow = head;
	slow = div(slow);
	fast = div(fast);
	stu* ret = merge(slow, fast);
	return ret;
}
stu* sortList(stu* head) {
	if (head == NULL)return NULL;
	cout << "Sorted successfully!\n";
	return div(head);
}