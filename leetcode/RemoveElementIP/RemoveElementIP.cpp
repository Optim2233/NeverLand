#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution 
{
    public: 
        int removeDuplicates(vector<int>& nums,int val) {
           if(nums.empty()) return 0;
           int i = 0;
           for( int j = 0 ; j < nums.size(); j++)
           {
            if(nums[j] != val) 
            {
                nums[i++] = nums[j];
            }
           }
           nums.resize(i);
           return i;
        }
};

int main()
{
    Solution sol;
    vector<int>nums = {0,1,2,2,3,0,4,2}; vector<int> NUMS = {3,2,2,2,3,3};
    cout<<sol.removeDuplicates(nums,2); cout<<endl; cout<<sol.removeDuplicates(NUMS,3);cout<<endl;
    for(int inte : nums) cout<<inte<<" "; cout<<endl;   for(int inte : NUMS) cout<<inte<<" ";

}