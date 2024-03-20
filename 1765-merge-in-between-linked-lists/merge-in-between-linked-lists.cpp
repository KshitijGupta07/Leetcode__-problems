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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count=0;
        ListNode* head=list1;
        while(count!=a-1){
            head=head->next;
            count++;
        }
        ListNode* temp=head;
        head=list1;
        count=0;
         while(count!=b){
            head=head->next;
            count++;
        }
       
        
        
        ListNode* temporary=list2;
        
        while(temporary->next!=NULL){
            temporary=temporary->next;
        }
        temp->next=list2;
        temporary->next=head->next;
        head->next=NULL;
        return list1;

        
    }
};