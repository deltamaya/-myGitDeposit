#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	int n;
	while (~scanf("%d", &n)) {
		int f = 1;
		while (n > 0) {
			while (n % 10 == 0 && f == 1) {
				n /= 10;
			}f = 0;
			printf("%d", n % 10);
			n /= 10;
		}
	}
	return 0;
}
#include <stdio.h>
#include <math.h>
int main() {
	long long money, year;
	double rate;
	scanf("%lld %lld %lf", &money, &year, &rate);
	if (!money || !year || !rate)return 0;
	printf("interest = %.2lf\n", money * pow(1 + rate, year) - money);

	return 0;
}
#include <stdio.h>
#include <math.h>

int fib(int n) {
    if (n <= 2)return 1;
    int ret[1001] = { 0,1,1 };
    int i;
    for (i = 3; i < 1000; i++) {
        ret[i] = ret[i - 1] + ret[i - 2];
    }
    return ret[n];
}
void CharPyramid(int n, char ch) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (j = 0; j < i; j++) {
            printf("%c ", ch);
        }
        printf("\n");
    }
}
int CountDigit(int number, int digit) {
    if (number < 0)number = -number;
    if (number == 0) {
        return digit == 0 ? 1 : 0;
    }
    int cnt=0;
    while (number > 0) {
        if (number % 10 == digit)cnt++;
        number /= 10;
    }
    return cnt;
}
void dectobin(int n) {
    if (n == 0) {
        printf("0\n");
        return;
    }
    int tmp = n % 2;
    if (n > 1) {
        dectobin(n >> 1);
    }
    printf("%d", tmp);
}
void ArrayShift(int a[], int n, int m) {
	int move = m % n;
	int i=0, j=n-1;
	int tmp=0;
	while (i < j) {
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		i++; j--;
	}
	i = move; j = n - 1;
	while (i < j) {
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		i++; j--;
	}
	i = 0; j = move - 1;
	while (i < j) {
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		i++; j--;
	}
	
}
int fun(int w) {
	int i=0;
	int tmp = w;
	int a = 0;
	while (tmp) {
		i++;
		a = tmp % 10;
		tmp /= 10;
	}
	w -= a*pow(10, i-1);
	return w;
}
double fun(int n) {
    double sum = 0;
    int i = 1;
    double tmp = 1;
    for (i = 1; i <= n; i++) {
        tmp *= i;
        sum += tmp;

    }
    return sum;
}
void fun(int a[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (a[j] < a[j - 1]) {
                int tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void fun(int a[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            int cmp = a[i];
            int s = i;
            j = i-1;
            while (j >= 0) {
                if (a[j] < cmp)break;
                else {
                    int tmp = a[j];
                    a[j] = a[i];
                    a[i] = tmp;
                    i--;
                }
                j--;
            }
            i = s;
        }
    }
}
 
 
 merge sort
#include <algorithm>
#define swap(x,y) {int tmp=x;x=y;y=tmp;}
#define sq(x) (x*x);
void merge(int a[], int s1,int s2,int f1,int f2,int tmp[]) {
    int b = s1;
    int p = s1;
    while (s1 <= f1 && s2 <= f2) {
        if (a[s1] >= a[s2]) {
            tmp[p++] = a[s2++];
        }
        else {
            tmp[p++] = a[s1++];
        }
    }
    if (s1 > f1) {
        while (s2 <= f2) {
            tmp[p++] = a[s2++];
        }
    }else if(s2>f2) {
        while (s1 <= f1) {
            tmp[p++] = a[s1++];
            }
    }
    for (int i = b; i <= f2; i++) {
        a[i] = tmp[i];
    }
}
void div(int a[], int l,int r,int tmp[]) {
    if (l == r)return;
        int mid = (l + r) / 2;
        div(a, l, mid, tmp);
        div(a, mid+1, r, tmp);
        merge(a, l, mid + 1, mid, r, tmp);
    
}
void fun(int a[],int n) {
    int tmp[1001] = { 0 };
    div(a, 0, n - 1,tmp );
    for (int i = 0; i < n; i++) {
        a[i] = tmp[i];
    }
}

quick sort
void fun(int a[], int n) {
    int p = 0;
    int i = n - 1;
    int r = 1;
    if (n <= 1)return;
    while (p != i) {
        if (r == 1) {
            while (i > p) {
                if (a[i] < a[p]) {
                    swap(a[i], a[p]);
                    r = 0;
                    swap(i, p);
                    break;
                }
                else {
                    i--;
                }
            }
        }
        else {
            while (i < p) {
                if (a[i] > a[p]) {
                    swap(a[i], a[p]);
                    r = 1;
                    swap(i, p);
                    break;
                }
                else {
                    i++;
                }
            }
        }
    }
    
    fun(a, p);
    fun(a+p+1, n-p-1);
}

vector<double> convertTemperature(double celsius) {
    vector<double>ret;
    ret.push_back(273.15 + celsius);
    ret.push_back(celsius * 1.8 + 32);
    return ret;
}

    int main()
    {
        int i, a[10] = { 3,7,5,1,2,8,6,4,10,9 };
        fun(a, 10);
     
        for (i = 0; i < 10; i++)
            printf("%d ", a[i]);
        return 0;
    }

int deleteGreatestValue(vector<vector<int>>& grid) {
    int ret = 0;
    for (int i = 0; i < grid.size(); i++) {
        sort(grid[i].begin(), grid[i].end());
    }int M = 0;
    for (int j = 0; j < grid[0].size(); j++) {
        int row = grid.size();
        M = 0;
        for (int i = 0; i < row; i++) {
            M = max(M, grid[i][j]);
        }
        ret += M;
    }
    return ret;
}



