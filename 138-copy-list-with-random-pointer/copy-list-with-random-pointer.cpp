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
        map<Node*,Node*>m;
        m[NULL]=NULL;
        Node* temp=head;
        while(temp!=NULL){
            m[temp]=new Node(temp->val);
            temp=temp->next;
        }
        temp=head;
        Node* newnode;
        while(temp!=NULL){
            newnode=m[temp];
            newnode->next=m[temp->next];
            newnode->random=m[temp->random];
            temp=temp->next;
        }
        return m[head];
    }
};