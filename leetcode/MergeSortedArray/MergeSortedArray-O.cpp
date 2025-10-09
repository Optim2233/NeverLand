#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lastValid = m - 1;

        for (int j = 0; j < n; j++) {
            int index = 0;
            while (index <= lastValid && nums1[index] <= nums2[j]) index++;

            for (int z = lastValid + 1; z > index; z--) {
                nums1[z] = nums1[z - 1];
            }
            nums1[index] = nums2[j];
            lastValid++;
        }
    }
};

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    for (int x : nums1) cout << x << " ";
    return 0;
}
