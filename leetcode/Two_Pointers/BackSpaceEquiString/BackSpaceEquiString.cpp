    #include<iostream>
    #include<string>
    #include<vector>
    #include<algorithm>
    using namespace std;

    class Solution {
    public:
        bool backspaceCompare(string s, string t) 
        {
            return (backspaceSubstract(s) == backspaceSubstract(t))? true : false;
        }
    public: // currently assigned to public for more transparent testing experience.  Switch it to private upon operation
        string backspaceSubstract(string& str)
        {
            for(int i = 1; i < str.size();i++ )
            {
                if(str[0] == '#') str.erase(str.begin());
                if(str[i]=='#')
                {
                    str.erase( str.begin() + i - 1, str.begin() + i + 1 ); 
                    i -= 2;
                    i = clamp(i, 0, (int)str.size());
                }
                
            }
            return str;
        }
    };

    int main()
    {
        string s = "a##c",  t = "#a#c";
        Solution sol;
        cout<<boolalpha<<(sol.backspaceCompare(s,t))? true : false;cout<<endl;
        cout<<sol.backspaceSubstract(s)<<endl;
        cout<<sol.backspaceSubstract(t);
        return 0;
    }