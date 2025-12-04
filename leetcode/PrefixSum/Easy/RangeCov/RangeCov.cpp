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
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
int n = ranges.size(); int min_num = ranges[0][0], max_num = ranges[0][1];
    for(int i = 0 ; i < n; i++)
    {
        min_num = min(min_num, ranges[i][0]);
        max_num = max(max_num, ranges[i][1]);
    }
    vector<int> rangeLine(max_num - min_num + 2, 0);
    if(left < min_num || right > max_num) return false;
    for(int i = 0; i < n; i++)
    {
        rangeLine[ranges[i][0] - min_num] += 1;
        rangeLine[ranges[i][1] + 1 - min_num] -= 1;
    }
        

    for(int i = 1; i < rangeLine.size();i++)
    {
        rangeLine[i] += rangeLine[i-1];
    }
    for(int i = left; i <= right; i++)
    {
        if(rangeLine[i - min_num] <= 0 ) return false;
    }
    return true;

    }
};
int main()
{
    
    vector<vector<int>> ranges =  {{1,50}};
   int n = ranges.size(); int min_num = ranges[0][0], max_num = ranges[0][1]; int left =2 , right = 5;
    for(int i = 0 ; i < n; i++)
    {
        min_num = min(min_num, ranges[i][0]);
        max_num = max(max_num, ranges[i][1]);
    }
    vector<int> rangeLine(max_num - min_num + 2, 0);
    if(left < min_num || right > max_num) return false;
    for(int i = 0; i < n; i++)
    {
        rangeLine[ranges[i][0] - min_num] += 1;
        rangeLine[ranges[i][1] + 1 - min_num] -= 1;
    }
    for(int i : rangeLine) cout<<rangeLine[i]<<" "; cout<<endl;
    for(int i = 1; i < rangeLine.size();i++)
    {
        rangeLine[i] += rangeLine[i-1];
    }
    for(int i : rangeLine) cout<<rangeLine[i]<<" "; cout<<endl;
    for(int i = left; i <= right; i++)
    {
        if(rangeLine[i] <= 0 ) return false;
    }
    return true;

    
    for(int i : rangeLine) cout<<rangeLine[i]<<" ";
        cout<<endl;
        cout<<min_num<<max_num;
    return 0;
}