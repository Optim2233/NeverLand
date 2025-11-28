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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 0) return 1;
        int n = nums.size();
        int right = 0 , left = 0 , ans = 0 ; long long prd = 1;
        while(right < n)
        {
            prd  *=  nums[right];
            while(prd >= k){ prd /= nums[left] ; left++;}
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {333}; int k = 1;
    cout<<sol.numSubarrayProductLessThanK(nums,k);

}