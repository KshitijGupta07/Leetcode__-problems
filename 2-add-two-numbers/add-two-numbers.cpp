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
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    void insertattail(ListNode* &tail,int val){
        ListNode* newnode=new ListNode(val);
        tail->next=newnode;
        tail=newnode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* head1=l1;
       ListNode* head2=l2;
       while(head1!=NULL&&head2!=NULL){
          if(length(head1)>length(head2)){
              head1->val+=head2->val;
              head1=head1->next;
              head2=head2->next;
          }
          else{
              head2->val+=head1->val;
              head1=head1->next;
              head2=head2->next;
          }
       }

       
       if(head1!=NULL){
           head1=l1;
           while(head1->next!=NULL){
               if(head1->val>9){
                   head1->val=(head1->val)%10;
                   head1->next->val++;
               }
               head1=head1->next;
           }
           if(head1->val>9){
               head1->val=(head1->val)%10;
               insertattail(head1,1);
           }
       }
      else  {
           head2=l2;
           while(head2->next!=NULL){
               if(head2->val>9){
                   head2->val=(head2->val)%10;
                   head2->next->val++;
               }
               head2=head2->next;
           }
           if(head2->val>9){
               head2->val=(head2->val)%10;
               insertattail(head2,1);
           }
       }
       
       if(length(l1)>length(l2)){
           return l1;
       }
       return l2;


    }
};