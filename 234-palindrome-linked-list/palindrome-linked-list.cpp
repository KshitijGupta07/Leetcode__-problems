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
    int co(ListNode* head){
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        int count=co(head);
        ListNode* curr=slow;
        prev=NULL;
        while(curr!=NULL){
            ListNode* future=curr->next;
            curr->next=prev;
            prev=curr;
            curr=future;
        }
        while(prev!=NULL&&head!=NULL){
            if(prev->val!=head->val){
                return false;
            }
            prev=prev->next;
            head=head->next;
        }
        return true;
        


    }
};