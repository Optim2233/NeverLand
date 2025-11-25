#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include<cmath>

using namespace std;
class Solution {
public:
    int divisorSubstrings(int num, int k) { 
        int count = 0;
        int s = (num == 0)? 1: floor(log10(abs(num))) + 1;
        int arr[s]; int temp = num;
        for(int i = s -1; i >= 0 ; i--) {arr[i] = temp % 10; temp /= 10;};
         int inte = 0; for( int i = 0 ; i < k ; i++){ inte *= 10; inte += arr[i]; }
        if(inte != 0 && num % inte == 0)  count++;
        for(int i = 0 ; i < s - k ; i++)
        {
            inte -= arr[i] * pow(10, k-1);
            inte = inte * 10 + arr[i + k];
            if(inte != 0 && num % inte == 0)  count++;
        }
        return  count ;
    }           
};


int main() 
{
    Solution sol;
     int k = 2, num = 430043;
     cout<<sol.divisorSubstrings(num,k);
    return 0;
}
