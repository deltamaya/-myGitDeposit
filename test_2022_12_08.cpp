//#include <stdio.h>
//
///* 排序函数，将数组 a 中的元素从小到大排序 */
//void bubble_sort(int a[], int n) {
//    int i, j, temp;
//    for (i = 0; i < n - 1; i++) {
//        for (j = 0; j < n - i - 1; j++) {
//            if (a[j] > a[j + 1]) {
//                /* 交换 a[j] 和 a[j + 1] 的值 */
//                temp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = temp;
//            }
//        }
//    }
//}
//
///* 打印数组元素 */
//void print_array(int a[], int n) {
//    int i;
//    for (i = 0; i < n; i++) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//}
//
//int main() {
//    /* 要排序的数组 */
//    int array[] = { 6, 3, 8, 5, 1 };
//
//    /* 数组的长度 */
//    int n = sizeof(array) / sizeof(array[0]);
//
//    printf("Original array: ");
//    print_array(array, n);
//
//    bubble_sort(array, n);
//
//    printf("Sorted array: ");
//    print_array(array, n);
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//bool squareIsWhite(string coordinates) {
//	if (coordinates[0] % 2 == 1) {
//		if (coordinates[1] % 2 == 1)return false;
//		else return true;
//	}
//	else {
//		if (coordinates[1] % 2 == 1)return true;
//		else return false;
//	}
//}
//int main() {
//	printf("%d", 'a');
//}

//#include <iostream>
//#include <vector>
//using namespace std;    
// vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//    vector<vector<int>>ret;
//    int begin = -1, end = -1, i, len = intervals.size() - 1;;
//    if (len == -1) {
//        ret.push_back(newInterval);
//        return ret;
//    }
//    if (newInterval[1] <= intervals[0][0]) {
//        if (newInterval[1] == intervals[0][0]) {
//            ret.push_back({ newInterval[0],intervals[0][1] });
//            for (int i = 1; i <= len; i++)ret.push_back(intervals[i]);
//        }
//        else {
//            ret.push_back(newInterval);
//            for (vector it : intervals)ret.push_back(it);
//        }
//        return ret;
//    }
//    if (newInterval[0] >= intervals[len][1]) {
//        if (newInterval[0] == intervals[len][1]) {
//
//            for (int i = 0; i < len; i++)ret.push_back(intervals[i]);
//            ret.push_back({ intervals[len][0],newInterval[1] });
//        }
//        else {
//            for (vector it : intervals)ret.push_back(it);
//            ret.push_back(newInterval);
//
//        }
//        return ret;
//    }
//    for (i = 0; i < intervals.size(); i++) {
//        if (intervals[i][1] >= newInterval[0] && begin == -1) {
//            if (intervals[i][1] == newInterval[0])begin = intervals[i][1];
//            else begin = min(intervals[i][0], newInterval[0]);
//
//        }
//        else if (intervals[i][0] >= newInterval[1] && end == -1) {
//            if (intervals[i][0] == newInterval[1]) {
//                end = intervals[i][1];
//            }
//            else {
//                end = max(newInterval[1], intervals[i - 1][1]); i--;
//            }
//            ret.push_back({ begin,end });
//        }
//        else if ((begin != -1 && end != -1) || (begin == -1 && end == -1)) {
//            ret.push_back(intervals[i]);
//        }
//    }
//    return ret;
//}
//int main() {
//    ;
//	return  0;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//
//int main() {
//    char S[500001], T[500001];
//    scanf("%s", S);
//    scanf("%s", T);
//
//    // 计算S和T的长度
//    int lenS = strlen(S);
//    int lenT = strlen(T);
//    int i;
//    for (i = 0; i < lenT; i++) {
//        if (S[i] != T[i]) {
//            printf("%d\n", i+1);
//            break;
//        }
//    }
//    return 0;
//}
#include <algorithm>
#include <iostream>
using namespace std;
signed main() {
	long long k;
	cin >> k;
	for (long long i = 1; i <= 2000010; i++) {
		k /= __gcd(k, i);
		if (k == 1) {
			cout << i << endl;
			return 0;
		}
	}
	cout << k << endl;
	return 0;
}
