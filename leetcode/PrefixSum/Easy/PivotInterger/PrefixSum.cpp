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
        int num = 0; vector<int> Prefix(n,1);
        if(n==1) return 1;
        int running = 0;
        for(int i = 1 ; i <= n;i++)
        {
            running+= i;
            Prefix[i-1] = running;
        }

        int left_sum = 0, right_sum = 0, m = Prefix.size();
        for( int i = 1; i < m; i++)
        {
            left_sum = Prefix[i];
            right_sum = Prefix[m-1] - Prefix[i - 1];
            if(left_sum == right_sum) return i+1;
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