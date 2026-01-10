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
    int findMaxLength(vector<int>& nums) {
        return 0;
    }
};
int main()
{
    vector<int> nums = {0,1,1,1,1,1,0,0,0};//0,1,2,3,4,5,5,5,5
    int n = nums.size();unordered_map<int,int> map; int running = 0;map[running] = 0;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == 0) nums[i] = -1;
    }

    for(int i = 1; i < n; i++)
    {
        nums[i] += nums[i-1];
    }
    
    for(int i : nums) cout<<i<<" ";

    for(int i = 0; i < n; i++)
    {
        running += nums[i];
        map[running] = i;
    }

}   

