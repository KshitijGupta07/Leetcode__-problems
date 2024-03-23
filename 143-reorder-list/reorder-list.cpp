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
    void reorderList(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        if(fast->next==NULL||fast->next->next==NULL){
            return;
        }
        if(fast->next->next!=NULL){
        while(fast!=NULL&&fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        }
        
        
        ListNode*middlenext=slow->next;
        ListNode* past=NULL;
        
        ListNode* future=NULL;
        while(middlenext!=NULL){
            future=middlenext->next;
            middlenext->next=past;
            past=middlenext;
            middlenext=future;
        }
        middlenext=past;
        
        slow->next=NULL;
        slow=head;
        while(slow!=NULL&&middlenext!=NULL){
            ListNode* forward=slow->next;
            ListNode* f=middlenext->next;
            middlenext->next=slow->next;
            slow->next=middlenext;
            slow=forward;
            middlenext=f;
        }
        


       
       
       

    }
};