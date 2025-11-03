#include<iostream>
#include<cmath>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution 
{
    public: 
        bool isHappy(int n)
        {
            const unordered_set<int> unhappy = {4, 16, 37, 58, 89, 145, 42, 20};
            while( n != 1 && !unhappy.count(n))
            {
                int sum = 0 ; 
                while (n)
                {
                    int d = n % 10;
                    sum += d*d;
                    n/=10; 
                }
                n = sum;
                
            }
            return n == 1;
        }
};

int main()
{
    int n = 4;
    Solution sol;
    cout<<boolalpha<<(sol.isHappy(n))? "true" : "false";
}