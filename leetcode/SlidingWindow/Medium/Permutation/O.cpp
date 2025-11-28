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
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), m = s1.size();
       int freq[26] = {0};
       for( char c : s1) freq[c - 'a']++; 
       int count = m;
       int right = 0, left = 0;
       while(right < n)
       {
        if(freq[s2[right] - 'a'] > 0) count--;

        freq[s2[right] - 'a']--;
        while(right - left + 1 >= m){
            if(count == 0) return true;
            if(freq[s2[left] - 'a'] >= 0) count++;
            freq[s2[left] - 'a']++;
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
    cout<<boolalpha<<sol.checkInclusion(p,s);
}