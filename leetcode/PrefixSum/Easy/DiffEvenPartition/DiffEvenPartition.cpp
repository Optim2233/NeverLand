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
    int countPartitions(vector<int>& nums)
    {
        int n = nums.size(), left_sum = 0, right_sum = 0, count = 0;
        for(int i = 1; i < n; i++)
        {
            nums[i] += nums[i-1];
        }
        for(int i = 0 ; i < n - 1; i++)
        {
            left_sum = nums[i];
            right_sum = nums[n-1] - nums[i];
            if((left_sum - right_sum) % 2 == 0) count++;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int>nums = {10,10,3,7,6};
    int n = nums.size() , left_sum = 0, right_sum = 0, count = 0;
    for(int i = 1; i < n; i++)
    {
        nums[i] += nums[i-1];
    }    
    for(int i : nums) cout<<i<<" ";
    cout<<endl;
    for(int i = 0 ; i < n - 1; i++)
    {
        left_sum = nums[i]; cout<<left_sum<<" ";
        right_sum = nums[n-1] - nums[i];cout<<right_sum<<" ";
        if((left_sum - right_sum) % 2 == 0) {cout<<left_sum-right_sum<<" "; count++; cout<<count<<" ";}
        cout<<endl;
    }
    
}