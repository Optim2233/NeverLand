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
        
        int n = colors.size() ,  first = colors[0], last = colors[n-1], count = 0;
        for(int i = 1 ; i < n - 1; i++)
        {
            if(colors[i] != colors[i-1] && colors[i] != colors[i+1]) count++;
        }
        if(first != last && first != colors[1]) count++;
        if(last != first && last != colors[n-2]) count++;
        return count;
    }
};

int main()
{
     vector<int> nums = {0,1,0,0,1}; 
    Solution sol;
    cout<<sol.numberOfAlternatingGroups(nums);
}