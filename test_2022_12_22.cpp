#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int countSubstrings(string s) {
    int ret = 0;
    int i = 0;
    for (i = 0; i < s.size(); i++) {

        int l = i, r = i;
        while (l >= 0 && r < s.size()&& s[l] == s[r]) {
            ret++;
            l--; r++;
        }
        l = i - 1; r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            ret++;
            l--; r++;
        }
    }
    return ret;
}
bool cmp(int x, int y) {
    return (x > y);
}
int leastInterval(vector<char>& tasks, int n) {
    vector<int>num(27, 0);
    int i, j;
    for (i = 0; i < tasks.size(); i++) {
        num[tasks[i] - 'A']++;
    }
    sort(num.begin(), num.end(),cmp);
    int chart[100000] = { 0 };
    j = i = 0;
    int ret = 0;
    for (i = 0; i < num.size(); i++) {
        if (num[i] == 0)break;
        while (chart[j] != 0)j++;
        while (num[i]--) {
            chart[j] ++;
            j += (n+1);
        }j -= (n + 1);
        ret = max(ret, j);
        j = 0;
    }
    return ret+1;
}
int main() {
    vector<char>tasks = { 'A','A','A','B','B','B' };
    cout << leastInterval(tasks, 2);
	return 0;
}