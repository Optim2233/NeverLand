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
    int  maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size(); 
        int min_year = logs[0][0], max_year = logs[n-1][1];
        for(int i = 0; i < logs.size(); i++)
        {
                min_year = min(min_year, logs[i][0]);
                max_year = max(max_year, logs[i][1]);
        }
        vector<int>timeline(max_year-min_year + 1);
        for(int i = 0; i < n; i++)
        {
            timeline[logs[i][0] - min_year] += 1;
            timeline[logs[i][1] - min_year] -= 1;
        }
        int max_ele = max(timeline[0], 0), early_pos = 0;
        for(int i = 1; i < timeline.size(); i++)
        {
        timeline[i] += timeline[i-1];
        if(max_ele < timeline[i])
            {
                max_ele = max(max_ele, timeline[i]);
                early_pos = i;
            }
        }
        
        return early_pos + min_year;
    }
};
int main()
{
    Solution sol;
    vector<vector<vector<int>>> tests = {
        {{1950,1961},{1960,1971},{1970,1981}},    // sample
        {{1960,1971},{1950,1961},{1970,1981}},    // same as sample but unsorted
        {{1990,1991}},                            // single person
        {{2000,2005},{2005,2010}},                // adjacent intervals
        {{2000,2001},{1990,2003}}                 // unsorted, wider span
    };

    for(size_t t = 0; t < tests.size(); ++t) {
        int ans = sol.maximumPopulation((vector<vector<int>>& )tests[t]);
        cout << "Test " << t+1 << " -> result: " << ans << endl;
    }

    return 0;
}