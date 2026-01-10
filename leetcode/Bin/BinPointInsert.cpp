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
    vector<int> sortedArr = {0,1,2,7,8,9};
    for(int i : sortedArr) cout<<i<<" "; cout<<endl;
    int n = sortedArr.size(), left = 0, right = n-1;
    int TbIn = 7, pos = 0;
    while(left <= right)
    {
        int m = (left + right)/2;
        if(sortedArr[m] == TbIn)
        {
            cout<<"Insert Position found"<<endl;
            break;
        }
        else if (sortedArr[m] < TbIn)
        {
            left = m + 1;
        }
        else{
            right = m - 1;
        }
        
    }
    pos = left; cout<<pos<<endl;
    sortedArr.resize(n+1); n++;
    cout<<n<<endl;
    for(int i = n - 1; i > pos; i--)
    {
        sortedArr[i] = sortedArr[i-1];
    }
    sortedArr[pos] = TbIn;

    for(int i : sortedArr)cout<<i<<" ";
}   

