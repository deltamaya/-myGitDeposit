#define _CRT_SECURE_NO_WARNINGS 1

//simulate function strcpy and strlen

#include <iostream>
#include <assert.h>
using namespace std;
size_t  my_strlen(const char* str) {
	unsigned int i = 0;
	while (str[i] != '\0')i++;
	return i;
	//size_t==unsigned int
}
char* my_strcpy(char* dst, const char* rse) {
	assert(my_strlen(rse));
	//if the length of string "rse" was zero, report error
	char* ret = dst;
	while (*rse != '\0') {
		*dst++ = *rse++;
	}
	return ret;
}
int main() {
	char str1[20] = "hello world!";
	char str2[20] = "";
	printf("%s\n", my_strcpy(str2, str1));
	return 0;
}


//a function to move odd numbers to the front of an array, and move even numbers to the back of an array

#include <iostream>
using namespace std;
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int l = 0;
	int r = sizeof(arr) / sizeof(arr[0])-1;
	while (l <=r) {
		while (arr[l] % 2 == 1) {
			l++;
		}
		while (arr[r] % 2 == 0) {
			r--;
		}
		arr[l] += arr[r];
		arr[r] = arr[l] - arr[r];
		arr[l] -= arr[r];
	}
	for (l = 0; l < 10; l++) {
		printf("%d ", arr[l]);
	}
	return 0;
}


// learning of lower_bound and upper_bound
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp_lower(int value, int element) {
	return (value<element);
}
bool cmp_upper(int value, int element) {
	return (element>value);
}
//compare function parameter list (value,element);
int main() {
	vector<int>v = { 1,2,2,2,2 };
	//using these two functions in an FULLY SORTED ARRAY
	int l = lower_bound(v.begin(), v.end(),3,cmp_lower) - v.begin();
	// parameter list (iterator pointing to the "first" , iterator pointing to the "last" , value , [compare function])
	//return an iterator pointing to the first element in the range of[first,last)
	//that (dosen't satisfy element<value) or (compare function returns false)
	//time complexity O(log n)
	int r = upper_bound(v.begin(), v.end(), 3,cmp_upper) - v.begin();
	// parameter list (iterator pointing to the "first" , iterator pointing to the "last" , value , [compare function])
	//return an iterator pointing to the first element in the range of[first,last)
	//that (satisfy value<element) or (compare function returns true)
	//time complexity O(log n)
	cout << l << ' ' << r << endl;
	//generally cmp_lower and cmp_upper are usually equal ,we could just program a single compare function to fit these two functions
	return 0;
}

//leetcode 49. Group Anagrams
//https://leetcode.com/problems/group-anagrams/description/
//
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>>ans;
    vector<string>path;
    map<string, vector<string>>hash;
    for (string& str : strs) {
        string k = str;
        sort(str.begin(), str.end());
        hash[str].push_back(k);
    }
    for (auto it = hash.begin(); it != hash.end(); it++) {
        ans.push_back(it->second);
    }
    return ans;
}
int main() {
    vector<vector<string>>ret;
    vector<string>strs = { "nat","tea","ate","tan","bat","eat" };
    ret = groupAnagrams(strs);
    for (int i = 0;i<ret.size();i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ' ';
        }
        cout << endl;
    }
	return 0;
}



//leetcode 15. 3Sum
//https://leetcode.com/problems/3sum/description/


//Solution 1 Deep First Search(Time Limit Exceeded)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(vector<vector<int>>& ans, vector<int>& path, vector<int>& nums, int begin, int sum, int len, int cnt) {
    int i = 0;
    if (cnt > 3)return;
    if (sum == 0 && cnt == 3) {
        ans.push_back(path);
        return;
    }
    for (i = begin; i < len; i++) {
        sum += nums[i];
        path.push_back(nums[i]);
        dfs(ans, path, nums, i+1, sum, len, cnt + 1);
        path.pop_back();
        sum -= nums[i];
    }
}
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>path;
    int len = nums.size();
    dfs(ans, path, nums, 0, 0, len, 0);
    for (int i = 1; i < ans.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (ans[i][0] == ans[j][0] && ans[i][1] == ans[j][1]) {
                ans.erase(ans.begin() + j, ans.begin() + j + 1);
                i--;
                j--;
            }
        }
    }
    return ans;
}
int main() {
    vector<int>nums = { 12,5,-12,4,-11,11,2,7,2,-5,-14,-3,-3,3,2,-10,9,-15,2,14,-3,-15,-3,-14,-1,-7,11,-4,-11,12,-15,-14,2,10,-2,-1,6,7,13,-15,-13,6,-10,-9,-14,7,-12,3,-1,5,2,11,6,14,12,-10,14,0,-7,11,-10,-7,4,-1,-12,-13,13,1,9,3,1,3,-5,6,9,-4,-2,5,14,12,-5,-6,1,8,-15,-10,5,-15,-2,5,3,3,13,-8,-13,8,-5,8,-6,11,-12,3,0,-2,-6,-14,2,0,6,1,-11,9,2,-3,-6,3,3,-15,-5,-14,5,13,-4,-4,-10,-10,11 };
    sort(nums.begin(), nums.end());
    vector<vector<int>>ret = threeSum(nums);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ' ';
        }
        cout << endl;
       }
	return 0;
}


//Solution 2 double pointer
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>ans;
    sort(nums.begin(), nums.end());
    int i = 0, l = 1, r = nums.size() - 1;
    for (i = 0; i < nums.size(); i++) {
        l = i + 1; r = nums.size() - 1;
        if (nums[i] > 0 || nums[r] < 0)continue;
        if (i > 0 && nums[i] == nums[i - 1])continue;
        while (l < r) {
            if (nums[i] + nums[l] + nums[r] > 0) {
                r--;
            }
            else if (nums[i] + nums[l] + nums[r] < 0) {
                l++;
            }
            else {
                ans.push_back(vector<int>{nums[i], nums[l], nums[r]});
                while (r > l && nums[r] == nums[r - 1]) r--;
                while (r > l && nums[l] == nums[l + 1]) l++;
                r--;
                l++;
            }
        }
    }
    return ans;
}
int main() {
    vector<int>nums = { 1,1,-2};
    
    vector<vector<int>>ret = threeSum(nums);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}