#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;//Runtime is optimized in trade of memory


 class MyHashMap {
private:

    static const int NUM_BUCKETS = 1009;
    std::vector<std::pair<int,int>> buckets[NUM_BUCKETS];

    int hash(int key) {
        return key % NUM_BUCKETS;
    }

public:

    MyHashMap() {}

    void put(int key, int value) {
        int bucketIndex = hash(key);           
        auto &bucket = buckets[bucketIndex];  

        for (auto &pair : bucket) {
            if (pair.first == key) {
                pair.second = value;        
                return;
            }
        }
        bucket.push_back({key, value});
    }

    int get(int key) {
        int bucketIndex = hash(key);
        auto &bucket = buckets[bucketIndex];

        for (auto &pair : bucket) {
            if (pair.first == key)
                return pair.second;           
        }

        return -1;                         
    }

    void remove(int key) {
        int bucketIndex = hash(key);
        auto &bucket = buckets[bucketIndex];

        for (int i = 0; i < bucket.size(); ++i) {
            if (bucket[i].first == key) {
                bucket[i] = bucket.back();
                bucket.pop_back();
                return;
            }
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
