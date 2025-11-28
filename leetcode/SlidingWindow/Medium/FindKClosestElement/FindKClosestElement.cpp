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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(); vector<int> ans;
        int right = 0 , left = 0, window = 0;
        while(right < k)
        {
            window += abs(x - arr[right]);
            right++;
        }
        int best_window = window, best_start = 0;
        while( right < n)
        {
            window += abs(x - arr[right]);
            window -= abs(x - arr[left]);
            right++; left++;
            if(window < best_window)
            {
                best_window = window;
                best_start = left;
            }
        }
        for(int i = best_start ; i < best_start + k ; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4,5}; int k = 4, x = 3;
    vector<int> ans = sol.findClosestElements(nums,k,x);
    for(int i : ans) cout<<i<<" ";
}