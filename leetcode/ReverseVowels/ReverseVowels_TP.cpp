#include<iostream>
#include<vector>
#include<unordered_set>
#include<cctype>
using namespace std;

class Solution 
{
    public:
        string reverseVowels(string s)
    {
        int left = 0, right = s.size() - 1;
        unordered_set<char> vowels = {'a', 'e' , 'i' ,'o', 'u'};
        while(left < right)
        {
            while((left < right) && !vowels.count(tolower(s[left]))) left++;
            while((left < right) &&!vowels.count(tolower(s[right]))) right--;
            swap(s[left],s[right]);
            left++; right--;
        }
        return s;
    }
};
int main()
{
    string s = "LeetCode";
    Solution sol;
    cout<<sol.reverseVowels(s);
}