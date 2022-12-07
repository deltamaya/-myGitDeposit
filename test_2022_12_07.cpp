#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//    /*int findDuplicate(vector<int>& nums){
//        for (int num : nums) {
//            num = abs(num);
//            if (nums[num] < 0) 
//                return num;
//            nums[num] *= -1;
//        }
//        return -1; 
//    }*/
//int findDuplicate(vector<int>& nums) {
//    bool hash[100001];
//    for (int i : nums) {
//        if (hash[nums[i]]) {
//            return nums[i];
//        }
//        else {
//            hash[nums[i]] = true;
//        }
//    }
//    return -1;
//}
//    int main() {
//        vector<int>nums = { 1,2,3,4,2 };
//        cout << findDuplicate(nums) << endl;
//        return 0;
//    }


//#include <algorithm>
//#include <vector>
//#include <iostream>
//using namespace std;
//    int numSquares(int n) {
//        vector<int> f(n + 1);
//        for (int i = 1; i <= n; i++) {
//            int minn = INT_MAX;
//            for (int j = 1; j * j <= i; j++) {
//                minn = min(minn, f[i - j * j]);
//            }
//            f[i] = minn + 1;
//        }
//        return f[n];
//    }
//int main() {
//    cout << numSquares(123)<<endl;
//	return 0;
//}


//#include <algorithm>
//#include <iostream>
//#include <vector>
//using namespace std;
//void bfs(vector<vector<char>>& grid, int i, int j, int row, int col) {
//    if (grid[i][j] == '1') {
//        grid[i][j] = '2';
//        if (i + 1 < row && grid[i + 1][j] == '1')bfs(grid, i + 1, j, row, col);
//        if (i - 1 >= 0 && grid[i - 1][j] == '1')bfs(grid, i - 1, j, row, col);
//        if (j + 1 < col && grid[i][j + 1] == '1')bfs(grid, i, j + 1, row, col);
//        if (j - 1 >= 0 && grid[i][j - 1] == '1')bfs(grid, i, j - 1, row, col);
//    }
//}
//int numIslands(vector<vector<char>>& grid) {
//    int cnt = 0;
//    int i, j;
//    for (i = 0; i < grid.size(); i++) {
//        for (j = 0; j < grid[0].size(); j++) {
//            if (grid[i][j] == '1') {
//                bfs(grid, i, j, grid.size(), grid[0].size());
//                cnt++;
//            }
//        }
//    }
//    return cnt;
//}
//int main() {
//    vector<vector<char>>grid = { {'1','1','1'},{'0','0','0'},{'1','0','1'}};
//    cout << numIslands(grid)<<endl;
//
//	return 0;
//}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <ctime>
//using namespace std;
//int dat[] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
//void Perm(int begin, int end) {
//	if (begin == end)return;
//	for (int i = begin; i <= end; i++) {
//		swap(dat[i], dat[begin]);
//		Perm(begin + 1, end);
//		swap(dat[i], dat[begin]);
//	}
//}
//int main() {
//	time_t start = clock();
//	Perm(0, 10);
//	cout << (double)(clock() - start)/CLOCKS_PER_SEC <<'s'<< endl;
//	return 0;
//}

