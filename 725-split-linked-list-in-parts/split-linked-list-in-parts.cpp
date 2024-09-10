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
    int size(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int count=size(head);
        vector<ListNode*>ans;
        if(count<k){
            ListNode* temp=head;
            for(int i=1;i<=count;i++){
                ListNode* temp2=temp->next;
                temp->next=NULL;

                ans.push_back(temp);
                temp=temp2;
            }
            for(int i=1;i<=k-count;i++){
                ans.push_back(NULL);
            }
            return ans;

        }
         int subsize=count/k;
         int m=count%k;
         ListNode* temp=head;
         if(count%k!=0){
            subsize=subsize+1;
         }
         ListNode* temp2=head;
         while(m!=0){
            int a=subsize;
            
            while(a>1){
               temp2=temp2->next;
               a--;
            }
            
             ListNode* temp3=temp2->next;
             temp2->next=NULL;
             
            ans.push_back(temp);
            temp2=temp3;
            temp=temp2;
            m=m-1;
         }
         
         ListNode* temp3=NULL;
          while(temp2!=NULL){
             for(int i=1;i<count/k;i++){
                temp2=temp2->next;
             }
             temp3=temp2->next;
             temp2->next=NULL;
             ans.push_back(temp);
             temp2=temp3;
             temp=temp2;
          }
            
         
        return ans;
    }
};