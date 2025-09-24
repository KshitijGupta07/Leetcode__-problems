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
    ListNode* rev(ListNode* head){
        ListNode* past=NULL;
        ListNode* future=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            future=curr->next;
            curr->next=past;
            past=curr;
            curr=future;
        }
        return past;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=slow;
        while(fast!=NULL&&fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        slow=rev(slow);
        while(head!=NULL&&slow!=NULL){
            if(head->val!=slow->val){
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;


    }
};