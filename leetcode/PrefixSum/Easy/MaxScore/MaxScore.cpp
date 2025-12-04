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
    int maxScore(string s) {
        int n = s.size(), left = 0, right = 0 , best = 0;
        vector<int> PS(n);
        PS[0] = s[0] - '0';
        
        for(int i = 1; i < n; i++)
        {
            PS[i] += PS[i-1] + (s[i] - '0');
        }
        for(int i = 0; i < n - 1; i++)
        {
            left = (i+1) - PS[i];
            right = PS[n-1] - PS[i];
            best = max(best,left+ right);
        }
        return best;
    }
};
int main()
{
    Solution sol;
    string str = "011101";
    cout<<sol.maxScore(str);
    
}