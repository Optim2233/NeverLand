#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode () : val(0), next(nullptr){}
    ListNode (int x) : val(x), next(nullptr){}
    ListNode (int x , ListNode *next) : val(x), next(next){}
};


class MyHashSet {
    private: vector<int> Database;

    
public:
    MyHashSet() {}
    auto Pointer(int key)
    {
       auto it = lower_bound(Database.begin(), Database.end(), key);
       return (it-Database.begin());
    }
    void add(int key) {
        if(!(contains(key)))
        {
            auto it = Pointer(key) + Database.begin();
            if(it == Database.end() || *it != key) Database.insert(it,key);
        }
        
    }
    
    void remove(int key) {
        if(contains(key))
        {
            auto it = Pointer(key);
            Database.erase(it + Database.begin());
        }
    }
    
    bool contains(int key) {
     
        return  (binary_search(Database.begin(), Database.end(),key))? true : false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
int main()
{
    MyHashSet Database ;
    Database.add(1);
    Database.add(2);
    cout<<boolalpha<<Database.contains(1)<<endl<<Database.contains(2)<<endl<<Database.contains(3)<<endl<<endl;
    Database.add(1);Database.remove(1);
    cout<<boolalpha<<Database.contains(1)<<endl<<Database.contains(2)<<endl<<Database.contains(3)<<endl;
    cout<<Database.Pointer(2);
    
}
