#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution
{
    public: 
     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
     {
        nums1.resize(m+n,INT_MAX);// nums1= { 1,2,3,M,M,M}  nums2 = {2,6,8}
        for(int j = 0 ; j < n; j++)
        {
               int index = 0;
            for(int i = 0 ; i < nums1.size(); i++)
            {
                if(nums2[j] >= nums1[i]) nums1[index++] = nums1[i];
                else if(nums2[j] < nums1[i]) 
                { 
                    for(int z = nums1.size()-1 ; z > index; z--)
                    {
                        nums1[z] = nums1[z-1];
                    }
                    nums1[index++] = nums2[j];
                    break;
                }
            }
        }
     }
};
int main()
{
    vector<int> nums1 = {}, nums2 = {1};
    int m = nums1.size(), n = nums2.size();
    Solution sol;
    sol.merge(nums1,m,nums2,n);
    for( int i : nums1)
    {
        cout<<i<<" ";
    }
    return 0;
}