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
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), m = t.size();
        int right = 0, left = 0, len = 0;
       while( right < n)
       {
            if(s[right] != t[right] && maxCost >= abs(s[right] - t[right]))
            {
                maxCost -= (abs(s[right] - t[right]));
                len++;
            }else if(s[right] == t[right]) len++;
            else{
                while(maxCost < abs(s[right] - t[right]))
                    {
                        maxCost += (abs(s[left] - t[left]));
                        len--;
                        left++;
                    }
                }
                right++;
       }
        return len;
    }
};
int main()
{
    Solution sol;
    string s = "krrgw" , t = "zjxss";int maxCost = 19;
    cout<<sol.equalSubstring(s,t,maxCost);

}