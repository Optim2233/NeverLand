#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> v ;
        int low = 0, high = s.size();
        for(int i = 0 ; low <= high ; i++)
        {
            if(s[i] == 'I'){v.push_back(low); low++;}
            else{v.push_back(high); high--;} 
        }
        return v;
    }
};
int main()  
{
    string s = "DDI";//IDID
    Solution sol;
    vector<int> v = sol.diStringMatch(s);
    for(int i : v) cout<<i<<" ";
    return 0;
}