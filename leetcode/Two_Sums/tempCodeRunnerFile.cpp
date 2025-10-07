#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Fast path: negative numbers are not palindromes. Numbers ending with 0
        // are not palindromes unless the number is 0 itself.
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        // Reverse only half of the number to avoid overflow and unnecessary work.
        int reverted = 0;
        while (x > reverted) {
            reverted = reverted * 10 + x % 10;
            x /= 10;
        }

        // For even length numbers x == reverted. For odd lengths, ignore the middle digit by reverted/10.
        return x == reverted || x == reverted / 10;
    }
};
int main()
{   
    Solution sol;
    int x = 121, y =123, z =-121;
    // Use boolalpha to print `true`/`false` instead of 1/0
    cout << boolalpha;
    cout << sol.isPalindrome(x) << endl;
    cout << sol.isPalindrome(y) << endl;
    cout << sol.isPalindrome(z) << endl;

    
}