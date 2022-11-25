#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
int main() {
	cout << -8 / 3 << '  ' << -8 % 3 << endl;
	cout << -8 / 3 << endl << -8 % 3 << endl;
	printf("%d %d\n", -8 / 3,-8%3);
	printf("%d\n", -8 % 3);
	return 0;

}


/// ///////////////////create a file contains prime number from 0 to 500
bool prime(int n) {
	int i = 0;
	if (n == 1)return false;
	if (n == 2)return true;
	else {
		for (i = 2; i <= sqrt(n); i++) {
			if (n % i == 0)return false;
		}
		return true;
	}
}
int main() {
	FILE* pf;
	if ((pf = fopen("prime.txt", "w")) == NULL) {
		printf("File open error!\n");
		exit(0);
	}
	int i = 2;
	for (i = 2; i < 500; i++) {
		if (prime(i)) {
			fprintf(pf, "%d ", i);
		}
	}
	if (fclose(pf)) {
		printf("File close error!\n");
		exit(0);
	}
	return 0;
}


////print all elements of the former file "prime.txt" 
int main() {
	FILE* pf;
	if ((pf = fopen("prime.txt", "r")) == NULL) {
		printf("File open error!\n");
		exit(0);
	}
	//"fopen"returns a pointer to the file to be opened on success,otherwise returns NULL
	//"r"for read only,"w"for create and write,"a"for append
	int integer = 0;
	while ((fscanf(pf, "%d",&integer)) != EOF) {
		//"fscanf"returns the number of items of the argument list filled successfully,if "feof" or"ferror"indicator is seted,return EOF
		//"feof"returns a non-zero value  in the case that the end-of-file indicator associated with the stream is set,otherwise returns 0
		printf("%d ", integer);
	}
	if (fclose) {
		printf("File close error!\n");
		exit(0);
	}
	//"fclose"returns a zero value if the file is closed successfully,otherwise returns EOF
	return 0;
}



//leetcode 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?favorite=2cktkvj
class Solution {
public:
    vector<string>ret;

    void dfs(string path, int len, int i, string digits) {
        if (i == len) {
            ret.push_back(path);
            return;
        }
        if (digits[i] == '2') {
            dfs(path + 'a', len, i + 1, digits);
            dfs(path + 'b', len, i + 1, digits);
            dfs(path + 'c', len, i + 1, digits);
        }
        else if (digits[i] == '3') {
            dfs(path + 'd', len, i + 1, digits);
            dfs(path + 'e', len, i + 1, digits);
            dfs(path + 'f', len, i + 1, digits);
        }
        else if (digits[i] == '4') {
            dfs(path + 'g', len, i + 1, digits);
            dfs(path + 'h', len, i + 1, digits);
            dfs(path + 'i', len, i + 1, digits);
        }
        else if (digits[i] == '5') {
            dfs(path + 'j', len, i + 1, digits);
            dfs(path + 'k', len, i + 1, digits);
            dfs(path + 'l', len, i + 1, digits);
        }
        else if (digits[i] == '6') {
            dfs(path + 'm', len, i + 1, digits);
            dfs(path + 'n', len, i + 1, digits);
            dfs(path + 'o', len, i + 1, digits);
        }
        else if (digits[i] == '7') {
            dfs(path + 'p', len, i + 1, digits);
            dfs(path + 'q', len, i + 1, digits);
            dfs(path + 'r', len, i + 1, digits);
            dfs(path + 's', len, i + 1, digits);
        }
        else if (digits[i] == '8') {
            dfs(path + 't', len, i + 1, digits);
            dfs(path + 'u', len, i + 1, digits);
            dfs(path + 'v', len, i + 1, digits);
        }
        else if (digits[i] == '9') {
            dfs(path + 'w', len, i + 1, digits);
            dfs(path + 'x', len, i + 1, digits);
            dfs(path + 'y', len, i + 1, digits);
            dfs(path + 'z', len, i + 1, digits);
        }

    }
    vector<string> letterCombinations(string digits) {


        int len = digits.size();
        if (len == 0)return {};
        dfs("", len, 0, digits);
        return ret;
    }
};


//luogu Q.1328
//https://www.luogu.com.cn/problem/P1328
#include <iostream>
using namespace std;
int main() {
	int n, a, b;
	while (cin >> n>>a>>b) {
		int A[200] = { 0 };
		int B[200] = { 0 };
		int i, j;
		for (i = 0; i < a; i++) {
			cin >> A[i];
		}
		for (i = a; i < 200; i++) {
			A[i] = A[i - a];
		}
		for (j = 0; j < b; j++) {
			cin >> B[j];
		}
		for (j = b; j < 200; j++) {
			B[j] = B[j - b];
		}
		int a_win = 0; int b_win = 0;
		int balance = 0;
		for (i = 0; i < n; i++) {
			if (A[i] == B[i])balance++;
			else if ((A[i] == 0 && B[i] == 2) || (A[i] == 0 && B[i] == 3))a_win++;
			else if ((A[i] == 1 && B[i] == 0) || (A[i] == 1 && B[i] == 3))a_win++;
			else if ((A[i] == 2 && B[i] == 4) || (A[i] == 2 && B[i] == 1))a_win++;
			else if (A[i] == 3 && B[i] == 4 || (A[i] == 3 && B[i] == 2))a_win++;
			else if (A[i] == 4 && B[i] == 0 || (A[i] == 4 && B[i] == 1))a_win++;
		}
		b_win = n - balance - a_win;
		cout << a_win << ' ' << b_win << endl;

	}
	return 0;
}



//luogu Q.1563
//https://www.luogu.com.cn/problem/P1563

#include <map>
#include <iostream>
using namespace std;
string people[100000][2];
int main() {
	int n, m;
	while (cin >> n >> m) {	
		int i, j;
		for (i = 0; i < n; i++) {
			cin >> people[i][0] >> people[i][1];
		}
		int target = 0;
		int move[2];
		for (i = 0; i < m; i++) {
			cin >> move[0] >> move[1];
			if (move[0] == 0 && people[target][0] == "0") {
				target -= move[1];
				while (target < 0)target += n;
			}
			else if (move[0] == 1 && people[target][0] == "0") {
				target += move[1];
				while (target >= n)target -= n;
			}
			else if (move[0] == 0 && people[target][0] == "1") {
				target += move[1];
				while (target >= n)target -= n;
			}
			else if (move[0] == 1 && people[target][0] == "1") {
				target -= move[1];
				while (target < 0)target += n;
			}
		}
		cout << people[target][1]<<endl;
	}
	return 0;
}

///luogu Q.2678
//https://www.luogu.com.cn/problem/P2678
//  crude force solution(Time Limit Exceeded)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>rock;
vector<int>delta;
int main() {
	int distance, n, remove;
	
	while (cin >> distance >> n >> remove) {
		rock.clear();
		rock.push_back(0);
		int i, j;
		for (i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			rock.push_back(tmp);
		}
		rock.push_back(distance);
		int min=distance;
		int cnt = 0;
		do {
			delta.clear();
			for (i = 1; i <= n+1-cnt; i++) {
				delta.push_back(rock[i] - rock[i - 1]);
			}
			min=INT_MAX;
			for (i = 0; i < n + 1-cnt; i++) {
				if (min > delta[i]) {
					min = delta[i];
					j = i;
				}
			}
			rock.erase(rock.begin() + j+1, rock.begin() + j+2 );
			cnt++;

		} while (remove--);
		cout << min << endl;
	}

	return 0;

}


///binary search solution(Accepted)
#include <iostream>
#include <string.h>
using namespace std;
int rock[50002];
int m,n,d;
bool judge(int x) {
	int sum = 0;
	int i = 0;
	int cur = 0;
	while (i < n + 1) {
		i++;
		if (rock[i] - rock[cur] >= x) {
			cur = i;
		}
		else {
			sum++;
		}

	}
	if (sum <= m)return true;
	else return false;
}
int main() {
	while (cin >> d >> n >> m) {
		memset(rock, 0, sizeof(rock));
		int i, j;
		int ans=0;
		for (i = 1; i <= n; i++) {
			cin >> rock[i];
		}
		rock[i] = d;
		int L = 0, R = d;
		while (L <= R) {
			int mid = (L + R) / 2;
			if (judge(mid)) {
				L = mid + 1;
				ans = mid;
			}
			else {
				R = mid - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}