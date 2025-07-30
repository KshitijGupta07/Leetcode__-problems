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
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<>>p;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
            p.push({lists[i]->val,lists[i]});
            }
        }
        ListNode* head=NULL;
        ListNode* temp=NULL;
        while(p.empty()==false){
            ListNode* top=p.top().second;
            int topp=p.top().first;
            p.pop();
            if(head==NULL){
                head=new ListNode(topp);
                temp=head;
            }
            else{
                temp->next=new ListNode(topp);
                temp=temp->next;
            }
            if(top->next!=NULL){
                p.push({top->next->val,top->next});
            }
        }
        return head;
    }
};