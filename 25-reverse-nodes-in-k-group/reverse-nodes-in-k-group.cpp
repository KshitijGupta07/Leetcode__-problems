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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        int counter=0;
        ListNode* temp2=head;
        while(temp2!=NULL){
            temp2=temp2->next;
            counter++;
        }
        if(counter<k){
            return head;
        }
        ListNode* past=NULL;
        ListNode* curr=head;
        ListNode* future=NULL;
        int count=0;
        while(count!=k&&curr!=NULL){
            future=curr->next;
            curr->next=past;
            past=curr;
            curr=future;
            count++;
        }
        ListNode* temp=past;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=reverseKGroup(future,k);
        
        return past;

    }
};