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
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();vector<int> ans; int  query_mover = 0, i = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i ++)
        {
            nums[i] += nums[i-1];
        }
        for(query_mover; query_mover < queries.size();query_mover++)
        {
            int right = 0;
            while(right < n && nums[right] <= queries[query_mover])// && nums[right+1] <= queries[query_mover]
            {
                right++;
            }
            ans.push_back(right);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int>nums = {1,2,4,5}, queries = {0};//{1,3,7,12}
    nums = sol.answerQueries(nums,queries);
    for(int i : nums) cout<<i<<" ";
}