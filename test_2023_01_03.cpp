#include <stdio.h>
#include <math.h>
//int j = 0; *returnSize = pow(10, n) - 1;
//int* num = (int*)malloc(sizeof(int) * *returnSize);
//for (int i = 1; i < pow(10, n); i++) {
//	num[j] = i;
//	j++;
//}
//return num;
//int main() {
//	int num = 0;
//	scanf("%d", &num);
//	for (int i = 0; i < pow(10,num); i++) {
//		printf("%d ", i);
//	}
//	return 0;
//}
#include <string.h>
#include<stdio.h>
//int main()
//{
//	char s[] = "\\123456\123456\t";
//	printf("%d\n", strlen(s));
//	return 0;
//}
#include <stdio.h>
struct A {
	int x;
	char c;
	int y;
};
//#include <stdio.h>
//#include <math.h>
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int tmp = n * n;
//    int i = 0, j = 0;
//    i = tmp - n + 1;
//    int f = 1;
//    for (i = i; i <= tmp + n - 1; i += 2) {
//        if (f == 1) {
//            printf("%d", i);
//            f = 0;
//        }
//        else {
//            printf("+%d", i);
//        }
//    }printf("\n");
//
//    return 0;
//}
//int main() {
//    int i = 2;
//    int sum = 0;
//    int n = 0;
//    scanf("%d", &n);
//    for (n = n; n > 0; n--) {
//        sum += i;
//        i += 3;
//    }
//    printf("%d\n", sum);
//    return 0;
//}
//int main()
//{
//	int a = 248, b = 4;
//	int const* c = 21;
//	const int* d = &a;
//	int* const e = &b;
//	int const* const f = &a;
//
//	return 0;
//}
#include <stdlib.h>
int i;
void prt()
{
	for (i = 5; i < 8; i++)
		printf("%c", '*');
	printf("\t");
}
//int main()
//{
//    int m, n;
//    printf("Enter m,n;");
//    scanf("%d%d", &m, &n);
//    while (m != n) //1
//    {
//        while (m > n) m = m - n; //2
//        while (n > m) n = n - m; //3
//    }
//    printf("m=%d\n", m);
//    return 0;
// printf("%d", n);
//}
// #include <stdio.h>
//int main()
//{
//    int cnt = 0;
//    int n;
//    scanf("%d", &n);
//    for (int i = 0; i <= n-1; i++) {
//        for (int j = n; j > i; j--)cnt++;
//    }
//    printf("%d", cnt);
//        return 0;
//}
// 
//#include <stdio.h>
//#include <string.h>
//int main() {
//    int n;
//    scanf("%d", &n);
//    int i, j;
//    char pwd[101];
//    for (i = 0; i < n; i++) {
//        int ok = 1;
//        scanf("%s", pwd);
//        if (pwd[0] >= '0' && pwd[0] <= '9')ok = 0;
//        if (strlen(pwd) < 8)ok = 0;
//        j = 0;
//        int G = 0, g = 0, d = 0;
//        while (G + g + d < 2 && j < strlen(pwd)) {
//            if (pwd[j] >= '0' && pwd[j] <= '9')d = 1;
//            if (pwd[j] >= 'a' && pwd[j] <= 'z')g = 1;
//            if (pwd[j] >= 'A' && pwd[j] <= 'Z')G = 1;
//            j++;
//        }
//        if (G + d + g < 2)ok = 0;
//        if (ok == 1)printf("YES\n");
//        else printf("NO\n");
//        memset(pwd, '\0', sizeof(pwd));
//
//    }
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int cnt = 0; double sum = 0;
//    int i = 0; int num = 0;
//    for (i = 0; i < n; i++) {
//        int tmp;
//        scanf("%d", &tmp);
//        if (tmp < 0) {
//            cnt++;
//        }
//        else if (tmp > 0) {
//            sum += tmp; num++;
//        }
//        else {
//            continue;
//        }
//    }
//    if (sum > 0)
//        printf("%d %.1lf\n", cnt, sum / num);
//    else
//        printf("%d 0.0\n", cnt);
//    return 0;
//}
int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
    int l = 0, r = rotateArrayLen - 1;
    int m;
    while (l <= r) {
        m = (l + r) / 2;
        if (rotateArray[m] > rotateArray[r]) {
            l = m + 1;
        }
        else if (rotateArray[m] < rotateArray[r]) {
            r = m;
        }
        else {
            r--;
        }
    }
    return rotateArray[m];
}
int GetNumberOfK(int* data, int dataLen, int k) {
    int l = 0, r = dataLen - 1;
    int f = 0;
    int m;

    while (l <= r) {
        m = (l + r) / 2;
        if (data[m] > k) {
            r = m - 1;
        }
        else if (data[m] < k) {
            l = m + 1;
        }
        else {
            f = 1;
            break;
        }
    }
    if (!f)return 0;
    else {
        int cnt = 1;
        l = m - 1; r = m + 1;
        while (l >= 0 && data[m] == data[l]) {
            l--; cnt++;
        }
        while (r < dataLen && data[m] == data[r]) {
            r++; cnt++;
        }
        return cnt;
    }

}
int convertInteger(int A, int B) {
    unsigned int dif = A ^ B;
    int ret = 0;
    while (dif) {
        ret++;
        dif &= (dif - 1);
    }
    return ret;
}
int main() {
    printf("%d", convertInteger(1,2));
    return 0;
}