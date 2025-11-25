#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<climits>
#include<limits>
#include<numeric>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), max_len = INT_MIN, left = 0 ;
        {
            for(left; left < n ; left++)
            {
            int Gcd = nums[left]; 
            int Lcd = nums[left];
            int Prd = nums[left];
            int right = left+1;
            while(right <= n - 1)
            {
                Gcd = gcd(Gcd, nums[right]);
                Lcd = lcm(Lcd, nums[right]);
                Prd = Prd * nums[right];
                if(Prd == Gcd * Lcd) {max_len = max(max_len ,( right - left+1)); right++;}
                else{break;}
                
            }
            }
        }
        return max_len;
    }
};
int main()
{
    vector<int> nums = {2,3}; int   k = 6, x = 2;
    Solution sol; 
    cout<<sol.maxLength(nums);

}