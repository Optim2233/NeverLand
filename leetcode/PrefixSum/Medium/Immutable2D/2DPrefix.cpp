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

class NumMatrix {
     vector<vector<long long>> pref;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int R = static_cast<int>(matrix.size());
        if (R == 0) return;

        int C = static_cast<int>(matrix[0].size());
        pref.assign(R, vector<long long>(C, 0));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                long long val = matrix[i][j];
                if (j > 0) val += pref[i][j-1];
                if (i > 0) val += pref[i-1][j];
                if (i > 0 && j > 0) val -= pref[i-1][j-1];
                pref[i][j] = val;
            }
        }
    }   
    int sumRegion(int r1, int c1, int r2, int c2) {
        if (pref.empty()) return 0;

        long long up    = (r1 > 0) ? pref[r1-1][c2] : 0;
        long long left  = (c1 > 0) ? pref[r2][c1-1] : 0;
        long long diag  = (r1 > 0 && c1 > 0) ? pref[r1-1][c1-1] : 0;
        long long res   = pref[r2][c2] - up - left + diag;
        return static_cast<int>(res);
    }
};

int main()
{
     vector<vector<long long>> pref;
    vector<vector<int>> matrix = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
 int R = static_cast<int>(matrix.size());
       // if (R == 0) return;

        int C = static_cast<int>(matrix[0].size());
        pref.assign(R, vector<long long>(C, 0));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                long long val = matrix[i][j];
                if (j > 0) val += pref[i][j-1];
                if (i > 0) val += pref[i-1][j];
                if (i > 0 && j > 0) val -= pref[i-1][j-1];
                pref[i][j] = val;
            }
        }

        for(int i = 0 ; i < R ; i++)
        {
            for(int j = 0; j < C; j++)
            {
                cout<<pref[i][j]<<" ";
            }
            cout<<endl;
        }
    }   

