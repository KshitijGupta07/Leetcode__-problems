/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
int length(ListNode* head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count+=1;
    }
    return count;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int a=length(temp1);
        int b=length(temp2);
        int mini=min(a,b);
        while(a>mini){
            headA=headA->next;
            a--;
        }
        while(b>mini){
            headB=headB->next;
            b--;
        }
        
        while(headA!=NULL&&headB!=NULL){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};