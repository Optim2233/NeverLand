#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<climits>
#include<limits>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size(), count = 0;

        for(int i = 0 ; i < n ; i++)
        {
            if(colors[i] != colors[(i - 1 + n) % n] && colors[i] != colors[(i + 1) % n]) count++;
        }
        return count;
    }
};

int main()
{
     vector<int> colors = {1,1,1}; 
    Solution sol;
    cout<<sol.numberOfAlternatingGroups(colors);
}