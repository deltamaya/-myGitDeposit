#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    //模拟实现next_permutation函数
    vector<int> nums={1,2,3,4,5};
    int len = nums.size();
    int i = 0;
    int f = 0;
    for (i = len - 1; i > 0; i--) {

        if (nums[i - 1] < nums[i]) {
            f = 1;
            for (int j = len - 1; j >= i; j--) {
                if (nums[j] > nums[i - 1]) {
                    swap(nums[i - 1], nums[j]);
                    break;
                }
            }
            sort(nums.begin() + i, nums.end());
            break;
        }

    }
    if (f == 0)sort(nums.begin(), nums.end());
	return 0;
}