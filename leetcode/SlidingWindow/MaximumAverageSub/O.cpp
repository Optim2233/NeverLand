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
    double findMaxAverage(vector<int>& nums, int k) {
    int s = nums.size(); double sum = 0;
    for(int j = 0 ; j < k; j++) sum += nums[j];

    double ans = sum;
    for(int i = k ; i < s ; i++)
    {
        sum += nums[i] - nums[i-k];
        ans = max(ans, sum);
    }
    return ans / k;
    }
};


int main()
{
    vector<int> nums = {-1}; int k = 1;
    Solution sol;
   cout<<sol.findMaxAverage(nums,k);
}