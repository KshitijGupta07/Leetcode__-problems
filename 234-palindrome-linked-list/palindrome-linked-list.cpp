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
    ListNode* reverse(ListNode* head){
        ListNode* past=NULL;
        ListNode* curr=head;
        ListNode* future=NULL;
        
        while(curr!=NULL){
             future=curr->next;
             curr->next=past;
             past=curr;
             curr=future;
        }
        return past;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        ListNode* temp=head;
        ListNode* fast=head;
        ListNode* slow=head;
        int count=0;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            count++;
        }
        ListNode* head2=slow;
        if(fast!=NULL){
            count++;
            head2=head2->next;
            
        }
        
         head2=reverse(slow);
        
       
    
        while(head2!=NULL){
            
            if(head->val!=head2->val){
                return false;
            }
    
            head=head->next;
            head2=head2->next;
        }
        return true;
        
        
    }
};