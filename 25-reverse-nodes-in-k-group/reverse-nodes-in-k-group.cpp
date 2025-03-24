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
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        if(count<k){
            return head;
        }
        ListNode* past=NULL;
        ListNode* curr=head;
        ListNode* future=NULL;
        count=0;
        while(count!=k){
            future=curr->next;
            curr->next=past;
            past=curr;
            curr=future;
            count++;
        }
        temp=past;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=reverseKGroup(future,k);
        return past;
    }
};