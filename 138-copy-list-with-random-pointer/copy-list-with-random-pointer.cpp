/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         if(head==NULL){
            return NULL;
         }
         map<Node*,Node*>m;
         Node* temp=head;
         while(temp!=NULL){
            m[temp]=new Node(temp->val);
            temp=temp->next;
         }
         Node* newhead=m[head];
         temp=head;
         Node* newtemp=newhead;
         while(temp!=NULL){
            newtemp->next=m[temp->next];
            newtemp->random=m[temp->random];
            temp=temp->next;
            newtemp=newtemp->next;
         }
         return newhead;

    }
};