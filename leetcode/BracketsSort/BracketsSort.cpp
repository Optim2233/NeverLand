#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    bool isValid(string s)
    {
        vector<char> stack;
        if(s.size() % 2 == 1) return false;
        for( char ch : s)
        {
            switch(ch)
            {
                case '[': stack.push_back(']'); break;
                case '{' : stack.push_back('}'); break;
                case '(' : stack.push_back(')'); break;
                case ')' : 
                case '}' : 
                case ']' : if( !stack.empty() && ch == stack.back()) {stack.pop_back(); break;} else return false;
                default  : return false;
            }
        }
        return stack.empty();
    }
};
int main()
{
    Solution sol;
    string str = "()", stri = "(){}[]", strin = "({)}", strinG = "]]";
    cout<<(sol.isValid(strinG))? "true" : "false";cout<<endl;
    /*cout<<(sol.isValid(str))? "true" : "false"; cout<<endl;
    cout<<(sol.isValid(stri))? "true" : "false"; cout<<endl;
    cout<<(sol.isValid(strin))? "true" : "false";cout<<endl;*/
}