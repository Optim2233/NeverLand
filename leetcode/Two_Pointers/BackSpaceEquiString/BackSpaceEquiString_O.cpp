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
            int j = 0;
            for(int i = 0; i < str.size();i++ )
            {
                if(str[i] != '#') str[j++] = str[i];
                else if( j > 0 ) j--;
            }
            str.resize(j);
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