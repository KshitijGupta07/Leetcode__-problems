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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        
        ListNode* ans=NULL;
        ListNode* d=ans;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                
                if(ans==NULL){
                    ans=new ListNode(temp->val);
                    d=ans;
                }
                else{
                    ans->next=new ListNode(temp->val);
                    ans=ans->next;
                }
                
            }
            temp=temp->next;

        }
        temp=head;
 if(d==NULL){
            return head;
        }
        while(temp!=NULL){
              if(temp->val>=x){
                ans->next=new ListNode( temp->val);
                ans=ans->next;
              }
              temp=temp->next;
        }
       
        return d;
    }
};