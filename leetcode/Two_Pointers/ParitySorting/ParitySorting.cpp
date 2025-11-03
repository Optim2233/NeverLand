#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0 , right = nums.size()-1;
        while( left < right)
        {
            while ( left < right && (nums[left]) % 2 == 0) left ++ ;
            while ( left < right && (nums[right]) % 2 == 1) right --;
            swap(nums[left++],nums[right--]);
        }
        return nums;
    }
};
int main()
{
    vector<int> V = {-3, -2, -1, 0, 1, 2};
    Solution sol;
    V = sol.sortArrayByParity(V);
    for(int i : V) cout<<i<<" ";
    return 0;
}