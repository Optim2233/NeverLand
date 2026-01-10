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
int main()
{
    vector<int> nums = {1,1,1}; int k = 2;
    int running = 0; unordered_map<int,int> map;
    map[running] = 1; int n = nums.size(), count = 0;
    for(int i = 0; i < n ; i++)
    {
       running += nums[i];
       if(map.count(running - k)) count += map[running-k];
       map[running]++;
    }
    for(int i : nums) cout<<i<<" ";
    cout<<count;
}   

