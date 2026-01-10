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
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            return 1;
        }
    };
    int main()
    {    
        vector<int> nums = {1,0,1,0,1}; 
        int k = 2;
        unordered_map<int,int> map;
        int running = 0, n = nums.size(), count = 0;
        map[running]++;
        for(int i = 0; i < n; i++)//1:2
        {
            running += nums[i];
            
            if(map.count(running - k))
                {
                    count += map[running - k];
                } 
            map[running]++;
        }
        cout<<count;
    }   

