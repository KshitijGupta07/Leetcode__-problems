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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newhead=NULL;
        ListNode* temp=newhead;
        while(l1!=NULL&&l2!=NULL){
    
                   if(newhead==NULL){
                       newhead=new ListNode(l2->val+l1->val);
                       temp=newhead;
                   }
                   else{
                    
                
                       temp->next=new ListNode(l2->val+l1->val);
                       temp=temp->next;
                       
                   }
                   l1=l1->next;
                   l2=l2->next;
            
         
        }
        while(l1!=NULL){
            temp->next=new ListNode(l1->val);
            temp=temp->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            temp->next=new ListNode(l2->val);
            temp=temp->next;
            l2=l2->next;
        }
        int carry=0;
        ListNode* prev=NULL;
        temp=newhead;
        while(newhead!=NULL){
            newhead->val=newhead->val+carry;
            if(newhead->val>9){
                newhead->val=newhead->val%10;
                carry=1;
            }
            else{
                carry=0;
            }
            prev=newhead;
            newhead=newhead->next;
        }
        if(carry==1){
            prev->next=new ListNode(1);
        }
   return temp;
    

    }
};