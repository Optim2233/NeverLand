#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) 
    {
        vector<int> V;
        int e = 0 , First_Pointer = 0, Previous_C = -1;
        while(e < s.size())
        {
            while( e < s.size() && s[e] != c) e++;
            if(e == s.size()) break;
            while(First_Pointer <= e )
            {
                if(Previous_C == -1) V.push_back(abs(First_Pointer - e));
                else
                    V.push_back(min(abs(First_Pointer - e), abs(First_Pointer - Previous_C)));
                First_Pointer++;
                
            }
            Previous_C = e; e++;
        }    
        while(First_Pointer < s.size())
        {
            V.push_back(abs(First_Pointer - Previous_C));
            First_Pointer++;
        }
        return V;
    }
};
int main()
{
    string s = "ab"; char c = 'a';
    Solution sol;
    vector<int> v = sol.shortestToChar(s,c);
    for(int i : v) cout<<i<<" ";
    return 0;
}