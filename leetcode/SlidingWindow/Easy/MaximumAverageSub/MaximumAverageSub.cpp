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
        int s = nums.size(); double sum = 0, avg = 0 , temp = numeric_limits<double>::lowest();
     for(int i = 0 ; i < s ; i++)
     {
        sum += nums[i];
        if(i >= k - 1)
        {
            avg = sum / k;
            //(temp < avg)? temp = avg : avg = temp;
            if(temp < avg) temp = avg;
            sum -= nums[i-k + 1];
        }
     }
     return avg;
    }
};


int main()
{
    vector<int> nums = {-1}; int k = 1;
    Solution sol;
   cout<<sol.findMaxAverage(nums,k);
}