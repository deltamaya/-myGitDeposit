#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<int>> generate(int numRows) {
    if (numRows == 1)return { {1} };
    else if (numRows == 2)return { {1},{1,1} };
    else {
        vector<vector<int>>ret;
        vector<int>ans;
        ret = generate(numRows - 1);
        ans.push_back(1);
        for (int i = 1; i < ret.size(); i++) {
            ans.push_back(ret[ret.size() - 1][i - 1] + ret[ret.size() - 1][i]);
        }
        ans.push_back(1);
        ret.push_back(ans);
        return ret;
    }


}
 
 
vector<int> getRow(int rowIndex) {
    if (rowIndex == 0)return { 1 };
    else if (rowIndex == 1)return { 1,1 };
    else {
        vector<int>ans;
        ans = getRow(rowIndex - 1);
        vector<int>ret;
        ret.push_back(1);
        for (int i = 1; i < ans.size(); i++) {
            ret.push_back(ans[i - 1] + ans[i]);
        }
        ret.push_back(1);
        return ret;
    }
}

vector<int> spiralOrder(vector<vector<int>> matrix) {
    vector <int> ans;
    if (matrix.empty()) return ans; //若数组为空，直接返回答案
    int u = 0; //赋值上下左右边界
    int d = matrix.size() - 1;
    int l = 0;
    int r = matrix[0].size() - 1;
    while (true)
    {
        for (int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
        if (++u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
        for (int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
        if (--r < l) break; //重新设定有边界
        for (int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
        if (--d < u) break; //重新设定下边界
        for (int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
        if (++l > r) break; //重新设定左边界
    }
    return ans;
}
//{1, 2, 3, 4}, { 5,6,7,8 }, { 9,10,11,12 }


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int i = 0, j = 0;
    if (matrix[0][0] > target)return false;
    if (matrix[row - 1][col - 1] < target)return false;
    while (i < row) {
        if (matrix[i][col - 1] >= target)break;
        else i++;
    }
    for (j = 0; j < col; j++) {
        if (matrix[i][j] == target)return true;
    }
    return false;
}

double myPow(double x, int n) {
    double tmp = 1.0;
    if (n > 0) {
        while (n > 1) {
            if (n % 2 == 0) {
                x *= x;
                n >>= 1;
            }
            else {
                tmp *= x;
                x *= x;
                n >>= 1;

            }

        }
        return tmp * x;

    }
    else if (n < 0) {
        x = 1 / x;
        n = -n;
        while (n > 1) {
            if (n % 2 == 0) {
                x *= x;
                n >>= 1;
            }
            else {
                tmp *= x;
                x *= x;
                n >>= 1;
            }
        }
        return tmp * x;
    }
    else return 1;
}

#include <stdlib.h>
int minOperations(vector<int>& nums) {
    int ret = 0;
    int i = 0, len = nums.size();
    for (i = 1; i < len; i++) {
        if (nums[i - 1] >= nums[i]) {
            ret += nums[i - 1];
            ret -= nums[i];
            ret++;
            nums[i] = nums[i - 1] + 1;
        }
    }
    return ret;
}
void ch(string &num,int x) {
    if (x > 0) {
        int tmp = x % 10;
        ch(num, x / 10);
        num.push_back(tmp + '0');
    }return;
}
bool isPalindrome(int x) {
    if (x < 0)return false;
    string num;
    ch(num, x);
    int l = 0, r = num.size() - 1;
    while (l < r) {
        if (num[l] == num[r]) {
            l++; r--;
        }
        else {
            return false;
        }
    }
    return true;
}
int main() {
    cout << isPalindrome(1);
	return  0;
}