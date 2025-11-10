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
    bool isPalindrome(ListNode* head) {
        if(!(head) || !(head->next)) return head;
        
        ListNode *slow = head, *fast = head, *Previous_Node = nullptr;
        while(fast && fast->next) {slow = slow->next; fast = fast->next->next;}
        ListNode *current = slow;
        while(current)
        {
            ListNode *NextNode = current->next;
            current->next = Previous_Node;
            Previous_Node = current;
            current = NextNode;
        }
        while(head && Previous_Node)
         {  if(head->val==Previous_Node->val){head = head->next; Previous_Node = Previous_Node->next;} else{return false;} }
         return true;
    }
};
int main(){
    ListNode *List_node4 = new ListNode(1);
    ListNode *List_node3 = new ListNode(1);
    ListNode *List_node2 = new ListNode(0, List_node3);
    ListNode *List_node1 = new ListNode(1,List_node2);

    ListNode *head = List_node1;
    Solution sol;
    cout<<boolalpha<<sol.isPalindrome(head);
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
   
}