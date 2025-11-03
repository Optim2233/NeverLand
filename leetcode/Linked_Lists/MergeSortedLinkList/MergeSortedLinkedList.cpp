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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1) tail->next = list1;
        else tail->next = list2;
        return dummy->next;
    }
};
int main()
{
    ListNode *List1_node3 = new ListNode(4);
    ListNode *List1_node2 = new ListNode(2,List1_node3);
    ListNode *List1_node1 = new ListNode(1,List1_node2);
    ListNode *List1_head = List1_node1;

    ListNode *List2_node3 = new ListNode(4);
    ListNode *List2_node2 = new ListNode(3,List2_node3);
    ListNode *List2_node1 = new ListNode(1,List2_node2);
    ListNode *List2_head = List2_node1;
    ListNode *List1_current = List1_head, *List2_current = List2_head;
    Solution sol;
    List1_head = sol.mergeTwoLists(List1_current, List2_current);
    for(ListNode *current = List1_head; current; current = current->next)
    {
        cout<<current->val<<" ";
    }
   /* ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    int First_Pointer = 0, Second_Pointer = 0;
    
    while(List1_current && List2_current)
    {
        if(List1_current->val <= List2_current->val)
        {
            tail->next = List1_current;
            List1_current =  List1_current->next; 
        } 
        else
        {
            tail->next = List2_current;
            List2_current = List2_current->next;
        } 
        tail = tail->next;
    }
    if(List1_current) tail->next = List1_current;
    else tail->next = List2_current;
    for(List1_current = dummy->next; List1_current != nullptr; List1_current = List1_current->next)
    {
        cout<<List1_current->val<<" ";
    }
    */
   
}