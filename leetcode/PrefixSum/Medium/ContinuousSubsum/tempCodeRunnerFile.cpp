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
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {

        }
    }
};
int main()
{
    vector<int> nums = {23,2,4,6,7};
    int n = nums.size();
    for(int i = 1 ; i < n; i++)
    {
        nums[i] += nums[i-1];
    }
    for(int i = 0; i < n; i++)
    {
        cout<<nums[i]<<" ";
    }
}   

