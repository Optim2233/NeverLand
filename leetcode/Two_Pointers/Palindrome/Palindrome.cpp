#include<iostream>
#include<string>
#include<cctype>
using namespace std;

class Solution
{
    public: 
        bool isPalindrome   (string s)
        {
            if(s == " ") return true;
            int j = 0;
            for(int i = 0 ; i < s.size(); i++)
            {
                if(isalnum(s[i])) s[j++] = tolower(s[i]);
                else{continue;}
            }
            s.resize(j);
            for(int i = 0 ; i < j/2; i++)
            {
                if(s[i] != s[j-1-i]) return false;
            }
            return true;
        }
};
int main()
{
    string s = "A man, a plan, a canal: Panama";
    Solution sol;
    cout<<(sol.isPalindrome(s))? "true" : "false";
    return 0;
}