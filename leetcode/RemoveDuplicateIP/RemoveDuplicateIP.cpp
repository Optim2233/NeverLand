#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution 
{
    public: 
        int removeDuplicates(vector<int>& nums) {
            if(nums.empty()) return 0;
            int i = 0;
            for ( int j = 1; j < nums.size(); j++)
            {
                if(nums[j] != nums[i]) 
                    nums[++i] = nums[j];
            } 
            return i + 1;
        }
};

int main()
{
    Solution sol;
    vector<int>nums = {1,2,3,10,11,12};
    cout<<sol.removeDuplicates(nums); cout<<endl;
    for(int inte : nums) cout<<inte<<" ";
}