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
        int right = 0, left = 0, len = 0, max_len = 0;
        for(int i = 0 ; i < n; i++)
        {
           
            if(s[i] == t[i]){len++;}
            while(maxCost < abs(s[i] - t[i]))
            {
                maxCost = maxCost + (abs(s[left] - t[left]));
                len--;
                left++;
            }
            
             if(s[i] != t[i] && maxCost >= abs(s[i] - t[i]))
            {   
                maxCost = maxCost - (abs(s[i] - t[i]));
                len++;
            }
            max_len = max(max_len,len); 
        }
        return max_len;
    }
};
class Solution1 {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int right = 0, left = 0, len = 0, currCost = 0;
        while(right < n)
        {
            currCost += abs(s[right]- t[right]);

            while(currCost > maxCost)
            {
                currCost -= abs(s[left]- t[left]);
                left++;
            }
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};
int main()
{
    Solution1 sol;
    string s = "krrgw" , t = "zjxss";int maxCost = 19;
    cout<<sol.equalSubstring(s,t,maxCost);

}