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
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(); int max_len = 0;
        int right = 0, left = 0,bit_sum = 0;
        while(right < n)
        {     
            while((bit_sum & nums[right]) != 0)
            {
                bit_sum ^= nums[left];
                left++; 
            }
            bit_sum |= nums[right];
            max_len = max(max_len, right - left  + 1);
            right++;
        }
        return max_len;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {3,1,5,11,13};
    cout<<sol.longestNiceSubarray(nums);


}