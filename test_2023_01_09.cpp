#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define swap(x,y) {int t=x;x=y;y=t;}
bool check(int (*p)[5], int len, int target) {
	int i, j;
	int l, r;
	if (p[0][0] > target || p[len - 1][len - 1] < target) { return false; }
	else {
		for (i = 0; i < len; i++) {
			if (p[i][len - i] < target) {
				for (j = i; j < len - i; j++) {
					if (p[j][len - i] == target) {
						return true;
					}
				}
			}
			else if (p[i][len - i] > target) {
				for (j = i; j < len - i; j++) {
					if (p[i][j] == target) {
						return true;
					}
				}
			}
			else return true;
		}
	}
}
void spinstr(char* s, int len, int k) {
	int l = 0, r = len - 1;
	while (l < r) {
		swap(s[l], s[r]);
		l++; r--;
	}
	l = 0; r = k-1;
	while (l < r) {
		swap(s[l], s[r]);
		l++; r--;
	}
	l = k ; r = len - 1;
	while (l < r) {
		swap(s[l], s[r]);
		l++; r--;
	}

}
bool is_spin(const char* a,const char* b) {
	/*int alen = strlen(a); int blen = strlen(b);
	int i=0, j=0;
	for (j = 0; j < blen; j++) {
		if (b[j] == a[0]) {
			break;
		}
	}
	while (j < blen&&i<alen) {
		if (a[i++] != b[j++])return false;
	}
	j = 0; 
	while (i < alen && j < blen) {
		if (a[i++] != b[j++])return false;
	}
	return true;*/
	char tmp[500] = { 0 };
	strcpy(tmp, a);
	strcat(tmp, a);
	return strstr(tmp, b) != NULL;
}
struct stu {
	int score;
	char name[20];
};
int double_cmp(const void* x,const void* y) {

	if (*(double*)x > *(double*)y)return 1;
	else if (*(double*)x < *(double*)y)return -1;
	else return 0;
}
int stu_cmp(const void* x, const void* y) {

	if (((stu*)x)->score > ((stu*)y)->score)return 1;
	else if (((stu*)x)->score > ((stu*)y)->score)return -1;
	else return 0;
}
void my_swap(size_t width, const void* x, const void* y) {
	size_t i = 0;
	for (i = 0; i < width; i++) {
		char t = *((char*)x+i);
		*((char*)x+i) = *((char*)y+i);
		*((char*)y+i) = t;
	}
}
void my_qsort(void* base, size_t len, size_t width, int(*cmp)(const void* x, const void* y)) {
	int i, j;
	for (i = 0; i < len; i+=1) {
		for (j = width; j < width*(len-i); j += width) {
			if (cmp((char*)base + j - width, (char*)base + j) > 0) {
				my_swap(width,(char*)base + j-width, (char*)base + j );
			}
		}
	}
}
int main() {
//	for (a = 1; a <= 5; a++) {
//		for (b = 1; b <= 5; b++) {
//			for (c = 1; c <= 5; c++) {
//				for (d = 1; d <= 5; d++) {
//					for (e = 1; e <= 5; e++) {
//						int ch[6] = { 0 };
//						ch[a] = 1; ch[b] = 1; ch[c] = 1; ch[d] = 1; ch[e] = 1;
//						for (int i = 1; i <=5; i++) { 
//							if (ch[i] != 1)
//								goto skip;
//						}
//						if (((b==2)+(a==3)==1)&& ((b == 2) + (e==4) == 1)&& ((c==1) + (d==2) == 1)&& ((c==5) + (d==3) == 1)&& ((e==4) + (a==1) == 1)) {
//							goto end;
//						}
//					skip:
//						;
//					}
//				}
//			}
//		}
//	}
//end:
//	
	//a = 1; b = c = d = 0;
	//if ((a != 1) + (c == 1) + (d == 1) + (d != 1) == 3) {
	//	printf("A\n");
	//}
	//b = 1; a = c = d = 0;
	//if ((a != 1) + (c == 1) + (d == 1) + (d != 1) == 3) {
	//	printf("B\n");
	//}
	//c = 1; a = b = d = 0;
	//if ((a != 1) + (c == 1) + (d == 1) + (d != 1) == 3) {
	//	printf("C\n");
	//}
	//d = 1; a = b = c = 0;
	//if ((a != 1) + (c == 1) + (d == 1) + (d != 1) == 3) {
	//	printf("D\n");
	//}
	//int n;
	//while (~scanf("%d", &n)) {
	//	int i = 1,j=0;
	//	int last[101]={0,1,1};
	//	int buf[101];
	//	for (i = 1; i <= n; i++) {
	//		if (i == 1) {
	//			printf("1\n");
	//		}
	//		else if (i == 2) {
	//			printf("1 1\n");
	//		}
	//		else {
	//			for (j = 1; j <= i; j++) {
	//				if (j == 1 || j == i) {
	//					printf("1 ");
	//					buf[j] = 1;
	//				}
	//				else {
	//					printf("%d ", last[j - 1] + last[j]);
	//					buf[j] = last[j - 1] + last[j];
	//				}
	//			}
	//			printf("\n");
	//			for (j = 1; j <= i; j++)last[j] = buf[j];
	//		}
	//	}
	//}
	/*int square[5][5] = {
					{1,4,7,9,15},
					{2,5,8,10,16},
					{3,6,9,11,17},
					{4,7,10,12,18},
					{5,8,11,13,19}
	};
	printf("%d",check(square, 5, 16));*/
	/*char str[] = "abcdef";
	char test[] = "defabc";
	printf("%d\n", is_spin(str, test));
	char tmp[] = "abcdefabcdef";
	printf("%d ", tmp);
	printf("%d ", strstr(tmp, test));*/
	//double t1[5] = {6.4,3.7,0,5.1,1.6};
	//my_qsort(t1, (size_t)sizeof(t1) / sizeof(t1[0]), (size_t)sizeof(double), double_cmp);
	//for (int i = 0; i < 5; i++) {
	//	printf("%.1lf ", t1[i]);
	//}
	//printf("\n");
	//struct stu t2[5] = { {99,"jack"},{87,"mike"},{90,"peter"},{60,"kate"},{100,"maya"} };
	//my_qsort(t2, (size_t)sizeof(t2) / sizeof(t2[0]), (size_t)sizeof(stu), stu_cmp);
	//	for (int i = 0; i < 5; i++) {
	//		printf("%d ", t2[i].score);
	//	}
	//int a = 2;
	//int t[2][3];
	//printf("%d\n", sizeof(t));//sizeof内部的表达式不进行运算
	//printf("%d\n", a);


	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a));//16整个数组的大小
	//printf("%d\n", sizeof(a+0));//4/8首元素的地址的大小
	//printf("%d\n", sizeof(*a));//4首元素的大小
	//printf("%d\n", sizeof(a+1));//4/8第二个元素的地址的大小
	//printf("%d\n", sizeof(a[1]));//4第二个元素的大小
	//printf("%d\n", sizeof(&a));//4/8整个数组的地址的大小
	//printf("%d\n", sizeof(*&a));//16整个数组的大小
	//printf("%d\n", sizeof(&a+1));//4/8数组后面一个地址的大小
	//printf("%d\n", sizeof(&a[0]));//4/8首元素地址的大小
	//printf("%d\n", sizeof(&a[0]+1));//4/8第二个元素地址的大小
	//char arr[] = {'a','b','c','d','e','f'};
	////printf("%d\n", sizeof(arr));//7
	////printf("%d\n", sizeof(arr+0));//4/8
	////printf("%d\n", sizeof(*arr));//1
	////printf("%d\n", sizeof(arr[1]));//1
	////printf("%d\n", sizeof(&arr));//4/8
	////printf("%d\n", sizeof(&arr+1));//4/8
	////printf("%d\n", sizeof(&arr[0]+1));//4/8
	//printf("%d\n", strlen(arr));//随机值X，找不到\0
	//printf("%d\n", strlen(arr+0));//随机值X，同上
	//printf("%d\n", strlen(*arr));//err，*arr是'a',以a的ASCII码值访问内存，非法访问
	//printf("%d\n", strlen(arr[1]));//err，b的ASCII码访问内存，非法访问
	//printf("%d\n", strlen(&arr));//随机值X，找不到\0
	//printf("%d\n", strlen(&arr+1));//随机值X-6，跳过数组之后开始访问，找不到\0
	//printf("%d\n", strlen(&arr[0]+1));//随机值X-1，找不到\0
	//const char* p = "abcdef";
	//printf("%d\n", strlen(p));//6
	//printf("%d\n", strlen(p+1));//5
	//printf("%d\n", strlen(*p));//err
	//printf("%d\n", strlen(p[0]));//err
	//printf("%d\n", strlen(&p));//rand，p指针的地址往后
	//printf("%d\n", strlen(&p+1));//rand，p往后一个往后找
	//printf("%d\n", strlen(& p[0] + 1));//5


//int a[3][4] = { 0 };
//printf("%d\n", sizeof(a));//48,整个数组的大小
//printf("%d\n", sizeof(a[0][0]));//4，第一行第一个元素的大小
//printf("%d\n", sizeof(a[0]));//16，第一个元素，是一个数组int[4]的大小
//printf("%d\n", sizeof(a[0]+1));//4/8，第一行第二个元素的地址的大小，a[0]作为数组名，没有单独放在sizeof内部，没有取地址，表示首元素的地址，+1就是第二个元素的地址
//printf("%d\n", sizeof(*(a[0]+1)));//4，第一行第二个元素的大小
//printf("%d\n", sizeof(a+1));//4/8,第一行的地址+1，第二行的地址
//printf("%d\n", sizeof(*(a+1)));//16，第二行的地址解引用，第二行的数组名表示整个数组，*(a+1)==a[1]
//printf("%d\n", sizeof(&a[0]+1));//4/8，第二行的地址的大小
//printf("%d\n", sizeof(*(&a[0]+1)));//16，第二行的地址解引用，表示第二行，==a[1]
//printf("%d\n", sizeof(*a));//16,首元素的地址解引用，表示第一行
//printf("%d\n", sizeof(a[3]));//16，a[3]的类型是int[4]，sizeof只看类型
int a[3][4];
printf("%d", &a[0][1] - &a[0][3]);
return 0^0;
}