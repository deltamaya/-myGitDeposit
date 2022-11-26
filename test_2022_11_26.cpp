#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<assert.h>
using namespace std;


//simulate function "strlen"
int my_strlen(const char* str) {
	//"const" means the value pointed by pointer"str" can not be changed 
	assert(str);
	//"assert(eqs)"will shut down the funtion if the [eqs]'s value is false
 //"assert" will be ignored when you compile in "Release" mod
	int cnt = 0;
	while (*str++)cnt++;
	//"++" has higher priority to "*"
	return cnt;
}
int main() {
	char a[] = "hello";
	cout << my_strlen(a);
	return 0;
}

using namespace std;
void Test(void);
int main() {
	//test();
	//when you spell something  uncorrectly , you can use "ctrl+F" to call out  "find" function and find  it quickly
	return 0;
}

//HDU Problem-2037
//http://acm.hdu.edu.cn/showproblem.php?pid=2037
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct show {
    int start;
    int end;
};
bool cmp(show s1, show s2) {
    return (s1.end < s2.end);
}
int main() {
    int n, i = 0;
    vector<show>s;
    while (cin >> n && n) {
        int st, e;
        s.clear();
        for (i = 0; i < n; i++) {
            cin >> st >> e;
            s.push_back({ st,e });
        }
        sort(s.begin(), s.end(), cmp);
        int lastend = -1; int cnt = 0;
        for (i = 0; i < n; i++) {
            if (s[i].start >= lastend) {
                cnt++;
                lastend = s[i].end;
            }
        }
        cout << cnt << endl;

    }
    return 0;
}



//HDU Problem-2899
//http://acm.hdu.edu.cn/showproblem.php?pid=2899
#include <iostream>
using namespace std;
long long y;
double func(double x) {
    return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * pow(x, 2) - y * x;
}

int main() {
    int n;
    while (cin >> n) {
        while (n--) {
            cin >> y;
            double delta = 0.98;
            double T = 100;
            double preci = 1e-8;
            double x = 50.0;
            int f[2] = { -1,1 };
            double now = func(x);
            double ans = now;
            while (T > preci) {
                double newx = x + f[rand() % 2] * T;
                if (newx >= 0 && newx <= 100) {
                    ans = min(now, func(newx));
                    if (now - func(newx) > preci) {
                        x = newx; now = func(newx);
                    }

                }

                T *= delta;
            }
            printf("%.4lf\n", ans);
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long f(long long x) {
    if (x > 0) return x;
    else return 0;
}

int main() {
    int n, m;
    long long* a, x, y, sum = 0;
    cin >> n;
    a = new long long[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]), sum += a[i];
    sort(a, a + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &x, &y);
        int r = lower_bound(a + 1, a + n, x) - a, l = r - 1;
        cout << min(f(x - a[l]) + f(y - sum + a[l]), f(x - a[r]) + f(y - sum + a[r])) << endl;
    }

}



#include <iostream>
using namespace std;
int main() {
	
	int n, m;
	while (cin >> n) {
		while (n--) {
			cin >> m;
			int i, j = 0;
			int* a = new int[m];
			for (i = 0; i < m; i++) {
				cin >> a[i];
			}int f = 1, yes = 1;
			for (i = 0; i < m - 1; i++) {
				int d = a[i + 1] - a[i];
				if (d < 0) {
					f = 0;
				}
				else if (!f && d > 0) {
					yes = 0;
				}
			}
			if (yes)printf("YES\n");
			else printf("NO\n");
		}
	}


	return 0;
}
