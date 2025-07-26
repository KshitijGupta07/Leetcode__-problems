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
    int count(ListNode* head){
        int count=0;
        while(head!=NULL){
            count+=1;
            head=head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        int length=count(head);
        k=k%length;
        while(k>0){
            ListNode* temp=head;
            ListNode* prev=NULL;
            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
            }
            temp->next=head;
            head=temp;
            prev->next=NULL;
            k-=1;
        }
        return head;
    }
};