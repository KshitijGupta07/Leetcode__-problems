/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "NULL,";
        }
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }
    TreeNode* build(queue<string>&q){
        string front=q.front();
        q.pop();
        if(front=="NULL"){
            return NULL;
        }
        cout<<front<<endl;
        TreeNode* root=new TreeNode(stoi(front));
        root->left=build(q);
        root->right=build(q);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s="";
        queue<string>q;
        for(int i=0;i<data.length();i++){
            if(data[i]==','){
                q.push(s);
                cout<<s<<endl;
                s="";
            }
            else{
                
                s+=data[i];
            }


        }
        if(s.size()!=0){
            q.push(s);
        }
        return build(q);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));