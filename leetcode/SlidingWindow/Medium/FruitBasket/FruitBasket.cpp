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
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> window;
        int right = 0, left = 0, ans = 0;   
        while(right < n)
        {
            window[fruits[right]]++;
            while(left < right && window.size() > 2)
            {
                window[fruits[left]]--;
                if(window[fruits[left]] == 0) window.erase(fruits[left]);
                left++;
            }
            
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }   
};
int main()
{
    Solution sol;
    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout<<sol.totalFruit(fruits);


}