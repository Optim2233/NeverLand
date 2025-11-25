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
        vector<int>decrypted(s,0);
        if(k == 0) return decrypted;
        int sum = 0, start, end;
        if(k > 0)
        {
            for(int i = 1; i <= k; i++)
            {
                sum += code[i  %  s];
            }
            decrypted[0] = sum;
            start = 1; end = k+1;
            for(int i = 1; i < s; i++)
            {
                sum -= code[start];
                sum += code[end % s];
                decrypted[i] = sum;
                start ++; end++;
            }
        }
        else 
        {
            k = -k;
            for(int i = s - k; i < s; i++)  
            {
                sum += code[i]; 
            }
            decrypted[0] = sum;
            start = s - k;
            end = 0;
            for(int i = 1 ; i < s; i++)
            {
                sum -= code[start % s];
                sum += code[end % s];
                decrypted[i] = sum;
                start ++; end++;
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