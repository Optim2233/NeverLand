#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int first_Pointer = 0, second_Pointer = 1;
        while(first_Pointer < s.size() && second_Pointer < s.size())
        {
            swap(s[second_Pointer] , s[first_Pointer]);
            first_Pointer += 2*k; second_Pointer += 2*k;
        }
        return s;
    }
};
int main()
{
    Solution sol;
    string s = "";
    s = sol.reverseStr(s,3);
    cout<<s;
    return 0;
}