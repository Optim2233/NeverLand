#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<limits>
using namespace std;

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() , j = 0 ,max_xor = 0, xr = 0;
        for(int i = 0 ; i < n; i++)
        {
            j = i;
            while( j < n && nums[i] * 2 >= nums[j] ) j++;
            for(int y = i; y < j; y++)
            {
                for(int z = y ; z < j; z++)
                {
                    xr = nums[y] ^ nums[z];
                    max_xor = max(xr, max_xor);
                }
            }
        }
        return max_xor;
    }
};
int main()
{
    vector<int> nums = {5,6,25,30}; int k = 6;
    Solution sol;
    cout<<sol.maximumStrongPairXor(nums);

   
}