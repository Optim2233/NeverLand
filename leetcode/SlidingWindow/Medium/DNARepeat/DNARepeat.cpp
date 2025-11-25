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
     vector<string> DNAcurrent_repeat(string s)
     {
        vector<string> res;unordered_map<string,int> freq;
        int n = s.size(), k = 10;
        for(int left = 0; left + k <=  n; left++)
        {
            string sub = s.substr(left, k);
            freq[sub]++;
            if(freq[sub] == 2) res.push_back(sub);
        }
        return res;
     }
};


int main()
{
    string s = "AAAAACCCCCAAAAACCCCC";
    vector<string>res;
    Solution sol;
    res = sol.DNAcurrent_repeat(s);
    for(string i : res)
    {
        cout<<i<<" ";
    }
    
}