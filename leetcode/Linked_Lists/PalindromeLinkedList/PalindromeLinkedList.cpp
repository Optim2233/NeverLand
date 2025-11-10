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
        ListNode *current = head;
        vector<int>Palinchecklist;
        while(current)
        {
            Palinchecklist.push_back(current->val);
            current = current->next;
        }
        int left = 0 , right = Palinchecklist.size()-1;
        while(left < right)
        {
            if(Palinchecklist[left] != Palinchecklist[right]) return false;
            left++; right--;
        }
        return true;
    }
};
int main(){
    ListNode *List_node4 = new ListNode(1);
    ListNode *List_node3 = new ListNode(3, List_node4);
    ListNode *List_node2 = new ListNode(2, List_node3);
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