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
        int numberOfPoints(vector<vector<int>>& nums) {
            int n = nums.size(), min_num = nums[0][0], max_num = nums[0][1];
            for(int i = 0; i < n; i++)
            {
                min_num = min(min_num,nums[i][0]);
                max_num = max(max_num,nums[i][1]);
            }
            vector<int> PS(max_num - min_num + 2, 0);
            for(int i = 0; i < n; i++)
            {
                PS[nums[i][0] - min_num]++;
                PS[nums[i][1] - min_num + 1]--; 
            }
            for(int i = 1; i < PS.size(); i++)
            {
                PS[i] += PS[i-1];
            }
            int count = 0;
            for(int i = 0 ; i < PS.size(); i++)
            {
                if(PS[i] > 0) count++;
            }
            return count;
        }
    };

    int main()
    {
        Solution sol;
        vector<vector<int>>nums = {{3,6},{1,5},{4,7}};
        int n = sol.numberOfPoints(nums);
        cout<<n<<" ";
        
    }