#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<limits>
#include <chrono>
#include <windows.h>
#include <psapi.h>

using namespace std;//not sliding window

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int s = code.size();
        vector<int>decrypted;

        for(int i = 0; i < s; i++)
        {
            if(k == 0)
            {
                decrypted.push_back(0);
            }
            else if(k > 0)
            {
                int sum = 0;
                for(int j = i + 1; j <= i+k; j++)
                {
                    sum += code[j % s];
                }
                decrypted.push_back(sum);
            }
           else
            {
                int sum = 0;
                for(int j = i - 1; j >= i+k; j--)
                {
                    sum += code[(j + s) % s];
                }
                decrypted.push_back(sum);
            }
        }
        return decrypted;
    }
};


int main()
{
    vector<int> nums = {2,4,9,3}; int k = -2;
    Solution sol; nums = sol.decrypt(nums, k);
    for( int i : nums)
    {
        cout<<i<<" ";
    }

}