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
    vector<int> productExceptSelf(vector<int>& nums) {
        
    }
};

int main()
{
    vector<int> org ={1,-1,0,-3,3};
    int n = org.size();
    vector<int> prefix(n);
    vector<int>suffix(n);
    prefix = org; suffix = org;
    for(int i = 1; i < n; i++)
    {
        prefix[i] *= prefix[i-1];
    }
    for(int i : prefix) cout<<i<<" ";
    cout<<endl;
    for(int i = n-2 ; i >= 0; i--)
    {
        suffix[i] *= suffix[i+1];
     }
     for(int i : suffix) cout<<i<<" ";
     cout<<endl;
     vector<int> ans (n);
     int left = 1, right = 1;
     for(int i = 0 ; i < n; i++)
     {
        left =  (i == 0)?  1 : prefix[i-1];
        right = (i == n-1)? 1: suffix[i+1];
        ans[i] = left * right;
     }
     for(int i : ans) cout<<i<<" ";
}
