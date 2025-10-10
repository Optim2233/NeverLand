#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public: 
        void moveZeros(vector<int>& nums)
        {
            int zeros = 0;
            for(int i = 0 ; i < nums.size(); i++)
            {
                if(nums[i] == 0)
                {
                    nums.erase(nums.begin() + i);
                    i--;
                    zeros++;
                }        
            }
            nums.resize(nums.size() + zeros, 0);
        }
};
int main()
{
    vector<int>nums = {1,0,0,0,1,9,0};
    Solution sol;
    sol.moveZeros(nums);
    for(int in : nums)
    {
        cout<<in<<" ";
    }
}