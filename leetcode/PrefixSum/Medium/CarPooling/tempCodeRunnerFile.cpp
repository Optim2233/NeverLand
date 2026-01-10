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
#include<map>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> lis;
        int n = nums.size(),running = 0,count = 0; lis[running]++;
        for(int i = 0; i < n; i++)
        {
            running += nums[i];
            int mod = ((running % k)+k) % k;
            if(lis.count(mod))
            {
                count += lis[mod];
            }
            lis[mod]++;
        }
        return count;
    }
};
int main()
{ 
    vector<vector<int>> trips = {
        {2, 1, 5},
        {3, 3, 7}
    };
    int capacity = 5;
    map<int,int> lis; int running = 0; 
    int n = trips.size();
    for(int i = 0; i < n; i++)
    {
        lis[trips[i][1]] = trips[i][0];
        lis[trips[i][2]] = -trips[i][0];
    }
    for(map<int,int>::iterator it = lis.begin(); it != lis.end(); it++)
    {
        running += it->second;
        cout<<"Current Passenger Numbers :"<<running<<endl;
        if(running > capacity)
        {
            cout<<"Passenger overflow"<<endl;
            
        }
    }
    cout<<"Destination arrived successfully"<<endl;


}   

