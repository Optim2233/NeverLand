#include<iostream>
#include<vector>
#include<algorithm>
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
    ListNode* reverseList(ListNode* head) {
        
        return Iterative(head);
    };

    ListNode* Iterative(ListNode *head)  
    {
        
        if(!(head) || !(head->next)) return head;
        ListNode *Previous_Node = nullptr;
        ListNode *current = head;
        while(current) 
        {
            ListNode *Next_Node = current->next;
            current->next = Previous_Node;
            Previous_Node = current;
            current = Next_Node;
        }
        return Previous_Node;
    }
};
int main()
{//1,2,6,3,4,5,6
    ListNode *Listnode8 = new ListNode(8);
    ListNode *List_node7 = new ListNode(7,Listnode8);
    ListNode *List_node6 = new ListNode(6, List_node7);
    ListNode *List_node5 = new ListNode(5, List_node6);
    ListNode *List_node4 = new ListNode(4, List_node5);
    ListNode *List_node3 = new ListNode(3, List_node4);
    ListNode *List_node2 = new ListNode(2, List_node3);
    ListNode *List_node1 = new ListNode(1,List_node2);

    ListNode *head = List_node1;
    Solution sol;
    head = sol.reverseList(head);
     while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }\
    return 0;
}
