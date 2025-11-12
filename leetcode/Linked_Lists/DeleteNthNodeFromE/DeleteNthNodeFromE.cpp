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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int delay = n-1;
        ListNode *slow = head, *fast = head,*slow_slow = nullptr;
        while(fast->next)
        {
            fast = fast->next;
            if(delay != 0) delay--;
            else{ 
                slow_slow = slow;
                slow = slow->next;}
        }
        if(slow_slow != nullptr) slow_slow->next = slow->next; else{head = head->next;}
        delete slow;
        return head;
    }
};

int main()
{

    ListNode *List1_node6 = new ListNode(5);
    ListNode *List1_node5 = new ListNode(4,List1_node6);
    ListNode *List1_node4 = new ListNode(3,List1_node5);
    ListNode *List1_node3 = new ListNode(2,List1_node4);
    ListNode *List1_node2 = new ListNode(1,List1_node3);
    ListNode *List1_node1 = new ListNode(0,List1_node2);
    
    ListNode *List1_head = List1_node1;

   Solution sol;
   List1_head = sol.removeNthFromEnd(List1_head,6);
    while(List1_head)
    {
        cout<<List1_head->val<<" ";
        List1_head = List1_head->next;
    }

   return 0;
}