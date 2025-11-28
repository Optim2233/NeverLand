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
    vector<int> findAnagrams(string s, string p) {
       int n = s.size(), m = p.size(); vector<int> ans;
       int freq[26] = {0};
       for( char c : p) freq[c - 'a']++; 
       int count = m;
       int right = 0, left = 0;
       while(right < n)
       {
        if(freq[s[right] - 'a'] > 0) count--;

        freq[s[right] - 'a']--;
        while(right - left + 1 >= m){
            if(count == 0) ans.push_back(left);
            if(freq[s[left] - 'a'] >= 0) count++;
            freq[s[left] - 'a']++;
            left++;
        }
        right++;
       }
       return ans;
    }
};
int main()
{
    Solution sol;
    string s = "cbaebabacd", p = "abc";
    vector<int> res = sol.findAnagrams(s,p);
    for(int i : res) cout<<i<<" ";
}