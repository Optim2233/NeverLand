#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<climits>
#include<limits>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int   min_len = numeric_limits<int>::max();
        for(int i = 0 ; i < nums.size(); i++)
        {

            int bitORsum = 0,j = 0, count = 0;
            for( j = i ; j < nums.size(); j++) 
            {
                bitORsum = bitORsum | nums[j];count++;
                if(bitORsum >=  k) { min_len = min(min_len, count); break;}
            }
        }
        return (min_len == numeric_limits<int>::max())? -1 : min_len;
    }
};
int main()
{
     vector<int> nums = {32,1,25,11,2}; int k = 59;
    Solution sol;

   cout<<sol.minimumSubarrayLength(nums,k);
}