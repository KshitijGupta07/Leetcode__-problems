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
            Node* clone=new Node(node->val);
            return clone;
        }
        map<Node*,Node*>mpp;
        mpp[node]=new Node(node->val,{});
        queue<Node*>q;
        q.push(node);
        while(q.empty()==false){
            Node* current=q.front();
            q.pop();
            for(auto x:current->neighbors){
                if(mpp.find(x)==mpp.end()){
                    mpp[x]=new Node(x->val,{});
                    q.push(x);
                }
                mpp[current]->neighbors.push_back(mpp[x]);
            }
        }
        return mpp[node];
    }
};