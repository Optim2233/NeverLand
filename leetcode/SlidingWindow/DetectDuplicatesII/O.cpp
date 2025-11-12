#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> window; int size = nums.size(); if(size <= 1) return false;
    for(int i = 0 ; i < size; i++)
    {
        if(window.count(nums[i])) return true; 
        window.insert(nums[i]);
        if(window.size() > size)
        {
            window.erase(nums[i-k]);
        }
    }
    return true;
    }
};

int main()
{
    vector<int> nums = {1,2,3,1,2,3}; int k = 2;
    Solution sol;
    cout<<boolalpha<<sol.containsNearbyDuplicate(nums,k);
}