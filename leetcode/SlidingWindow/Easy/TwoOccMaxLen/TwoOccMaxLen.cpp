#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<climits>
#include<limits>
using namespace std;

/*class Solution {
public:
    int maximumLengthSubstring(string s) {
        int start = 0 ,end = 1, n = s.size(), len = 0 , max_len = 0;  bool SW = false; int bin = 0;
        unordered_set<int> seen;
        seen.insert(s[0]);
        while( start < n && end < n)
        {
            while(end < n && !(seen.count(s[end]) && SW)){  end++; if(seen.count(s[end])) SW = true; seen.insert(s[end]) ;}
            len = end - start-1;
            max_len = max(max_len, len);
            int Last_Seen_Char = s.find_first_of(s[end], start);
            while( start < end && start <= Last_Seen_Char) {seen.erase(s[start]);  start++;}
            SW = false;
            
        }
        return max_len;
    }
};*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> frequencies ;
        int i = 0 , j = 0 , n = s.size(), max_len = 0; 
        while( i < n && j < n)
        {
            frequencies[s[j]]++; 

            while(frequencies[s[j]] > 2)
            {
                frequencies[s[i]]--;
                i++;
            }  
            max_len = max(max_len, j - i + 1);     
            j++;
        }
        return max_len;
    }
};

int main()
{
    string s = "adaddccdb";
    //cout<<s.find_first_of('b', 1);
    Solution sol;
   
    cout<<sol.maximumLengthSubstring(s);

}