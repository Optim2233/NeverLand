#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<cmath>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l1Pointer = l1, *l2Pointer = l2;
        while(l1Pointer && l2Pointer)
        {
            l1Pointer->val = l1Pointer->val + l2Pointer->val;
            l1Pointer = l1Pointer->next;
            l2Pointer = l2Pointer->next;
        }
        if(l2Pointer == nullptr) l1Pointer->next = l2Pointer;
        return l1;
    }
};

int main()
{
    ListNode *List2_node6 = new ListNode(6);
    ListNode *List2_node5 = new ListNode(5,List2_node6);
    ListNode *List2_node4 = new ListNode(1,List2_node5);
    ListNode *List2_node3 = new ListNode(1,List2_node4);
    ListNode *List2_node2 = new ListNode(1,List2_node3);
    ListNode *List2_node1 = new ListNode(1,List2_node2);

    ListNode *List2_head = List2_node1;

    ListNode *List1_node6 = new ListNode(6);
    ListNode *List1_node5 = new ListNode(5,List1_node6);
    ListNode *List1_node4 = new ListNode(1,List1_node5);
    ListNode *List1_node3 = new ListNode(1,List1_node4);
    ListNode *List1_node2 = new ListNode(1,List1_node3);
    ListNode *List1_node1 = new ListNode(1,List1_node2);
    
    ListNode *List1_head = List1_head;
   Solution sol;
   List1_head = sol.addTwoNumbers(List1_head,List2_head);
   while(List2_head )
   {
    cout<<List2_head->val<<" ";
    List1_head = List1_head->next;
   }
   return 0;
}