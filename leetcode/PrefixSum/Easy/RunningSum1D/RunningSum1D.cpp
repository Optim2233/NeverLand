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
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n ; i++)
        {
            nums[i] += nums[i-1];
        }
        return nums;
    }
};
int main()
{
    Solution sol;
    vector<int>nums = {1,2,3,4};
    nums = sol.runningSum(nums);
    for(int i : nums) cout<<i<<" ";
    
}