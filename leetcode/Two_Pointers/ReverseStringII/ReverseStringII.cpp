#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            int left = i;
            int right = min(i + k - 1, n - 1);
            while (left < right) {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s = "abcd";
    cout << sol.reverseStr(s, 3) << endl;
    return 0;
}
