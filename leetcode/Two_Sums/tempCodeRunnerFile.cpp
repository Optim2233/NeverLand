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
        for (size_t i = 0; i < s.size(); ++i) {
            char ch = s[i];
            switch (ch) {
            case '[': stack.push_back(']'); break;
            case '{': stack.push_back('}'); break;
            case '(' : stack.push_back(')'); break;

            case ')':
            case '}':
            case ']':
                if (stack.empty() || stack.back() != ch) return false;
                stack.pop_back();
                break;
            default:
                return false;
            }
        }

        return stack.empty();
    }
};
int main()
{
    Solution sol;
    string str = "()", stri = "(){}[]", strin = "({)}", strinG = "]]";
    // print boolean result clearly
    cout << boolalpha << sol.isValid(strinG) << endl;
    /*cout<<(sol.isValid(str))? "true" : "false"; cout<<endl;
    cout<<(sol.isValid(stri))? "true" : "false"; cout<<endl;
    cout<<(sol.isValid(strin))? "true" : "false";cout<<endl;*/
}