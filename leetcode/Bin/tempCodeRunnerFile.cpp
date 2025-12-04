#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<limits>
#include<numeric>
#include<cstring>
using namespace std;

int main()
{
    vector<int> nums = {1,3,8,48,10};
    int n = nums.size(); int max_len = 0;
        int right = 0, left = 0,bit_sum = 0;
        while(right < n)
        {   
            if(bit_sum & nums[right] != 0 )
            {
                while((bit_sum & nums[right]) != 0 )
                {
                    cout<<"BIT1: "<<bit_sum<<endl;
                    bit_sum ^= nums[left]; 
                    cout<<"BIT1: "<<bit_sum<<endl;
                    left++; 
                }
            }
            bit_sum |= nums[right];
            max_len = max(max_len, right - left  + 1);
            cout<<bit_sum<<" "<<max_len<<" "<<left<<" "<<right<<" "<<endl;
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            right++;
        }
        cout<<max_len;
}