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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int countA=0;
        int countB=0;
        while(tempA!=NULL){
            tempA=tempA->next;
            countA+=1;
        }
        while(tempB!=NULL){
            tempB=tempB->next;
            countB+=1;
        }
        tempA=headA;
        tempB=headB;
        if(countA>countB){
            while(countA!=countB){
                tempA=tempA->next;
                countA-=1;
            }
        }
        else{
            while(countB!=countA){
                tempB=tempB->next;
                countB-=1;
            }
        }
        while(tempA!=NULL&&tempB!=NULL){
            if(tempA==tempB){
                return tempA;
            }
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};