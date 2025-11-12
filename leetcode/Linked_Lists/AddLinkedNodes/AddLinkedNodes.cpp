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
    ListNode* addTwoNumbers(ListNode *head1, ListNode *head2) {

        ListNode *l1Pointer = head1; int i = 0 , j = 0, carry = 0;

        while(head1 && head2 || carry == 1)
        {
            head1->val += head2->val + carry; carry = 0;
            if(head1->val >= 10) carry++; head1->val %= 10;
            if(head1->next == nullptr && (carry == 1 ||head2->next != nullptr)) head1->next = new ListNode(0);
            if(head2->next == nullptr && (carry == 1 ||head1->next != nullptr)) head2->next = new ListNode(0);
            head1 = head1->next; head2 = head2->next;
        }
        return l1Pointer;
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
    
    ListNode *List1_head = List1_node1;

   Solution sol;
   ListNode *Res = sol.addTwoNumbers(List1_head,List2_head);
    while(Res)
   {
    cout<<Res->val<<" ";
    Res = Res->next;
   }
   return 0;
}