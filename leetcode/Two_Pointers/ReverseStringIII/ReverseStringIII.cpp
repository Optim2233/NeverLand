#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, n = s.size();
       for(j; j <= n; j++)
       {
        if(s[j] == ' ' || j == n)
        {
            reverse(s.begin()+i, s.begin()+j);
            i = j+1; 
        }
       }
       return s;
    }
};
int main()
{
    Solution sol;
    string s = "Mr Ding";
    s = sol.reverseWords(s);
    cout<<s;
}