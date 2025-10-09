#include<iostream>
#include<cmath>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution 
{
    public: 
        bool isHappy(int num)
        {
            const unordered_set<int> unhappy = {4, 16, 37, 58, 89, 145, 42, 20};
            while( num != 1 && !unhappy.count(num))
            {
                int sum = 0 ; 
                while (num)
                {
                    int d = num % 10;
                    sum += d*d;
                    num/=10; 
                }
                num = sum;
                
            }
            return num == 1;
        }
};

int main()
{
    int num = 19;
    Solution sol;
    cout<<boolalpha<<(sol.isHappy(num))? "true" : "false";
}