#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<limits>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        string window ; int count = 0 , size = s.size() , k = 3;
    
       for(int i = 0 ; i <= size - k; i++)
       {
        if(s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) count++;
       }
       return count;
    }
};


int main()
{
    string s = "aababcabc";
    Solution sol;
    cout<<sol.countGoodSubstrings(s);
}    /*for(int i = 0 ; i < 3; i++) {window.push_back(s[i]);}
        if(window.size() == 3) count++;
        int i = 0 , end = 3;
        for(int i = 0 ; i < size - 3; i++)
        {
            window.erase(s[i]); if(!window.count(s[end])) count++;
            window.insert(s[end]);
            i++; end++;
        }
        return count;
        */
       