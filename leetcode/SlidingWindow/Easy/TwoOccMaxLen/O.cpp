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
    int maximumLengthSubstring(string s) {
       
        int i = 0 , j = 0 , n = s.size(), max_len = 0 ,frequencies [26] = {0};
        for(int j = 0 ; j < n ; j++)
        {
            int c = s[j] - 'a';
            frequencies[c]++;
            while(frequencies[c] > 2)
            {
                frequencies[s[i] - 'a']--;
                i++;
            }
            max_len = max(max_len, j - i + 1);
        } 
        return max_len;
    }
};

int main()
{
    string s = "adaddccdb";
    //cout<<s.find_first_of('b', 1);
    Solution sol;
   
    cout<<sol.maximumLengthSubstring(s);

}