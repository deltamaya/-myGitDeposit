
//leetcode 62. Unique Paths
//https://leetcode.com/problems/unique-paths/description/

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int uniquePaths(int m, int n) {
//    int block[101][101] = { 0 };
//    block[1][1] = 1;
//    int i, j;
//    for (j = 2; j <= n; j++)block[1][j] = 1;
//    for (i = 2; i <= m; i++)block[i][1] = 1;
//    for (i = 2; i <= m; i++) {
//        for (j = 2; j <= n; j++) {
//            block[i][j] = block[i - 1][j] + block[i][j - 1];
//        }
//    }
//    return block[m][n];
//}
//int main() {
//    cout << uniquePaths(4, 4);
//	return 0;
//}


//64. Minimum Path Sum
//https://leetcode.com/problems/minimum-path-sum/description/

//#include <iostream>
//#include <vector>
//using namespace std;
//int minPathSum(vector<vector<int>>& grid) {
//    int minPath[201][201] = { 0 };
//    minPath[0][0] = grid[0][0];
//    int i, j;
//    int row = grid.size();
//    int col = grid[0].size();
//    for (j = 1; j < col; j++)minPath[0][j] = grid[0][j] + minPath[0][j - 1];
//    for (i = 1; i < row; i++)minPath[i][0] = grid[i][0] + minPath[i - 1][0];
//    for (i = 1; i < row; i++) {
//        for (j = 1; j < col; j++) {
//            minPath[i][j] = min(minPath[i - 1][j], minPath[i][j - 1]) + grid[i][j];
//        }
//    }
//    return minPath[row - 1][col - 1];
//}
//int main() {
//    vector<vector<int>>grid = { {1,3,1 }, { 1,5,1 }, {4, 2, 1} };
//    cout << minPathSum(grid);
//	return 0;
//}


//leetcode  78. Subsets
//https://leetcode.com/problems/subsets/description/
// 
//#include <iostream>
//#include <vector>
//using namespace std;
//void dfs(vector<vector<int>>& ret, vector<int>& path, vector<int>& nums, int len, int length, int aimlen,int begin) {
//    int i = 0;
//    if (aimlen > length)return;
//    if (len >= aimlen) {
//        ret.push_back(path);
//        dfs(ret, path, nums, len, length, aimlen + 1,begin);
//        return;
//    }
//    else {
//        for (i = begin; i < length; i++) {
//            path.push_back(nums[i]);
//            dfs(ret, path, nums, len + 1, length, aimlen,i+1);
//            path.pop_back();
//
//        }
//    }
//
//}
//vector<vector<int>> subsets(vector<int>& nums) {
//    vector<vector<int>> ret;
//    vector<int>path;
//    int length = nums.size();
//    dfs(ret, path, nums, 0, length, 0,0);
//    return ret;
//}
//int main() {
//
//    vector<int>nums{ 1,2,3 };
//    vector<vector<int>>ret = subsets(nums);
//    for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++) {
//        for (vector<int>::iterator i = (*it).begin(); i != (*it).end(); i++) {
//            cout << *i << ' ';
//        }
//        cout << endl;
//    }
//
//	return 0;
//}


//leetcode 79. Word Search
//https://leetcode.com/problems/word-search/description/
#include <iostream>
#include <vector>
#include <string>
using namespace std; 
bool bfs(vector<vector<char>>& board, string& word, int x, int y, int aim, int& row, int& col) {
    if (word[aim] == '\0')return true;
    if (x < 0 || x >= row || y < 0 || y >= col)return false;
    bool ret = false;
    if (board[x][y] == word[aim]) {
        board[x][y] -= 80;
        ret = ret || bfs(board, word, x - 1, y, aim + 1, row, col);
        ret = ret || bfs(board, word, x + 1, y, aim + 1, row, col);
        ret = ret || bfs(board, word, x, y - 1, aim + 1, row, col);
        ret = ret || bfs(board, word, x, y + 1, aim + 1, row, col);
        board[x][y] += 80;
    }
    else {
        return false;
    }
    return ret;
}
bool exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    int col = board[0].size();
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (board[i][j] == word[0]) {
                if (bfs(board, word, i, j, 0, row, col))return true;
            }
        }
    }
    return false;
}
int main() {
    vector<vector<char>>board = { {'C','B'},{'a','G'} };
    string word = "CBGaa";
    cout << exist(board, word);
	return 0;
}