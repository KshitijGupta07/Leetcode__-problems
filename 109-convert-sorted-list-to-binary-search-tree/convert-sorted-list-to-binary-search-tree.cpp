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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countnode(ListNode* head){
        if(head==NULL){
            return 0;
        }
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
             temp=temp->next;
             count++;
        }
        return count;
    }
    TreeNode* buildtree(ListNode* &head,int count){
        if(count==0||head==NULL){
            return NULL;
        }
        
        
         TreeNode* left=buildtree(head,count/2);
        TreeNode* root=new TreeNode(head->val);
        root->left=left;
       head=head->next;
        root->right=buildtree(head,count-count/2-1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        TreeNode* root=buildtree(head,countnode(head));
        return root;

    }
};