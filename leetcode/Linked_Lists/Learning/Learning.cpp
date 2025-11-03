#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 //* Definition for singly-linked list.

   struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}   
    ListNode(int x)  : val(x), next(nullptr){}
    ListNode(int x , ListNode *next): val (x) , next(next){}
   };

   int main()
   {
        ListNode *node3 = new ListNode(30);
        ListNode *node2 = new ListNode(20,node3);
        ListNode *node1 = new ListNode(10,node2);
        ListNode *head = node1;
        ListNode *current = head;
        while(current != nullptr)
        {
            cout<<current->val<<" ";
            current = current->next;
        }
       int count = 0 ; 
       current = head;
       while(current != nullptr)
       {
        count++;
        current = current->next;
       }
       cout<<endl<<count<<" "<<std::endl;

       int sum = 0;
       for(current = head; current != nullptr; current= current->next)
       {
        sum+= current->val;
        cout<<sum<<" ";
       }

       bool found = false;
       current = head;
       while(current)
       {
        if(current->val == 20)
        {
            found = true; break;
        }
        current = current->next;
       }
   }