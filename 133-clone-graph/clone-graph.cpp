/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        if(node->neighbors.size()==0){
            return new Node(node->val);
        }
        Node* ans=new Node(node->val);
        map<Node*,Node*>m;
        m[node]=ans;
        queue<Node*>q;
        q.push(node);
        while(q.empty()==false){
            Node* front=q.front();
            q.pop();
            for(auto j:front->neighbors){
                if(m.find(j)==m.end()){
                    m[j]=new Node(j->val);
                    q.push(j);
                }
                m[front]->neighbors.push_back(m[j]);
            } 
        }
        return m[node];
    }
};