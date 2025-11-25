#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<limits>
#include<numeric>
using namespace std;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(); if( n < 3) return 0;
        int left = 0, right = left + 1, preset = nums[1] - nums[0]; long long ans = 0;
        for(int right = 2 ; right < n ; right ++)
        {
            if(nums[right] - nums[right - 1] != preset)
            {
                int len = right - left;
                if(len >= 3)
                {
                    ans += (len - 2) * (len - 1) / 2;
                }
                left = right - 1;
                preset = nums[right] - nums[right - 1];
            }
            
        }
        int len = n - left;
        if(len >= 3)
            ans += (len - 2) * (len - 1) / 2;
        return (int)ans;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4};
    Solution sol;
    cout<<sol.numberOfArithmeticSlices(nums);

}