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
void insertattail(ListNode* &tail,int val){
     ListNode* newnode=new ListNode(val);
     if(tail==NULL){
        tail=newnode;
     }
     else{
         tail->next=newnode;
         tail=newnode;
     }
 }
 
 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL&&list2==NULL){
            return NULL;
        }
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        
        ListNode* tail=NULL;
        ListNode* head1=list1;
        ListNode* head2=list2;
        ListNode* head=NULL;
        int count=0;
        while(head1!=NULL&&head2!=NULL){
            
            
            if(head1->val>head2->val){
                insertattail(tail,head2->val);
                head2=head2->next;
            }
            else{
                insertattail(tail,head1->val);
                head1=head1->next;
            }
            count++;
            if(count==1){
                head=tail;
            }
            
            
            
        }
        if(head1!=NULL){
            while(head1!=NULL){
             insertattail(tail,head1->val);
             head1=head1->next;
            }

        }
        if(head2!=NULL){
            while(head2!=NULL){
                insertattail(tail,head2->val);
                head2=head2->next;
            }
        }
        return head;
    }
};