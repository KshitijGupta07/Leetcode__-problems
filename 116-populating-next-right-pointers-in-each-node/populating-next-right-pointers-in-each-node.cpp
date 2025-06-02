/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        root->next=NULL;
        while(q.empty()==false){
              int a=q.size();
              for(int i=0;i<a;i++){
                  Node* front=q.front();
                  q.pop();
                  if(a>1&&i<a-1){
                    front->next=q.front();
                  }
              
              if(front==NULL){
                if(q.empty()==false){
                    q.push(NULL);
                }
              }
              else{
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
              }
              }
        }
        return root;

    }
};