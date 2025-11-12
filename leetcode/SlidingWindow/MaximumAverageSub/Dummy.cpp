#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <chrono>
#include <windows.h>
#include <psapi.h>

using namespace std;
using namespace chrono;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int s = nums.size();
        double sum = 0;
        for (int j = 0; j < k; j++) sum += nums[j];

        double ans = sum;
        for (int i = k; i < s; i++) {
            sum += nums[i] - nums[i - k];
            ans = max(ans, sum);
        }
        return ans / k;
    }
};

// Function to get memory usage in MB (Windows)
size_t getMemoryUsageMB() {
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        return pmc.WorkingSetSize / (1024 * 1024); // bytes → MB
    }
    return 0;
}

int main() {
    // Example array
    //vector<int> nums = {-1}; 
    //int k = 1;
    vector<int> nums(10000000, 1); // 10 million elements
    int k = 1000;

    auto start = high_resolution_clock::now();

    Solution sol;
    double result = sol.findMaxAverage(nums, k);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Result: " << result << endl;
    cout << "Time: " << duration.count() << " ms" << endl;
    cout << "Memory used: " << getMemoryUsageMB() << " MB" << endl;

    return 0;
}
