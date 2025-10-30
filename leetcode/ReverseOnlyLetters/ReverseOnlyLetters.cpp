#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0 , right = s.size()-1;
        while(left < right)
        {
            while(left < right && !isalpha(s[left])) left++;
            while(left < right && !isalpha(s[right])) right --;
            swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main()
{
    string s = "esCa123de-xiM!";
    Solution sol;
    cout << sol.reverseOnlyLetters(s);
    return 0;
}