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
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size(); int left_sum = 0, right_sum = 0;
        vector<int> PS(n);
        PS = nums;
        for(int i = 1; i < n; i++)
        {
            PS[i] += PS[i-1];
        }
        for(int midx = 0; midx < n; midx ++)
        {
            if(midx == 0) left_sum = 0;
            else {left_sum = PS[midx-1];}
            right_sum = PS[n-1] - PS [midx];
            if(left_sum == right_sum) return midx;
        }
        return -1;
    }
};
int main()
{
    vector<int> nums = {1,7,3,6,5,6};
    Solution sol;
    cout<<sol.findMiddleIndex(nums);
}