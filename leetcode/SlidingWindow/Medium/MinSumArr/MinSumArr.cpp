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
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, left = 0 , n = nums.size(), min_len = INT_MAX;
        for(int right = 0 ; right < n ; right++)
        {
            sum += nums[right];
            while(sum >= target)
            {
                min_len = min(min_len, right - left + 1 );
                sum -= nums[left];
                left++;
            }
        }
        return (min_len == INT_MAX)? 0 : min_len;
    }   
};

int main()
{
    Solution sol;
    vector<int> nums = {12,28,83,4,25,26,25,2,25,25,25,12};
    cout<<sol.minSubArrayLen(11,nums);
    
}