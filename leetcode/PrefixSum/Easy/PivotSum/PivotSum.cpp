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
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), left_sum = 0, right_sum = 0;
        vector<int>PS;
        PS = nums;
        for(int i = 1 ; i < n; i++)
        {
            PS[i] += PS[i-1];
        }

        for(int piv = 0; piv < n; piv++)
        {
            if(piv == 0) left_sum = 0;
            else{left_sum = PS[piv - 1];}
            right_sum = PS[n-1] - PS[piv];
            if(left_sum == right_sum) return piv;
        }
        return -1;
    }
};
int main()
{
    vector<int> nums = {1,7,3,6,5,6};
    Solution sol;
    cout<<sol.pivotIndex(nums);
}