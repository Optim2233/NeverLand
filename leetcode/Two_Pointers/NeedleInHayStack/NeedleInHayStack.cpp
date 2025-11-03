#include<iostream>
#include<string>
using namespace std;

class Solution 
{
    public: 
    int strStr(string haystack , string needle)
    {   
        
        int needleLength = needle.size(); if(needleLength == 0) return -1;
        int haystackLength = haystack.size();
        for(int i = 0 ; i <= haystackLength - needleLength; i++)
        {
            if(haystack.substr(i,needleLength) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    string haystack = "a", needle = "a";
    Solution sol;
    cout<<sol.strStr(haystack,needle);

}