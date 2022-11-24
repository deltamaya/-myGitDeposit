#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/////////////move odd integer to the front of the array
//int main() {
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int len = sizeof(a) / sizeof(a[0]);
//	int k = 0; 
//	int b[10];
//	for (i = 0; i < len; i++) {
//		if (a[i] % 2 == 1) {
//			b[k++] = a[i];
//		}
//	}
//	for (i = 0; i < len; i++) {
//		if (a[i] % 2 == 0) {
//			b[k++] = a[i];
//		}
//	}
//	for (i = 0; i < len; i++)cout << b[i]<<' ';
//	return 0;
//}

////////////////////////merge two sorted array
//#include <stdio.h>
//
//int main() {
//    int a[1000] = { 0 }, b[1000] = { 0 };
//    int n, m;
//    while (~scanf("%d%d", &n, &m)) {
//        int i;
//        for (i = 0; i < n; i++)scanf("%d", &a[i]);
//        for (i = 0; i < m; i++)scanf("%d", &b[i]);
//        int pa = 0, pb = 0;
//        int sum[2000] = { 0 };
//        for (i = 0; i < n + m; i++) {
//            if (a[pa] <= b[pb]) {
//                sum[i] = a[pa++];
//                if (pa == n)break;
//            }
//            else {
//                sum[i] = b[pb++];
//                if (pb == m)break;
//            }
//        }
//        i++;
//        if (pa == n) {
//            while (pb < m)sum[i++] = b[pb++];
//        }
//        else if (pb == m) {
//            while (pa < n)sum[i++] = a[pa++];
//        }
//        for (i = 0; i < n + m; i++)printf("%d ", sum[i]);
//    }
//    return 0;
//}


/////////////////////////check a array is sorted or not
#include <stdio.h>

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int i = 0;
        int a[50];
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int delta = 0;
        i = 0;
        while (delta == 0 && i < n - 1) {
            delta = a[i + 1] - a[i];
            i++;
        }
        int f = 1;

        if (delta < 0) {
            for (; i < n - 1; i++) {
                if (a[i + 1] - a[i] > 0) {
                    f = 0;
                    break;
                }
            }
        }
        else if (delta > 0) {
            for (; i < n - 1; i++) {
                if (a[i + 1] < a[i]) {
                    f = 0;
                    break;
                }
            }
        }
        else {
            printf("sorted\n");
            continue;
        }
        if (f == 0)printf("unsorted\n");
        else printf("sorted\n");
    }
    return 0;
}