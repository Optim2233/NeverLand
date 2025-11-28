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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int right = 0 , left = 0, sum = 0, count = 0;
        while(right < n)
        {
            sum += nums[right];
            while(sum > goal){sum -= nums[left]; left++;}   
            if(sum >= goal) count++;
            right++;
        }left++;
        while(left < n)
        {
            if(sum >= goal) count++; 
            sum -= nums[left];
            left++;            
        }
        return count;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {0,0,0,0,0}; int goal = 0;
    cout<<sol.numSubarraysWithSum(nums,goal);



}