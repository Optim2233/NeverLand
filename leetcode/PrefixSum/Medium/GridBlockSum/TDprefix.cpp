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
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
            int r = mat.size();
            int c = mat[0].size();
            vector<vector<int>> PS;
            PS.assign(r+1, vector<int>(c+1,0));
            vector<vector<int>> ans (r, vector<int>(c));
            for(int i = 1; i <= r; i++)
            {
                for(int j = 1; j <= c ; j++)
                {
                    PS[i][j] = mat[i-1][j-1] + PS[i-1][j] + PS[i][j-1] - PS[i-1][j-1];
                }
            }
           for(int i = 0; i < r ; i++)
           {
                for(int j = 0; j < c ; j++)
                {
                    int row1 = max(0, i -k);
                    int col1 = max(0, j - k);
                    int row2 = min(r-1,i + k);
                    int col2 = min(c -1, j + k);
                    row1++; col1++; row2++; col2++;
                    ans[i][j] = PS[row2][col2] - PS[row2][col1 -1 ] - PS[row1-1][col2] + PS[row1-1][col1-1];

                }
           }
            
            return ans;
    }
};

int main()
{
    // 3x3 grid with values 1..9
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Solution sol;
    grid = sol.matrixBlockSum(grid,2);
    int r = grid.size();
    int c = grid[0].size();
     for(int i = 0; i < r; i++)
      {
        for(int j = 0; j < c ; j++)
        {
          cout<<grid[i][j]<<" ";
        }
        cout<<endl;
       }


}   

