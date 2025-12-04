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
using namespace std;//bruteforce
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int len = 1; len <= n; len += 2)
        {
            for(int start = 0; start + len - 1< n; start++)
                for(int k = start ; k < start + len; k++)
                {
                    sum += nums[k];
                }
        }
         return sum;
    }
};
int main()
{
    Solution sol;
    vector<int>nums = {1,4,2,5,3};
    cout<<sol.sumOddLengthSubarrays(nums);

    
}