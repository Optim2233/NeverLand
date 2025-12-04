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
    int minStartValue(vector<int>& nums) {
        int n = nums.size(), min_sum = 0, sum = 0;
        for(int i = 0 ; i < n; i++)
        {
            sum += nums[i];
            min_sum = min(min_sum,sum);
        }
        return 1- min_sum;
    }
};

int main()
{
    vector<int> nums = {1,7,3,6,5,6};
    Solution sol;
}