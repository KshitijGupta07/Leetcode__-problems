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
ListNode* nodebeforetail(ListNode*&head){
    ListNode* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0){
            return head;
        }
        ListNode* a=head;
        int count=0;
        while(a->next!=NULL){
            a=a->next;
            count++;
        }
        
        
          k=k%(count+1);
          while(k!=0){
              ListNode* beforetail=nodebeforetail(head);
              ListNode* tail=beforetail->next;
              beforetail->next=NULL;
              tail->next=head;
              head=tail;
              k--;
          }
          return head;
    }
};