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
class NumArray {
public:
    vector<int> prefix ;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix = nums;
        for(int i = 1; i < n; i++)
        {
            prefix[i] += prefix[i-1];
        }

    }
    
    int sumRange(int left, int right) {
        if (left == 0) return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};

int main()
{

}