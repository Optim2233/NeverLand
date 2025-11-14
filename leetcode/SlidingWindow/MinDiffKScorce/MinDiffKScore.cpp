#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size() , MinDiff = numeric_limits<int>::max();
        sort(nums.begin(), nums.end());
        if(n == 1) return  0;
        for(int i = 0; i <= n - k; i++)
        {
            int Difference = abs(nums[i] - nums[i + k - 1]);
            MinDiff = min(MinDiff, Difference);
        }
        return MinDiff;
    }
};


int main() 
{
    Solution sol;
    vector<int>nums = {87063,61094,44530,21297,95857,93551,9918}; int k = 2;
    cout<<sol.minimumDifference(nums,k);
    return 0;
}
