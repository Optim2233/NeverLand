#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution 
{
    public: 
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {       
        vector<int> a;int i = 0 , j = 0, n = nums1.size(), m = nums2.size();
        sort(nums1.begin(), nums1.end()); sort(nums2.begin(), nums2.end());
        a.reserve(min(n,m));
        while( i < n && j < m)
        {
            if(nums1[i] == nums2[j]){a.push_back(nums1[i]); i++; j++;}
            else if(nums1[i] < nums2[j]) i++;
            else {j++;}
        }
        return a;
    }

};

int main()
{
    vector<int> nums1 = {4,5,9,4,9}, nums2 = {4,4,8,9,9};
    Solution sol;
    vector <int> res = sol.intersect(nums1,nums2);
    for( int i : res) cout<<i<<" ";

}