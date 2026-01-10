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
#include<map>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size(); long long running = 0;
        for(int i = n-1; i >= 0; i--)
        {
            running += shifts[i];
            s[i] = (s[i] - 'a' + running % 26 ) % 26 + 'a';

        }
        return s;
    }
};
int main()
{    
    string s = "abc"; vector<int>shifts = {3,5,9};
    int n = s.size(), running = 0;
    for(int i = n-1; i >= 0; i--)
    {
        running += shifts[i];
        s[i] += running;
    }   
    cout<<s;
}   

