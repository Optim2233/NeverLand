#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
       if( x < 0 || ( x % 10 == 0 && x != 0)) return false;
       int reverted = 0;
       while(x > reverted)
       {
        reverted = reverted * 10 + x % 10;
        x /= 10;
       }
       return (x == reverted || x==reverted/10)? true : false;
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