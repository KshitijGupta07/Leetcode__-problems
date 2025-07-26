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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){return NULL;}
        ListNode* temp=head;
        ListNode* slow=head;
        while(n>0){
            temp=temp->next;
            n-=1;
        }
        ListNode* prev=NULL;
        while(temp!=NULL){
            prev=slow;
            slow=slow->next;
            temp=temp->next;
        }
        if(prev==NULL){
            head=head->next;
            return head;
        }
        prev->next=slow->next;
        slow->next=NULL;
        return head;
    }
};