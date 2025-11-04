#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x) , next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
}‌;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head;
        while(current && current->next)
        {
            if( current->val == current->next->val) 
            {
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else{current = current->next;}

        }
        /*
        while(current != nullptr)
        {   
            if(current->next == nullptr) {tail->next = current;}
            else if(current->val == current->next->val) 
            {
                current = current->next;
            }
            else {tail->next = current; current = current->next;tail = tail->next;}
        }*/
        return head;
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
    ListNode *List1_head = List1_node1; ListNode *current = List1_head;
    Solution sol;
    ListNode *Result = sol.deleteDuplicates(List1_head);
    while(Result)
    {
        cout<<Result->val<<" ";
        Result =Result->next;
    }
    return 0;
}