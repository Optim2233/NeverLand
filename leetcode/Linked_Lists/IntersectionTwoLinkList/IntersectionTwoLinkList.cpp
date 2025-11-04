#include<iostream>
#include<algorithm>
#include<vector>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *List1_current = headA, *list2_current = headB;
        unordered_set<ListNode*> visited;
        while(List1_current)
        {
            visited.insert(List1_current);
            List1_current = List1_current->next;
        }
        while(list2_current)    
        {
            if(visited.count(list2_current)) return list2_current;
            list2_current = list2_current->next;
        }
        return NULL;
    }
};

int main()
{
    // Shared intersection part
    ListNode *List_common3 = new ListNode(8);
    ListNode *List_common2 = new ListNode(7, List_common3);
    ListNode *List_common1 = new ListNode(6, List_common2);

    // First linked list: 1 -> 2 -> 3 -> [6 -> 7 -> 8]
    ListNode *List1_node3 = new ListNode(3);
    ListNode *List1_node2 = new ListNode(2, List1_node3);
    ListNode *List1_node1 = new ListNode(1, List1_node2);

    // Second linked list: 9 -> 5 -> [6 -> 7 -> 8]
    ListNode *List2_node2 = new ListNode(5);
    ListNode *List2_node1 = new ListNode(9, List2_node2);

    // Heads
    ListNode *headA = List1_node1;
    ListNode *headB = List2_node1;

    Solution sol;
    ListNode *res = sol.getIntersectionNode(headA,headB);
    cout<<res->val;
}
