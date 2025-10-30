#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) 
    {
        
        for(int i = 0; i < image.size(); i++)
        {
            int left = 0, right = image[i].size()-1;
            while(left < right)
        {
            swap(image[i][left] , image[i][right]);
            left++; right--;
        }
        }
        
        for(int row = 0 ; row < image.size(); row++)
        {
            for(int col = 0; col < image[row].size(); col++)
            {
                if(image[row][col] == 0) image[row][col] = 1;
                else if(image[row][col] == 1) image[row][col] = 0;
            }
        }
         return image;
    }
   
};

int main()
{
    vector<vector<int>> matrix = {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    Solution sol;
    matrix = sol.flipAndInvertImage(matrix);
    for(auto &row : matrix) {
        for(int val : row) cout << val << " ";
        cout << endl;
    }
}