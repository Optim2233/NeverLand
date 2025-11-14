#include <iostream> // status: yet to be comprehended
#include <cmath>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int count = 0;
        int temp = num;

        // Step 1: count digits
        int digits = (num == 0) ? 1 : floor(log10(num)) + 1;
        if(digits < k) return 0;

        // Step 2: compute 10^(k-1)
        int mult = 1;
        for(int i = 1; i < k; i++) mult *= 10;

        // Step 3: get first k-digit number
        int firstPower = 1;
        for(int i = 0; i < digits - k; i++) firstPower *= 10;
        int inte = temp / firstPower;

        if(inte != 0 && num % inte == 0) count++;

        // Step 4: slide the window
        for(int i = digits - k - 1; i >= 0; i--) {
            int power = 1;
            for(int j = 0; j < i; j++) power *= 10;

            int nextDigit = (temp / power) % 10;
            inte = (inte % mult) * 10 + nextDigit;

            if(inte != 0 && num % inte == 0) count++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    int k = 2, num = 430043;
    cout << sol.divisorSubstrings(num, k) << endl;
    return 0;
}
