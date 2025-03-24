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
        int length=0;
        while(head!=NULL){
            head=head->next;
            length++;
        }
        return length;
    }
    ListNode* tail(ListNode* head){
        while(head->next->next!=NULL){
            head=head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        int l=length(head);
        k=k%l;
        while(k>0){
            ListNode* pt=tail(head);
            ListNode* t=pt->next;
            t->next=head;
            head=t;
            pt->next=NULL;
            k-=1;
        }
        return head;
    }
};