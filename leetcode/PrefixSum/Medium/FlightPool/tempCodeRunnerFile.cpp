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

int main()
{ 
    vector<vector<int>> bookings = {
        {1,2,10},
        {2,2,15}
    };
    int c = 2; vector<int> ans;
    int running = 0;
    int n = bookings.size(); int start = bookings[0][0] , end = bookings[0][1];
    for(int i = 0; i < n; i++)
    {
        start = min(start, bookings[i][0]);
        end = max(end,bookings[i][1]);
    }
    vector<int> flightLine(end+ c);

    for(int i = 0; i < n;i++)
    {
        flightLine[bookings[i][0]] += bookings[i][2];
        flightLine[bookings[i][1]+1] -= bookings[i][2];
    }

    for(int i = 1; i < flightLine.size() ; i++)
    {
        flightLine[i] += flightLine[i-1];
    }
    
    for(int i : flightLine) cout<<i<<" ";

    cout<<endl;
    for(int i : flightLine) cout<<i<<" ";
    cout<<endl;

     for(int i = 1; i < flightLine.size() - 1; i++)
    {
        cout<<flightLine[i]<<" ";
    }

   
}   

