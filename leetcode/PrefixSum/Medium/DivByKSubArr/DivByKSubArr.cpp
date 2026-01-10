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
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> lis;
        int n = nums.size(),running = 0,count = 0; lis[running]++;
        for(int i = 0; i < n; i++)
        {
            running += nums[i];
            int mod = ((running % k)+k) % k;
            if(lis.count(mod))
            {
                count += lis[mod];
            }
            lis[mod]++;
        }
        return count;
    }
};
int main()
{ 
    vector<int> nums = {5}; int k = 9; 
    unordered_map<int,int> lis;
    int n = nums.size(),running = 0,count = 0; lis[running]++;
    for(int i = 0; i < n; i++)
    {
        running += nums[i];
        int mod = ((running % k)+k) % k;
        if(lis.count(mod))
        {
            count += lis[mod];
        }
        lis[mod]++;
    }
    cout<<"Out "<<count;



}   

