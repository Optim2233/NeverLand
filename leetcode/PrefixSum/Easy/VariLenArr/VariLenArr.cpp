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
    int subarraySum(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        vector<int> PS(n);
        PS = nums;
        for (int i = 1; i < n; i++) {
            PS[i] += PS[i - 1];
        }
        for (int i = 0; i < n; i++) {
            int start = max(0, i - nums[i]);
            sum += PS[i];
            if (start - 1 >= 0) {
                sum -= PS[start - 1];
            }
        }

        return sum;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1,4,1,5,1};
    cout<<sol.subarraySum(nums);
}