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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* current=head;
        ListNode* forward=NULL;
        while(current!=NULL){
            forward=current->next;
            current->next=prev;
            prev=current;
            current=forward;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp=reverse(head);
        ListNode* newnode=temp;
        while(newnode!=NULL&&newnode->next!=NULL){
            if(newnode->val>newnode->next->val){
                newnode->next=newnode->next->next;
            }
            else{
                newnode=newnode->next;
            }
        }
        return reverse(temp);
    }
};