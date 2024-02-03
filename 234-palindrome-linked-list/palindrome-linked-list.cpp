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
     ListNode* reverse(ListNode* &head){
         if(head==NULL||head->next==NULL){
             return head;
         }
         ListNode* prev=NULL;
         ListNode* current=head;
         ListNode* forward=NULL;
         while(current!=NULL){
             forward=current->next;
             current->next=prev;
             prev=current;
             current=forward;
         }
         return prev;

     }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        if(head->next->next==NULL){
            if(head->val!=head->next->val){
                return false;
            }
            else{
                return true;
            }
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* middlenext=slow->next;
        slow->next=NULL;
        
        
        ListNode* head1=head;
        ListNode* head2=reverse(middlenext);
        while(head1!=NULL&&head2!=NULL){
            
            if(head1->val!=head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return true;

        

    }
};