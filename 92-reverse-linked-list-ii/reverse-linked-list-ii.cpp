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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right||head->next==NULL){
            return head;
        }
        ListNode* past=NULL;
        ListNode* first=head;
        int count=1;
        while(count!=left){
            past=first;
            first=first->next;
            count++;

        }
        if(past!=NULL){
            past->next=NULL;
        }
        ListNode* prev=NULL;
        ListNode* curr=first;
        ListNode* future=NULL;
        while(curr!=NULL&&count<=right){
            future=curr->next;
            curr->next=prev;
            prev=curr;
            curr=future;
            count++;
        }
        if(past==NULL&&future==NULL){
        return prev;
        }
        else if(past!=NULL&&future==NULL){
            past->next=prev;
            
        }
        else if(past==NULL&&future!=NULL){
            first->next=future;
            return prev;
        }
    
            past->next=prev;
        first->next=future;
         
        return head;
    }
};