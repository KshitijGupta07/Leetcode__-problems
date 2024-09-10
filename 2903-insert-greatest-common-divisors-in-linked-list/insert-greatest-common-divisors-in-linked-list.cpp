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
  int gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a!=0&&b!=0){
        if(a>b){
            a-=b;
        }
        else{
            b-=a;
    }
      
    }
    if(a==0){
        return b;
    }
    return a;
  }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
         ListNode* current=head->next;
          ListNode* future=current->next;
         ListNode* past=head;
         while(current!=NULL){
            future=current->next;
            ListNode* newnode=new ListNode(gcd(past->val,current->val));
            past->next=newnode;
            newnode->next=current;
            past=current;
            current=future;

         } 
         return head;
    }
};