#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s = "abcdefgh";
    cout << sol.reverseStr(s, 3) << endl;
    return 0;
}
