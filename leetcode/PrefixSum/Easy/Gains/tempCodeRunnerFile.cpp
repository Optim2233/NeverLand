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
    int largestAltitude(vector<int>& gain) {
        int n = gain.size(), sum = 0, m = max(0,gain[0]);
        for(int i = 1; i < n ; i++)
        {
            gain[i] += gain[i-1];
            m = max(m,gain[i]);
        }
        return m;
    }
};

int main()
{
    Solution sol;
    vector<int>nums = {-4,-3,-2,-1,4,3,2};
    cout<<sol.largestAltitude(nums);
    
}