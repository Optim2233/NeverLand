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
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
         if (n <= 2) 
         {  if(n <= 1) return 1; 
            if(cmp(arr[n-2],arr[n-1]) != 0) return 2;
            else return 1;
         }
        int right = 1 , left = 0, max_len = 1;
        int prev , curr;
        while(right < n)
        {
            int curr = cmp(arr[right-1] , arr[right]);
            if(curr==0){left = right;} else if( right == n-1 || curr * cmp(arr[right], arr[right + 1]) != -1)
            {
                max_len = max(max_len, right - left + 1);
                left = right;
            }    
            right++;   
        } 
        return max_len;
    }
    int cmp(int a, int b)
    {
        if(a==b) return 0;

        return (a < b)? 1 : -1;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {9,4,2,10,7,8,8,1,9}; int goal = 0;

    cout<<sol.maxTurbulenceSize(nums);



}