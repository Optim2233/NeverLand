#include<iostream>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
        int romanToInt(string s) 
        {
            static const unordered_map<char,int> R2I = { {'I', 1}, {'V',5}, {'X', 10} , {'L',50}, {'C',100}, {'D', 500}, {'M',1000}};
            int total = 0;
            for(int i = 0 ; i < s.size(); i++)
            {
                int value = R2I.at(s[i]);
                if(i + 1 < s.size() && R2I.at(s[i+1]) > value)
                {
                    total -= value;
                }
                else total += value;
            }
            return total;
        }
};
int main()
{

}