#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<limits>
#include<numeric>
#include<cstring>
using namespace std;
class Solution {
public:
    bool scoreBalance(string str) {
    int s = str.size();
    vector<int> Pre(s);
    for(int i = 0 ; i < s ; i++)
    {
        Pre[i] = str[i] - 'a' + 1;
    }
    for(int  i = 1; i < Pre.size(); i++)
    {
        Pre[i] += Pre[i-1];
    }
    for(int  i = 0; i < Pre.size(); i++)
    {
        int left = Pre[i];
        int right = Pre[s-1] - Pre[i];
        if(left == right) return true;
    }
    return false;        
    }
};


int main()
{
     string str = "adcb";
    int s = str.size();
    vector<int> Pre(s);
    for(int i = 0 ; i < s ; i++)
    {
        Pre[i] = str[i] - 'a' + 1;
    }
    for(int  i = 1; i < Pre.size(); i++)
    {
        Pre[i] += Pre[i-1];
    }
    for(int  i = 0; i < Pre.size(); i++)
    {
        int left = Pre[i];
        int right = Pre[s-1] - Pre[i];
        if(left == right) return true;
    }
    return false;
    for(int i : Pre) cout<<i<<" ";
}