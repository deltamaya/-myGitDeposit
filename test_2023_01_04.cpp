#include <stdio.h>
//int main() {
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p)printf("xiao");
//	else printf("da");
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main() {
//	
//	 unsigned char b = 255;
// b++; 
//	 printf("%d\n", b);
//	
//		return 0;
//}
//11111111111111111111111110000000
//10000000000000000000000010000000
//10000000 --- -128   char->[-128,127]
//00000000 --- 0
//#include <string.h>
//int my_strlen(const char* str) {
//	
//	int i = 0;
//	while (*str++ != '\0')i++;
//	return i;
//}
//int main() {
//
//	char arr[] = "hello";
//	printf("%d %d", sizeof(arr) / sizeof(arr[0]), my_strlen(arr));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//void print(const int (*p)[2]/*const int p[2]*/, int row, int col) {
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//}
//void test(int(*p)[3]) {
//	printf("%d", (*(p + 1))[1]);
//}
//void r(int **p){}
//int main() {
//	
//	//int arr1[3] = { 1,2,3 };
//	//int arr2[3] = { 4,6,7 };
//	//int* arr[2]={arr1,arr2};
//	//int i, j;
//	//for (i = 0; i < 2; i++) {
//	//	for (j = 0; j < 3; j++) {
//	//		printf("%d ", *(*(arr + i) + j));
//	//	}
//	//	printf("\n");
//	//}
//	//int arr1[2][2] = {{1,2},{3,4}};
//	//int arr2[3] = { 4,5,6 };
//	//int(*p)[2] = &arr1[0];
//	//print(arr1, 2, 2);
//	//int(*parr)[3] = &arr1;
//	//printf("%p\n", arr1);
//	//printf("%p ", parr+1);
//	//char str[5];
//	//char(*ps)[5] = &str;
//	int arr[2][3] = { 0 };
//	test(arr);
//	int** t = (int**)malloc(sizeof(int*));
//	t[0] = (int*)malloc(sizeof(int) * 3);
//	r(t);
//	auto pr = &r;
//	pr(t);
//	return 0;
//}



void(*signal(int, void(*)(int)))(int);
//signal传入int和函数指针(接受int返回void)，返回函数指针(接受int返回void)
//(void(*)(int)) signal(int, void(*)(int));
//助于理解
typedef  void(*ty_p)(int);
//typedef声明指针时名字要放到*旁边
ty_p signal(int, ty_p);
//简化后如上
int main() {
	( *(( void(*)() )0) ) ();

	
	return 0;
}