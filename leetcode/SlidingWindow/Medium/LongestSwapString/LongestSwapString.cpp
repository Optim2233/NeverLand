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
    int maxRepOpt1(string text) {
        int n = text.size();
        int ans = 0, length;
        for(auto ch = 'a'; ch <='z'; ch++)
        {
            int right = 0, left = 0, zero_count = 0;

            while(right < n)
            {
                if(text[right] != ch) zero_count++;

                while(zero_count > 1)
                {
                    if(text[left] != ch) zero_count--;
                    left++;
                }
            }
            ans = max(ans, min(right - left, (int)count_if(text.begin(), text.end(), [&](char ch1) { return ch1 == ch; })));
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    string s = "ababa";
    cout<<sol.maxRepOpt1(s);

}