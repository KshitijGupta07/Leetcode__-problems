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
        if(head->next==NULL){
            return NULL;
        }
        ListNode* temp=head;
        ListNode* ans=head;
        ListNode* prev=NULL;
        
        while(temp->next!=NULL){
            if(n<=1){
                prev=ans;
                ans=ans->next;
                
            }
            else{
                n=n-1;
            }
            temp=temp->next;
        
        }
               if(ans==head){
            cout<<ans->val<<endl;
            return head->next;
         }
         if(prev==NULL){
            head->next==NULL;
            return head;
         }
        
        prev->next=ans->next;
        ans->next=NULL;
        return head;


    }
};