#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> Palin;
        if(x < 0)return false;
        while(x > 0)
        {
            Palin.push_back( x % 10);
            x /= 10;
        }
        for(int i = 0 ; i < (Palin.size()/2); i ++)
        {
            if(Palin[i] != Palin[Palin.size() - 1 - i]) return false;
        }
        return true;
    }
};
int main()
{   
    Solution sol;
    int x = 121, y =123, z =-121;
    cout<<(sol.isPalindrome(x))? true : false; cout<<endl;
    cout<<(sol.isPalindrome(y))? true : false; cout<<endl;
    cout<<(sol.isPalindrome(z))? true : false; cout<<endl;

    
}