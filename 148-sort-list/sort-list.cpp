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
  ListNode* merge(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;

        }
        ListNode* head=NULL;
        ListNode* temp=NULL;
        while(list1!=NULL&&list2!=NULL){
              if(list1->val<list2->val){
                if(head==NULL){
                     head=new ListNode(list1->val);
                     temp=head;
                }
                else{
                    temp->next=new ListNode(list1->val);
                    temp=temp->next;
                }
                list1=list1->next;
              }
              else{
                    if(head==NULL){
                     head=new ListNode(list2->val);
                     temp=head;
                }
                else{
                    temp->next=new ListNode(list2->val);
                    temp=temp->next;
                }
                list2=list2->next;
              }
        }
        while(list1!=NULL){
            temp->next=new ListNode(list1->val);
            temp=temp->next;
            list1=list1->next;
        }
        while(list2!=NULL){
            temp->next=new ListNode(list2->val);
            temp=temp->next;
            list2=list2->next;
        }
        return head;
        
    }
    ListNode* solve(ListNode* head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast!=NULL&&fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
          prev->next=NULL;
        ListNode* temp1=solve(head);
        ListNode* temp2=solve(slow);
        ListNode* ans=merge(temp1,temp2);
        return ans;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* temp=solve(head);
        return temp;
    }
};