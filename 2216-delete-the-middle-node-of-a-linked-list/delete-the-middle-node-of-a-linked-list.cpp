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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        ListNode* prev=NULL;
        ListNode* middle=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            prev=middle;
            middle=middle->next;
            fast=fast->next->next;
        }
        ListNode* temp=middle->next;
        prev->next=temp;
        middle->next=NULL;
        return head;
    }
};