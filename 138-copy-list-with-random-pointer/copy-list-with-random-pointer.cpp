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
        map<Node* ,Node*>m;
        Node* temp=head;
        Node* head2=NULL;
        Node* temp2=NULL;
        while(temp!=NULL){
            m[temp]=new Node(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            if(head2==NULL){
                head2=m[temp];
                temp2=head2;
            }
            else{
                temp2->next=m[temp];
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        temp=head;
        temp2=head2;
        while(temp!=NULL){
              temp2->random=m[temp->random];
              temp2=temp2->next;
              temp=temp->next;
        }
        return head2;
    }
};