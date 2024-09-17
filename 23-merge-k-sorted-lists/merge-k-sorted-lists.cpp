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
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>p;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
            p.push({lists[i]->val,lists[i]});
            }
        }
         while(p.empty()==false){
            pair<int,ListNode*> top=p.top();
             temp->next=new ListNode(top.first);
             temp=temp->next;
            p.pop();
           if(top.second->next){
           p.push({top.second->next->val,top.second->next});
           }
        }
        return head->next;
    }
};