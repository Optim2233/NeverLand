#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int First_Pointer = 0, Second_Pointer = 0;
        int x = 0, y = 0,sum = 0;
        while(Second_Pointer < s.size())
        {
            while(Second_Pointer < s.size()&& s[Second_Pointer] == s[First_Pointer]) Second_Pointer++;
            y = x;
            x = Second_Pointer-First_Pointer;
            sum += min(x,y);
            First_Pointer = Second_Pointer;
        }
        return sum;
    }
};
int main()
{
    string s = "0000111100001111";
    Solution sol;
    cout<<sol.countBinarySubstrings(s);
    return 0;
}