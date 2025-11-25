#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<climits>
#include<limits>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
         int n = s.size(),  ans = 0,left = 0 ,right = 0,count0 = 0 , count1 = 0;
        for(int right = 0 ; right < n ; right++)
        {
        if(s[right]=='1') count1++; else count0++;            
        while(count0 > k && count1 > k) 
        {
            if(s[left] == '1') count1--; else count0--;
            left++;
        }
            ans += right - left + 1;
        }
        return ans;
    }
};
int main()
{
    string s = "10101";  int k = 1;
    Solution sol; 
    cout<<sol.countKConstraintSubstrings(s,k);
}