#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution 
{
    public:
        void reverseString(vector<char>& s)
        {
            for(int i = 0, n = s.size(); i < n/2 ; i++)
            {
                swap(s[i], s[s.size()-1-i]);
            }
        }
};
int main()
{
    vector<char> s = {'h','e','l','l','o'};
    Solution sol;
    sol.reverseString(s);
    for(char c : s)
    {
        cout<<c<<" ";
    }

}