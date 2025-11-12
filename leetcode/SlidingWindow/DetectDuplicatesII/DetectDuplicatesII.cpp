#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
     unordered_set<int> window; int size = nums.size(); if(size <= 1) return false;
     for(int j = 0 ; j < min(k,size); j++) {if(!window.count(nums[j])) window.insert(nums[j]);else return true; }

     for(int i = 0 ; i < size - k; i++)
     {
        if(i != 0) window.erase(nums[i-1]);
        if(!window.count(nums[i+k])) window.insert(nums[i+k]);else return true;
         
     }  
     return false;
    }
};

int main()
{
    vector<int> nums = {1,2,3,1,2,3}; int k = 2;
    Solution sol;
    cout<<boolalpha<<sol.containsNearbyDuplicate(nums,k);
}