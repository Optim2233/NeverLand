#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        bool r = true;
        int left = 0, right = s.size()-1;
        
        while(left < right)
        {
            if(s[left] == s[right])
            {
                left++; right--;
                
            }else{return R1Check(s,left+1,right) || R1Check(s,left,right-1);}
            
        }
        return true;
    }
    private: 
    bool R1Check(const string& s,int l , int r)
    {
        while(l < r)
        {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
};
int main()
{
    string s = "abca";
    Solution sol;
    cout<<boolalpha<<sol.validPalindrome(s);
    return 0;
}