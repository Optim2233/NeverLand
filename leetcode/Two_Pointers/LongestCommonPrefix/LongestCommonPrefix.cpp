#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
    public: 
    string LongestCommonPrefix(vector<string>& strs){
        if(strs.empty())return "";
        for(int i = 0 ; i <strs[0].size(); i++)
        {
            char c = strs[0][i];
            for(int j = 0 ; j < strs.size(); j++)
            {
                if ( c != strs[j][i] ) return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};
int main()
{

}