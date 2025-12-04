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
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
        
        vector<int> ans;
        ans.reserve(queries.size());

        for(int q : queries){
            int idx = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            ans.push_back(idx);
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