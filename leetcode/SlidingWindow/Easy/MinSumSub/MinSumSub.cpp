#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<climits>
#include<limits>//will be revisited
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), left = 0 , min_sum = INT_MAX;
        for(int right = 0 ; right < n; right++)
        {
            int sum = 0;
            for(int j = right; j >= l && j >=j)
        }
        return (min_sum == INT_MAX)? -1 : min_sum;
    }
};
int main()
{
    int l = 1, r = 3;
    vector<int>nums =   {-18,6,9};
    Solution sol;
    cout<<sol.minimumSumSubarray(nums,l,r);

}   