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
    
    ListNode* doubleIt(ListNode* head) {
        
        ListNode* prev=head;
        while(prev!=NULL){
            prev->val*=2;
            prev=prev->next;
           }
           
        prev=head;
       ListNode* current=head->next;
       while(current!=NULL){
           if(current->val>9){
               prev->val+=current->val/10;
               current->val%=10;
           }
           prev=current;
           current=current->next;
       }
       if(head->val>9){
           int value=head->val/10;
           head->val%=10;
           ListNode* newnode=new ListNode(value);
           newnode->next=head;
           head=newnode;
       }
        
        
        
        return head;
    }
};