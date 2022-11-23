#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
void my_swap(int* a, int* b, int* c, int* d) {
    int tmp1 = *a;
    int tmp2 = *b;
    int tmp3 = *c;
    int tmp4 = *d;
    *a = tmp3;
    *b = tmp1;
    *c = tmp4;
    *d = tmp2;
}
int main() {
    vector<vector<int>>matrix = { {1,2,3},{4,5,6},{7,8,9} };

    
    
    int n = matrix.size() - 1;
    int x1 = 0, x2 = 0, x3 = n, x4 = n, y1 = 0, y2 = n, y3 = 0, y4 = n;
    int i = 0;
    for (i = 1; i < (n + 1) / 2 + 1; i++) {
        int j = 0;
        for (j = 0; j < n - 2 * (i - 1); j++) {
            my_swap(&matrix[x1][y1], &matrix[x2][y2], &matrix[x3][y3], &matrix[x4][y4]);
            y1++; x2++; x3--; y4--;

        }
        x1 = i; y1 = i;
        x2 = i; y2 = n - i;
        x3 = n - i; y3 = i;
        x4 = n - i; y4 = n - i;

    }
	return 0;
}