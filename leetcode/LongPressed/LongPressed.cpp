#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;//SelectiveRemoval() is the final function that solves the problem. Other functions will remain for future references

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        /*if(Remove(typed).size() < name.size())
        {
            return (Insert(name, Remove(typed)) == name)? true : false;
        }
        else
        {
            return (Remove(typed) == name)? true : false;
        }
        */
       if(typed[0] != name[0])return false;
       else return (SelectiveRemoval(name,typed) == name)? true : false;
       
    }
public:
    string Remove(string& s)
    {
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == s[i+1] || s[i] == s[i-1]) {s.erase(s.begin() + i); i--;}
        }
        return s;
    }
    string Insert(string& name, string typed)
    {
        int First_Pointer = 0; 
        typed.resize(name.size(),' ');
        while(First_Pointer < name.size() )
        {
            while(First_Pointer < name.size()&& typed[First_Pointer] == name[First_Pointer]) First_Pointer++;
            typed.insert(First_Pointer,1, name[First_Pointer]);
            First_Pointer++;
        }
        typed.resize(name.size());
        return typed;
    }
    string SelectiveRemoval(string& name, string& typed)
    {
        int First_Pointer = 0;
        while(First_Pointer < typed.size() && typed.size() >= name.size())
        {
            if(First_Pointer < name.size() && name[First_Pointer] == typed[First_Pointer]) First_Pointer++;
            else{
                while (First_Pointer < typed.size() && First_Pointer < name.size() && typed[First_Pointer] != name[First_Pointer])
                {
                    
                    if(typed[First_Pointer] == name[First_Pointer-1])
                    {
                  
                        typed.erase(typed.begin() + First_Pointer);
                    } else{First_Pointer++;}
                }   
                First_Pointer++;
            }
        }
        while(typed.size() > name.size() && typed[typed.size()-1] == typed[typed.size()-2]){typed.erase(typed.size()-1);} 
  
        return typed;
    }
};

int main()
{
    Solution sol;
    string name = "alex", typed = "alexs";
    cout<<boolalpha<<sol.isLongPressedName(name,typed)<<endl;
    string n = sol.SelectiveRemoval(name,typed);
    cout<<name<<endl<<n<<endl;
    cout<<"Typed Size "<< typed.size()<<endl<<"Name Size "<< name.size();
    return 0;
}