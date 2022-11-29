#define _CRT_SECURE_NO_WARNINGS 1
//leetcode 33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/?favorite=2cktkvj

#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int l, r, mid;
    l = 0; r = nums.size();
    if (r == 1) {
        return target == nums[0] ? 0 : -1;
    }
    if (r == 2) {
        if (nums[0] == target)return 0;
        if (nums[1] == target)return 1;
        return -1;
    }
    if (nums[0] <= nums[r - 1]) {
        r--;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] > target)r = mid - 1;
            else if (nums[mid] < target)l = mid + 1;
            else return mid;

        }
        return -1;
    }
    int i, j;
    int len = nums.size() - 1;
    while (1) {
        mid = (l + r) / 2;
        if (mid == l)break;

        if (nums[mid] > nums[len]) {
            l = mid;
        }
        else if (nums[mid] <= nums[len]) {
            r = mid;
        }

    }
    cout << mid << endl;
    if (nums[0] > target) { l = mid + 1; r = len; }
    else { l = 0; r = mid; }
    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] > target)r = mid - 1;
        else if (nums[mid] < target)l = mid + 1;
        else return mid;
    }

    return -1;


}
int main() {
    vector<int>nums = {3,5,1 };
    cout << search(nums, 1);
	return 0;
}

#include <iostream>
using namespace std;
int main() {
	int cash = 20;
	int e = 0;
	int cnt = 0;
	while (cash || e>=2) {
		cash--;
		cnt++;
		e++;
		if (e >= 2) {
			e -= 2;
			cnt++;
			e++;
		}
	}
	cout << cnt;
	return 0;
}


//leetcode 34. Find First and Last Position of Element in Sorted Array
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    int l, r, mid;
    l = 0; r = nums.size();
    if (r < 1)return { -1,-1 };
    if (r == 1) {
        if (nums[0] == target)return { 0,0 };
        else return { -1,-1 };
    }
    while (l <= r&&l<nums.size() ){
        mid = (l + r) / 2;
        if (nums[mid] > target) {
            r = mid - 1;
        }
        else if (nums[mid] < target) {
            l = mid + 1;
        }
        else break;
    }
    if (l > r||l>=nums.size())return { -1,-1 };
    l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    return { l,r - 1 };
}
int main() {
    vector<int>ans;
    vector<int>nums = { 0,0,0 };
    ans = searchRange(nums, 1);
    cout << ans[0] << endl << ans[1];
	return 0;
}



//leetcode 39. Combination Sum
//https://leetcode.com/problems/combination-sum/description/
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>ans;
void dfs(vector<int>& candidates, vector<int>& path, int target, int sum, int begin) {
    if (target <= 0)return;
    if (sum == target) {
        ans.push_back(path);
        return;
    }
    else if (sum > target)return;
    for (int i = begin; i < candidates.size(); i++) {
        path.push_back(candidates[i]);
        sum += candidates[i];
        dfs(candidates, path, target, sum, i);
        path.pop_back();
        sum -= candidates[i];
    }

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int>path;
    dfs(candidates, path, target, 0, 0);
    return  ans;
}
int main() {
    int i = 0;
    vector<int>candidates = { 2,3,6,7 };
    combinationSum(candidates, 7);
    while (i < ans.size()) {
        int j=0;
        while (j < ans[i].size()) {
            cout << ans[i][j] << ' ';
            j++;
        }
        i++;
        cout << endl;
    }
	return 0;
}


//leetcode 46. Permutations
//https://leetcode.com/problems/permutations/submissions/851086992/

//Solution 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(vector<vector<int>>& ans, vector<int>& path, int len, int begin) {
    if (begin == len) {
        ans.push_back(path);
        return;
    }
    for (int i = begin; i < len; i++) {
        swap(path[i], path[begin]);
		  //put every possible number to the first place,until meet the end
        dfs(ans, path, len, begin + 1);
        swap(path[i], path[begin]);
		  //resume
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>path;
    dfs(ans, nums, (int)nums.size(), 0);
    return ans;
}
int main() {
    int i = 0;
    vector<int>candidates = {1,2,3};
    vector<vector<int>>ans=permute(candidates);
    while (i < ans.size()) {
        int j = 0;
        while (j < ans[i].size()) {
            cout << ans[i][j] << ' ';
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}

//Solution 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    sort(nums.begin(), nums.end());
    do {
        ans.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return ans;
}
int main() {
    int i = 0;
    vector<int>candidates = {1,2,3};
    vector<vector<int>>ans=permute(candidates);
    while (i < ans.size()) {
        int j = 0;
        while (j < ans[i].size()) {
            cout << ans[i][j] << ' ';
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}


