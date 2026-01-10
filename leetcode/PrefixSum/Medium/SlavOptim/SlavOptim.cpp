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
    vector<int> productExceptSelf(vector<int>& org) {
    int n = org.size();
    vector<int> prefix(n);
    vector<int>suffix(n);
    prefix = org; suffix = org;
    for(int i = 1; i < n; i++)
    {
        prefix[i] *= prefix[i-1];
    }
    for(int i = n-2 ; i >= 0; i--)
    {
        suffix[i] *= suffix[i+1];
     }
     vector<int> ans (n);
     int left = 1, right = 1;
     for(int i = 0 ; i < n; i++)
     {
        left =  (i == 0)?  1 : prefix[i-1];
        right = (i == n-1)? 1: suffix[i+1];
        ans[i] = left * right;
     }
     return ans;
    }
};

int main()
{
    vector<int> hours = {9,9,6,6,6,9};

    unordered_map<int,int> map;
    int n = hours.size(), prefix = 0, ans = 0;
    for(int i = 0 ; i < n; i++)
    {
        if(hours[i] > 8) prefix += 1;
        else prefix -= 1;

        if(prefix > 0) ans = i+1;
        else{
            if(map.count(prefix - 1))
            {
                ans = max(ans, i - map[prefix-1]);
            }
        }

        if(!map.count(prefix))
            map[prefix] = i;
    }
    return ans;
}
