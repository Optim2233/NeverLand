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
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, max_c = 0;
        int right = 0, left = 0;
        while(right < n)
        {
            if(nums[right] == 1) count++;
            else
            {
                while(k == 0 && left < n)
                {
                    (nums[left]==1)? count-- : (count--, k++);
                    left++;
                }
                if(k > 0)
                {
                    k--;
                    count++;
                }
                
            }
            max_c = max(max_c, count);
            right++;
        }
        return max_c;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}; int k = 3;
    cout<<sol.longestOnes(nums,k);




}