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
            count++;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       int a=length(headA);
       int b=length(headB);
       if(a>b){
        while(a>b){
            headA=headA->next;
            a-=1;
        }

       }
       if(b>a){
        while(b>a){
            headB=headB->next;
            b-=1;
        }
       }
       
       ListNode* value=0;
       bool check=false;
       while(headA!=NULL&&headB!=NULL){
                 if(headA==headB){
                    if(check==false){
                    value=headA;
                    check=true;
                    }
                 }
                 else{
                    check=false;
                    value=NULL;
                 }
                 headA=headA->next;
                 headB=headB->next;
       }
       return value;
       

    }
};