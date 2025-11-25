#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<limits>//not aquired
using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1 || nums[i] > threshold) continue;

            int count = 1; 
            int j = i + 1;

            while (j < n && (nums[j] <= threshold) && ((nums[j] % 2) != (nums[j - 1] % 2))) {
                count++;
                j++;
            }
            max_len = max(max_len, count);
            i = j - 1;
        }

        return max_len;
    }
};

int main()
{
    vector<int> nums = {2,3,2,3,2,3,3,2,3,2,3,2,3,2,3,2,3,2,3}; int k = 6;
    Solution sol;
    cout<<sol.longestAlternatingSubarray(nums,k);

}