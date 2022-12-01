//reverse a string word by word

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int main() {
//    char str[100];
//    cin.getline(str, 100);
//    int r = strlen(str)-1;
//    int l,m=r;
//    while (m > 0) {
//        m--;
//        if (str[m] == ' ') {
//            for (l = m+1; l <= r; l++) {
//                printf("%c", str[l]);
//            }
//            r = m - 1;
//            printf(" ");
//        }
//    }
//    for (l = m; l <= r; l++) {
//        printf("%c", str[l]);
//    }
//    return 0;
//}


//learning of vector
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//bool cmp(int x, int y) {
//	return (x > y);
//}
//int main() {
//	//initialize vector
//	vector<int>v1;
//	vector<int>v2(4);
//	vector<int>v3(4, 2);
//	vector<string>v4(4, "hello");
//	vector<string>v5(v4);
//	//basic algorithm
//	sort(v1.begin(), v1.end());
//	sort(v1.begin(), v1.end(), cmp);
//	v1.insert(v1.begin(), 1);
//	v1.assign(v2.begin(), v2.end());
//	v1.erase(v1.begin() + 1);
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++);
//	for (vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++);
//	v1.reserve(10);
//	v1.resize(20);
//
//	return  0;
//}

//leetcode 53. Maximum Subarray
//https://leetcode.com/problems/maximum-subarray/?favorite=2cktkvj


//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
// 
//int maxSubArray(vector<int>& nums) {
//    int len = nums.size();
//    int* dp = new int[len];
//    dp[0] = nums[0];
//    for (int i = 1; i < len; i++) {
//        if (dp[i - 1] < 0) {
//            dp[i] = nums[i];
//        }
//        else {
//            dp[i] = dp[i - 1] + nums[i];
//        }
//    }
//    int ret = -INT_MAX;
//    for (int i = 0; i < len; i++) {
//        ret = max(ret, dp[i]);
//    }
//    return ret;
//}
//int main() {
//	
//    vector<int>nums = { -2,1,-3,4,-1,2,1,-5,4 };
//    cout<<maxSubArray(nums)<<endl;
//	return 0;
//}

//leetcode 56. Merge Intervals
//https://leetcode.com/problems/merge-intervals/description/

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//vector<vector<int>> merge(vector<vector<int>>& intervals) {
//    sort(intervals.begin(), intervals.end());
//    int i = 1;
//    for (i = 1; i < intervals.size(); i++) {
//        if (intervals[i][0] <= intervals[i - 1][1]) {
//            intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
//            intervals[i - 1][1] = -1;
//            intervals[i][0] = -1;
//        }
//    }
//    vector<vector<int>>ret;
//    int cnt = 0; int pre = 0, next = 0;
//    for (i = 0; i < intervals.size(); i++) {
//        for (int j = 0; j < 2; j++) {
//            if (intervals[i][j] != -1 && cnt == 0) {
//                pre = intervals[i][j];
//                cnt++;
//            }
//            else if (intervals[i][j] != -1 && cnt == 1) {
//                next = intervals[i][j];
//                cnt++;
//            }
//            else continue;
//            if (cnt == 2) {
//                cnt = 0;
//                ret.push_back({ pre,next });
//            }
//        }
//    }
//    return ret;
//}
//int main() {
//	vector<vector<int>> num = { {1,3 }, {2, 6},{8, 10},{15, 18} };
//	merge(num);
//	for (vector<vector<int>>::iterator it = num.begin(); it != num.end(); it++) {
//		for (vector<int>::iterator p = ( * it).begin(); p != (*it).end(); p++) {
//			cout << *p << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}



//#include <iostream>
//using namespace std;
//
//int fact(int n) {
//    int i = 1, ret = 1;
//    if (n == 0)return 1;
//    while (i <= n) {
//        ret *= i;
//        i++;
//    }
//    return ret;
//}
//int C(int m, int n) {
//    return fact(n) / (fact(m) * fact(n - m));
//}
//int uniquePaths(int m, int n) {
//    if (m == 1 && n == 1)return 1;
//    int less, great;
//    int ret = 0;
//    if (m >= n) {
//        less = n;
//        great = m;
//    }
//    else {
//        less = m;
//        great = n;
//    }
//    for (int j = less - 1; j > 0; j--) {
//        ret += C(j, great);
//    }
//    return ret;
//}
//int main() {
//    cout << uniquePaths(3, 7);
//	return 0;
//}