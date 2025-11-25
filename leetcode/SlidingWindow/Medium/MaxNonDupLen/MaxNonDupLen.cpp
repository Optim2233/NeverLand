#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<limits>
#include<numeric>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();unordered_set<char> seen;
        int left = 0, right = 0, max_len = 0;

            while(right < n && left < n)
            {
                if(!seen.count(s[right])) {seen.insert(s[right]);right++;}
                else 
                { 
                    while(seen.count(s[right])) {seen.erase(s[left]); left++; }
                }   
                max_len = max(max_len,( right - left ));
                     
            }          
        return max_len;
    }
};
int main()
{
    string s = "dvdf";
    Solution sol; 
    cout<<sol.lengthOfLongestSubstring(s);

}