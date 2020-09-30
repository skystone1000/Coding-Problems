// Binary Tree
// 03 #0145 Binary Tree Postorder Traversal

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
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        postOrd(root);
        return ans;
    }
    
    void postOrd(TreeNode *root){
        if(root == NULL){
            return;
        }
        
        postOrd(root->left);
        postOrd(root->right);
        ans.push_back(root->val);
    }
};
