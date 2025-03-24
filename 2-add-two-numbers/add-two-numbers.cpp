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
    int length(ListNode* head){
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL){
            temp=temp->next;
            length+=1;
        }
        return length;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a=length(l1);
        int b=length(l2);
        
        ListNode* head=NULL;
        ListNode* temp=NULL;
         while(l1!=NULL&&l2!=NULL){
                if(head==NULL){
                    head=new ListNode(l1->val+l2->val);
                    temp=head;
                }
                else{
                    temp->next=new ListNode(l1->val +l2->val);
                    temp=temp->next;
                }
                l1=l1->next;
                l2=l2->next;
         }
         while(l1!=NULL){
            temp->next=new ListNode(l1->val);
            l1=l1->next;
            temp=temp->next;
         }
         while(l2!=NULL){
            temp->next=new ListNode(l2->val);
            l2=l2->next;
            temp=temp->next;
         }
         temp=head;
         cout<<temp->val<<endl;
         while(temp->next!=NULL){
            if(temp->val>=10){
                temp->next->val+=(temp->val)/10;
                temp->val=temp->val%10;
            }
            temp=temp->next;
         }
         if(temp->val>=10){
            temp->next=new ListNode(temp->val/10);
            temp->val=temp->val%10;
         }
        return head;
            
    }
};