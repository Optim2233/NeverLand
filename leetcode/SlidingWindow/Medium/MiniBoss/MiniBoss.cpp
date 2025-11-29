#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<limits>
#include<numeric>
#include<cstring>//will comeback later after prefix
using namespace std;
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        int First_Window_right = 0 , First_Window_left = 0, First_sum = 0, Max_First_Sum = 0;
        int Second_Window_right = 0 ,Second_Window_left = 0 , Second_sum = 0 , Max_Second_Sum = 0;
        int tot_max = 0, Max_Left_Pos = 0, Max_Right_Pos = 0;
        while(First_Window_right < n)
        {
            
            First_sum += nums[First_Window_right];
            if(Max_First_Sum <= First_sum )
            {
                Max_First_Sum = max(Max_First_Sum, First_sum);
                Max_Left_Pos = First_Window_left;
                Max_Right_Pos = First_Window_right;
            }
            while(First_Window_right - First_Window_left +1 >= firstLen)
            {
                First_sum -= nums[First_Window_left];
                First_Window_left++;
            }
            
            First_Window_right++;
        }
        if(Max_Left_Pos - Second_Window_left + 1 >= secondLen)
        {
            while(Second_Window_right < Max_Left_Pos)
            {
                
                Second_sum +=nums[Second_Window_right];
                Max_Second_Sum = max(Max_Second_Sum, Second_sum);
                tot_max = max(tot_max, Max_First_Sum + Max_Second_Sum);
                while(Second_Window_right - Second_Window_left + 1 >= secondLen)
                {   
                    Second_sum -= nums[Second_Window_left];
                    Second_Window_left++;
                }
                Second_Window_right++;
            }
        }
        Second_sum = 0;
        if (n - 1 - Second_Window_left + 1 >= secondLen)
        {
            Second_Window_right = Max_Right_Pos  + 1 ;
            Second_Window_left = Second_Window_right;
            while(Second_Window_right < n)
            {
                Second_sum +=nums[Second_Window_right];
                Max_Second_Sum = max(Max_Second_Sum, Second_sum);
                tot_max = max(tot_max, Max_First_Sum + Max_Second_Sum);
                while(Second_Window_right - Second_Window_left + 1 >= secondLen)
                {   
                    Second_sum -= nums[Second_Window_left];
                    Second_Window_left++;
                }
                Second_Window_right++;
            }
        }
        
        return tot_max;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {4,5,14,16,16,20,7,13,8,15}; int first_len = 3, second_len = 5;
    cout<<sol.maxSumTwoNoOverlap(nums,first_len,second_len);

}