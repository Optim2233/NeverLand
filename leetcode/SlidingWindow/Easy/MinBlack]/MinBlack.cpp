#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<limits>
using namespace std;


class Solution {
public:
    int minimumRecolors(string blocks, int k) {
    
        int c = 0, n = blocks.size() , min_c = 0;
        for(int i = 0; i < k; i++) if(blocks[i] == 'W') c++; min_c = c;
        if(n > 1)
        {
            for(int i = 0; i < n- k; i++)
            {
                if(blocks[i] == 'W') c--;
                if(blocks[i + k] == 'W') c++;
                min_c = min(c, min_c);
            }
        }
        
        return min_c;
    }
};

int main()
{
    string blocks = "BWBBWWBBBWBWWWBWWBBWBWBBWBB"; int k = 11;
    Solution sol;
    cout<<sol.minimumRecolors(blocks,k);
}