#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution 
{
    public: 
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> seen(nums1.begin(), nums1.end());        
        vector<int> Intersection;
        for(int i = 0 , n = nums2.size()-1; i <= n; i++)
        {
            if(seen.count(nums2[i]) && (find(Intersection.begin(), Intersection.end(),nums2[i])) == Intersection.end())
            {
                Intersection.push_back(nums2[i]);
            }
            else{continue;}
        }
        return Intersection;
        }

};

int main()
{
    vector<int> nums1 = {4,9,5}, nums2 = {9,4,9,8,4};
    Solution sol;
    vector <int> res = sol.intersection(nums1,nums2);
    for( int i : res) cout<<i<<" ";

}