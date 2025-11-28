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
    int findLength(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size(), m = nums2.size();
       int First_Pointer_Right = 0 , Second_Pointer_Left = 0; int count = 0;
       while(First_Pointer_Right < n)
       {
        if(nums1[First_Pointer_Right == nums2[Second_Pointer_Left]])
        {
            count++;
            Second_Pointer_Left++;
        }
            First_Pointer_Right++;
       }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {333}; int k = 1;


}