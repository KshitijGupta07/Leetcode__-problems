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
    ListNode* swapNodes(ListNode* head, int k) {
        int i=1;
        ListNode* temp=head;
        while(i<k){
            i++;
             temp=temp->next;
        }
        ListNode* first=temp;
        ListNode* second=head;
        
        temp=temp->next;
        while(temp!=NULL){
            temp=temp->next;
            second=second->next;
        }
        
        swap(second->val,first->val);
        return head;

    }
};