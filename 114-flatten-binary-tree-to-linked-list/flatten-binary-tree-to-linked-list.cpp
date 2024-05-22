/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->left != nullptr) {
                TreeNode* temp = current->left;
                while (temp->right != nullptr) {
                    temp = temp->right;
                }
                temp->right = current->right;
                current->right = current->left;
                current->left = nullptr;  // Make sure to set the left to nullptr
            }
            current = current->right;
        }
    }
};
