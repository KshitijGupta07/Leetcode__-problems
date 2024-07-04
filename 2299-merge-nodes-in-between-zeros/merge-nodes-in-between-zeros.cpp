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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* newhead=NULL;
        ListNode* newtail=NULL;
        int sum=0;
        while(temp!=NULL){
            if(temp->val!=0){
                sum+=temp->val;
            } 
            if(temp->val==0&&temp!=head){
                if(newhead==NULL){
                    newhead=new ListNode(sum);
                    newtail=new ListNode(sum);
                }
                else{
                    ListNode* newnode=new ListNode(sum);
                    newtail->next=newnode;
                    newtail=newnode;
                    if(newhead->next==NULL){
                        newhead->next=newtail;
                    }
                }
                sum=0;
            }
            temp=temp->next;
        }
        return newhead;
    }
};