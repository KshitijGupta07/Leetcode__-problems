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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          if(lists.size()==0){
            return NULL;
          }
          ListNode* head=NULL;
          ListNode* temp=NULL;
          priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<>>p;
          for(auto j:lists){
            if(j!=NULL){
            p.push({j->val,j});
            }
          }
          while(p.empty()==false){
             pair<int,ListNode*>top=p.top();

             p.pop();
              if(head==NULL){

                  head=new ListNode(top.first);
                  temp=head;
              }
              else{
                 temp->next=new ListNode(top.first);
                 temp=temp->next;
              }
              if(top.second->next!=NULL){
                p.push({top.second->next->val,top.second->next});
              }
            
              

          }
          return head;
    }
};