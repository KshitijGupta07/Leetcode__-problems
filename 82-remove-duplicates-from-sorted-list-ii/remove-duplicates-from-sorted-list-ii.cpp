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
    void deletehead(ListNode* head){
        ListNode* temp=head;
        head=head->next;
        delete temp;
        
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        map<int,int>m;
        ListNode* temp=head;
        while(temp->next!=NULL){
            if(temp->val==temp->next->val){
                m[temp->val]++;
            }
            temp=temp->next;
        }
        temp=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            if(m[curr->val]!=0){
               if(curr==head){
                head=head->next;
                curr=head;
               }
               else{
                temp->next=curr->next;
                curr=curr->next;
               }
            }
            else{
            temp=curr;
            curr=curr->next;
            }
        }
        return head;
    }
};