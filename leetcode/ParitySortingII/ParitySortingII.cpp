#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int left = 0 , right = nums.size()-1;
        while(left < nums.size())
        {
            while(left < nums.size() && (left % 2 == 0 && nums[left] % 2 == 0)) left += 2;
            while(right > 0 && (right % 2 == 1 && nums[right] % 2 == 1)) right -= 2;
            if(left < nums.size() && right > 0) swap(nums[left], nums[right]); left += 2; right -= 2;
            
        }
        return nums;
    }
};
int main()
{
    vector<int> V = {2,4,6,8,1,3,5,7};
    Solution sol;
    V = sol.sortArrayByParityII(V);
    for( int i : V) cout<<i<<" ";
    return 0;

}