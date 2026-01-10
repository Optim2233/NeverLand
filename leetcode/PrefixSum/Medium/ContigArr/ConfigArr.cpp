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
        vector<int> nums = {0,1,1,1,1,1,0,0,0};//0,1,2,3,4,5,5,5,5
        int n = nums.size(), max_len = 0;unordered_map<int,int> map; int running = 0;map[running] = -1;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0) nums[i] = -1;
        }
        for(int i = 0; i < n; i++)
        {
            running += nums[i];
            if(!map.count(running))
                map[running] = i;
            else 
            {
                max_len = max(max_len, i - map[running]);
            }
        }
        return max_len;
        }
};
int main()
{
    vector<int> nums = {0,1,1,1,1,1,0,0,0};//0,1,2,3,4,5,5,5,5
    int n = nums.size(), max_len = 0;unordered_map<int,int> map; int running = 0;map[running] = -1;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == 0) nums[i] = -1;
    }


    for(int i : nums) cout<<i<<" ";

    for(int i = 0; i < n; i++)
    {
        running += nums[i];
        if(!map.count(running))
            map[running] = i;
        else 
        {
            max_len = max(max_len, i - map[running]);
        }
    }
    return max_len;
}   

