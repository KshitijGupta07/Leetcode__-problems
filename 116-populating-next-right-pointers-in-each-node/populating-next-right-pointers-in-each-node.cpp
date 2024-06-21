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
        vector<Node*>v;
        vector<vector<Node*>>a;
        q.push(root);
        q.push(NULL);
        
        while(q.empty()==false){
            Node* front=q.front();
            q.pop();
            if(front==NULL){
                if(q.empty()==false){
                 q.push(NULL);
                }
                 a.push_back(v);
                 v.clear();
            }
            else{
                v.push_back(front);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                    
                }
            }
        }
    
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size()-1;j++){
                a[i][j]->next=a[i][j+1];
            }
        
        }
        return root;
    }
};