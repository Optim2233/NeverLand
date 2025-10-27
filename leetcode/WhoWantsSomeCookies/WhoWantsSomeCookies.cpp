#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); sort(s.begin(), s.end());
        int first_pointer_G = 0, second_pointer_S = 0, counter = 0;
        while(first_pointer_G < g.size() && second_pointer_S < s.size())
        {
            while(second_pointer_S < s.size() && s[second_pointer_S] < g[first_pointer_G]) second_pointer_S++;
            if((second_pointer_S < s.size())&& s[second_pointer_S] >= g[first_pointer_G]){
                counter++;
            }
            first_pointer_G++; second_pointer_S++; 
        }
        return counter;
    }
};
int main()
{
    Solution sol;
    vector<int> g = {1,1,2,3,7}; vector<int> s = {50,50,50};
    int res = sol.findContentChildren(g,s);
    cout<<"SOL "<<res;
    return 0;
}