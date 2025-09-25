/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         if(head->next==NULL){
            return NULL;
         }
         ListNode* slow=head;
         ListNode* fast=head;
         ListNode* prev=NULL;
         while(fast!=NULL){
            fast=fast->next;
            n-=1;
            if(n==0){
                while(fast!=NULL){
                    fast=fast->next;
                    prev=slow;
                    slow=slow->next;
                }
            }

         }
         if(slow==head){
            return head->next;
         }
         prev->next=slow->next;
         slow->next=NULL;
         return head;

    
    }
};