#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class MyHashMap {
private: vector<pair<int,int>>MapBase;
public:
    MyHashMap() {}

    void put(int key, int value) {
        auto it = lower_bound(MapBase.begin(),MapBase.end(),make_pair(key,0),[](auto &a , auto &b){return a.first < b.first;}) ;
        if(it != MapBase.end() && it->first == key){it->second = value;}
        else {MapBase.insert(it,make_pair(key,value));}
    }
    
    int get(int key) {
        auto it = lower_bound(MapBase.begin(),MapBase.end(),make_pair(key,0),[](auto &a , auto &b){return a.first < b.first;}) ;
        if(it != MapBase.end() && it->first == key) {return it->second;}
        else {return -1;} 
        return (it != MapBase.end() && it->first == key)? it->second : -1;
    }
    
    void remove(int key) {
        auto it = lower_bound(MapBase.begin(),MapBase.end(),make_pair(key,0),[](auto &a , auto &b){return a.first < b.first;}) ;
        if(it != MapBase.end() && it->first == key)
        {
            MapBase.erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
int main()
{

    MyHashMap obj;
    obj.put(1,2);  obj.put(2,3); obj.put(1,1);
    cout<<obj.get(1)<<obj.get(2)<<obj.get(3)<<endl;
    obj.remove(1);
    cout<<obj.get(1)<<obj.get(2)<<obj.get(3);
    
    
   
    
}
