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
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode *current = head;
        while(current)
        {
            if(visited.count(current))
            {
                return true;
            }
            visited.insert(current);
            current = current->next;
        }
        return false;
    }
};

int main()
{
    ListNode *List1_node6 = new ListNode(3);
    ListNode *List1_node5 = new ListNode(3,List1_node6);
    ListNode *List1_node4 = new ListNode(2,List1_node5);
    ListNode *List1_node3 = new ListNode(2,List1_node4);
    ListNode *List1_node2 = new ListNode(1,List1_node3);
    ListNode *List1_node1 = new ListNode(1,List1_node2);
    //List1_node6->next = List1_node2;
    ListNode *List1_head = List1_node1;
    Solution sol;
    bool rs = sol.hasCycle(List1_head);
    cout<<boolalpha<<rs<<endl;
}
