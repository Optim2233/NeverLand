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
    int pivotInteger(int n) {
        int num = 0; 
        for(double i = 1; i <= n; i++)
        {
            double left_sum = i/2 * (1 + i);
            double right_sum = (n-i+1)/2 * (i+n);
            if(left_sum == right_sum) return i;
        }
        return -1;
        
    }
};
int main()
{
    Solution sol;
    vector<int>nums = {1,2,4,5}, queries = {0};//{1,3,7,12}
    cout<<sol.pivotInteger(8);
}