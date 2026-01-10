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
#include<map>
using namespace std;
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        
    }
};

int main()
{    
    vector<int> nums = {9,1,2,3,9}; int k = 3;

    for(int i = 1; i < nums.size(); i++)
    {
        nums[i] += nums[i-1];
    }
    for(int i : nums) cout<<i<<" ";
}   

