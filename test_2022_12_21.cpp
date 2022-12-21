
#include <stdio.h>
#include  <string.h>
#include <vector>
#include <string>
#include <map>
using namespace std;
vector<int> getConcatenation(vector<int>& nums) {
    int len = nums.size();
    for (int i = 0;i<len;i++) {
        nums.push_back(nums[i]);
    }
    return nums;
}
vector<int> decode(vector<int>& encoded, int first) {
    vector<int>ret;
    ret.push_back(first);
    for (int i = 1; i <= encoded.size(); i++) {
        int last = ret[i - 1];
        ret.push_back(last ^ encoded[i - 1]);
    }
    return ret;
}
int finalValueAfterOperations(vector<string>& operations) {
    int ret = 0;
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][1] == '+')ret++;
        else ret--;
    }
    return ret;
}
int mostWordsFound(vector<string>& sentences) {
    int max_word = 0;
    for (int i = 0; i < sentences.size(); i++) {
        int cnt = 1;
        for (int j = 0; j < sentences[i].size(); j++) {
            if (sentences[i][j] == ' ')cnt++;
        }
        max_word = max(max_word, cnt);
    }
    return max_word;
}
vector<int> shuffle(vector<int>& nums, int n) {
    vector<int>ret;
    int l = 0, r = n;
    for (l = 0; l < n; l++) {
        ret.push_back(nums[l]);
        ret.push_back(nums[r]);
        r++;
    }
    return ret;
}
int countConsistentStrings(string allowed, vector<string>& words) {
    int ret = 0;
    map<char, int>dict;
    for (int i = 0; i < allowed.size(); i++) {
        dict[allowed[i]] = 1;
    }
    for (int i = 0; i < words.size(); i++) {
        int f = 1;
        for (int j = 0; j < words[i].size(); j++) {
            if (dict[words[i][j]] != 1) {
                f = 0;
                break;
            }
        }
        if (f == 1)ret++;
    }
    return ret;
}
int numIdenticalPairs(vector<int>& nums) {
    int i, j;
    int ret = 0;
    for (i = 0; i < nums.size(); i++) {
        for (j = i + 1; j < nums.size(); j++) {
            if (nums[i] == nums[j])ret++;
        }
    }
    return ret;
}
vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int len = grid.size();
    vector<vector<int>>ret(len - 2);
    int i, j;
    for (i = 1; i < grid.size() - 1; i++) {

        for (j = 1; j < grid.size() - 1; j++) {
            int M = grid[i][j];
            M = max({ M,grid[i - 1][j - 1],grid[i - 1][j],grid[i - 1][j + 1],grid[i][j - 1],
            grid[i][j + 1],grid[i + 1][j - 1],grid[i + 1][j],grid[i + 1][j + 1] });
            ret[i - 1].push_back(M);
        }

    }

    return ret;
}
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool>ret;
    int M = 0;
    for (int i = 0; i < candies.size(); i++) {
        M = max(M, candies[i]);

    }
    for (int i = 0; i < candies.size(); i++) {
        if (candies[i] + extraCandies >= M)ret.push_back(true);
        else ret.push_back(false);
    }
    return ret;
}
int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int ret = 0;
    int i = 1;
    for (i = 1; i < points.size(); i++) {
        int dx = points[i][0] - points[i - 1][0];
        dx = abs(dx);
        int dy = points[i][1] - points[i - 1][1];
        dy = abs(dy);
        while (dx && dy) {
            dx--; dy--;
            ret++;
        }
        while (dx) {
            dx--; ret++;
        }
        while (dy) {
            dy--; ret++;
        }
    }
    return ret;
}
int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int ret = 0;
    int i = 1;
    int sx = 0, sy = 0;
    for (i = 1; i < points.size(); i++) {
        int dx = points[i][0] - points[i - 1][0];
        dx = abs(dx);
        int dy = points[i][1] - points[i - 1][1];
        dy = abs(dy);

        while (dx && dy) {
            int m = min(dx, dy);
            dx -= m; dy -= m;
            ret += m;
        }
        if (dx != 0) {
            ret += dx;
        }
        if (dy != 0)ret += dy;
    }

    return ret;
}
#include <time.h>
int main() {
	srand((unsigned int)time(NULL));
	int tmp = rand()%2;
	printf("%d", tmp);
	return 0;

}