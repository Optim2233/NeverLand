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
    int getDecimalValue(ListNode* head) {
         ListNode *current = head; 
         int sum = 0, i = 0; string binary;
         while(current)
         {
            binary.push_back(current->val);
            current = current->next;
         }
         int size = binary.size();
         for(i; i <= size-1; i++)
         {
            sum+= binary[i] * pow(2,size - 1 - i);
         }
         return sum;
    }
}; 
int main()
{
    ListNode *List1_node6 = new ListNode(6);
    ListNode *List1_node5 = new ListNode(5,List1_node6);
    ListNode *List1_node4 = new ListNode(1);
    ListNode *List1_node3 = new ListNode(1,List1_node4);
    ListNode *List1_node2 = new ListNode(1,List1_node3);
    ListNode *List1_node1 = new ListNode(1,List1_node2);

    ListNode *List1_head = List1_node1;
    Solution sol;
    cout<<sol.getDecimalValue(List1_head);
   
 
}