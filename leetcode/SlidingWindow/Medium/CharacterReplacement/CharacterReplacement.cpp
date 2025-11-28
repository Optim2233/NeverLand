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
    int characterReplacement(string s, int k) {
        int n = s.size();
        int right = 0 , left = 0;int  freq [26] = {0}; int max_freq = 0, len = 0;
        while(right < n && left < n)
        {
            
            freq[s[right ]- 'A']++;
            max_freq = max(max_freq, freq[s[right] - 'A']);
            while(right - left + 1 - max_freq > k){freq[s[left]- 'A']--; left++;}
            len = max(len, right - left + 1 );
            right++;
        }
        return len;
    }
};
int main()
{
    Solution sol;
    string s = "AABABBA"; int k = 1;
    cout<<sol.characterReplacement(s,k);


}