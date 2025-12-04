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
   int returnToBoundaryCount(vector<int>& nums) {
        int n = nums.size(), count0 = 0;
        for(int i = 1; i < n; i++)
        {
            nums[i] += nums[i-1];
        }
        for(int i = 0 ; i < n; i++)
        {
            if(nums[i] == 0) count0++;
        }
        return count0;
    }
};
    int main()
    {
        Solution sol;
        vector<int> nums = {2,3,-5};
        int c = sol.returnToBoundaryCount(nums);
        cout<<c;
        
    }