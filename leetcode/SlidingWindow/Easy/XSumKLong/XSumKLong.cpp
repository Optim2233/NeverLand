#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<climits>//will be revisited later
#include<limits>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
    }

    int X_sum(vector<int>&nums, int x)
    {
        int n = nums.size(), x_sum = 0;
        unordered_map<int,int> freq; int max_freq = 0 , max_val = numeric_limits<int>::max();
        for(int i = 0 ; i < x ; i++)
        {
            for(int val : nums)
            {    
                freq[val]++;
                if(freq[val] > max_freq)
                {
                    max_freq = freq[val];
                     max_val = val;
                }else if( freq[val] == max_freq)
                {
                    max_val = max(max_val, val);
                }
            }
            x_sum += max_val * max_freq;
            
        }
       return max_val;

    }
};
int main()
{
    vector<int> nums = {1,1,2,2,3,4}; int   k = 6, x = 2;
    Solution sol; 
    cout<<sol.X_sum(nums,x);
}