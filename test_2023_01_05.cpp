#include <stdio.h>
//int add(int x, int y) { return x + y; }
//int sub(int x, int y) { return x - y; }
//int main() {
//	int(*pf[2])(int, int) = { add,sub };
//	//pf是函数指针数组
//	int (*(*a)[2])(int, int) = &pf;
//	//a是指向函数指针数组的指针
//	return 0;
//}

//#define swap(x,y){int tmp=x;x=y;y=tmp;}
void int_bbsort(int* arr, int size) {
	int i, j;
	for (i = 0; i < size-1; i++) {
		for (j = 0; j < size -1- i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			};
		}
	}
}
//int add(int x, int y) { return x + y; }
//int sub(int x, int y) { return x - y; }
//int cal(int x, int y, int(*p)(int, int)) {
//	return p(x, y);
//}
//int main() {
//	bool a = false;
//	int (*pa)(int, int) = add;
//	int (*pb)(int, int) = sub;
//	cal(1, 2, pa);
//	return 0;
//}

void swap(char* x, char* y, int w) {
	int i;
	for (i = 0; i < w; i++) {
		char tmp = x[i];
		x[i] =y[i];
		y[i] = tmp;
	}
}
int cmp_double(const void* x, const void* y,int size) {
	if (*(double*)x - *(double*)y > 0) {
		return 1;
	}
	else return 0;
}
void bbsort(void* base, int n, int width, int (*cmp)(const void* x, const void* y,int size)) {
	int i, j;
	base = (char*)base;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < width*(n - i - 1); j+=(width)) {
			if (cmp((char*)base+j, (char*)base+j+width, width) > 0)swap((char*)base + j, (char*)base + j + width,width);
		}
	}
}
int main() {
	double arr[5] = { 1.0,0.5,0,7,9.9 };
	bbsort(arr, 5, sizeof(double), cmp_double);
	for (int i = 0; i < 5; i++) {
		printf("%.1lf ", arr[i]);
	}
	return 0;
}