#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<limits>
#include<numeric>
#include<cstring>
using namespace std;


class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> LeftSum (n,0), RightSum (n,0);
        for(int i = 1; i < n ; i++)
        {
            LeftSum[i] = LeftSum[i-1]+nums[i-1];
        }
        reverse(nums.begin(), nums.end());
        for(int i = 1; i < n ; i++)
        {
            RightSum[i] = RightSum[i-1]+nums[i-1];
        }
        reverse(RightSum.begin(), RightSum.end());
        for(int i = 0; i < n; i++)
        {
            RightSum[i] = abs(LeftSum[i] - RightSum[i]);
        }
        return RightSum;
    }
};


int main()
{
    Solution sol;
    vector<int>nums = {1};
    nums = sol.leftRightDifference(nums);
    for(int i : nums) cout<<i<<" ";
}