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
        ListNode* head=NULL;
        ListNode* temp=NULL;
        while(l1!=NULL&&l2!=NULL){
              if(temp==NULL){
                head=new ListNode(l1->val+l2->val);
                 temp=head;
              }
              else{
                
                temp->next=new ListNode(l1->val+l2->val);
                temp=temp->next;
              }
              l1=l1->next;
              l2=l2->next;
        }
        if(l1!=NULL){
            temp->next=l1;
            temp=temp->next;
        }
        if(l2!=NULL){
           temp->next=l2;
           temp=temp->next;
        }
        int carry=0;
        temp=head;
       ListNode* prev=NULL;
        while(temp!=NULL){
            if(temp->val+carry>9){
                temp->val=((temp->val+carry)%10);
                carry=1;
            }
            else{
                temp->val=temp->val+carry;
                carry=0;
            }
            prev=temp;
            temp=temp->next;
        }
        if(carry==1){
           prev->next=new ListNode(1); 
        }
        cout<<carry<<endl;
        return head;
    }
};