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

class MyCalendarTwo {
public:
    map<int,int> lis;
    
    bool book(int startTime, int endTime) {
        int running  = 0;
        lis[startTime]++;
        lis[endTime]--;
        for(map<int,int>::iterator it = lis.begin(); it != lis.end(); it++)
        {   
            running += it->second;
            if(running > 2)
            {
                lis[startTime]--;
                lis[endTime]++;
                if(lis[startTime] == 0) lis.erase(startTime);
                if(lis[endTime] == 0) lis.erase(endTime);
                return false;
            }
        }
        return true;
    }
};

int main()
{    
        int startTime = 10, endTime = 20;
        map<int,int> lis;int running  = 0;
        lis[startTime]++;
        lis[endTime]--;
        for(map<int,int>::iterator it = lis.begin(); it != lis.end(); it++)
        {   
            running += it->second;
            if(running > 2)
            {
                cout<<"false"<<endl;
                break;
            }
        }
}   

