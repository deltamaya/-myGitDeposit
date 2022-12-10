#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cstdio>
#define MAXN 50
using namespace std;
struct stu {
	char name[20];
	int num;
	int math;
	int computer;
	stu* next=NULL;
};
void menu();
stu* In(stu*);
void Modify(stu*);
stu* Del(stu*);
void print_all(stu*);
void print_stu(stu*);
bool check(int);
void save(stu*);
stu* fread();
stu* sortList(stu*);