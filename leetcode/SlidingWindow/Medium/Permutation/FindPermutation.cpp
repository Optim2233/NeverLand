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
    bool checkInclusion(string p, string s){
       int n = s.size(), m = p.size(); 
       unordered_map<char, int> freq_p; unordered_map<char, int> freq_s; vector<int> ans;
       for(int i = 0 ; i < m; i++) freq_p[p[i]]++;
        int left = 0 , right = 0;
       while (right < n)
       {
            freq_s[s[right]]++;
            while(right - left + 1 >= m)
            {
                if(freq_p == freq_s) {return true;}
                freq_s[s[left]]--; if(freq_s[s[left]] == 0) freq_s.erase(s[left]);
                left++;
            }
            right++;
       }
       return false;
    }
};
int main()
{
    Solution sol;
    string s = "cbaebabacd", p = "abc";
    bool ans = sol.checkInclusion(p,s);
    cout<<boolalpha<<ans;
}