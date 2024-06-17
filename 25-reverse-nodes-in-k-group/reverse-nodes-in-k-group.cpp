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
        int i=0;
         ListNode* past=NULL;
        ListNode* current=head;
        ListNode* future=NULL;
        ListNode* temp=head;
        while(i<k){
            if(temp==NULL){
                return head;
            }
          temp=temp->next;
          i++;
        }
        i=0;
       
        while(current!=NULL&&i<k){
            future=current->next;
            current->next=past;
            past=current;
            current=future;
            i++;
        }
        if(future!=NULL){
            head->next=reverseKGroup(future,k);
        }
        return past;
    }
};