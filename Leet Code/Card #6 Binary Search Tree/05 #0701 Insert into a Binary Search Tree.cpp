// Binary Search Tree
// 05 #0701 Insert into a Binary Search Tree

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }
        
        TreeNode* iter = root;
        
        while(iter != NULL){
            // If element already present
            if(iter -> val == val)
                return root;
            
            // If target is greater
            else if(iter -> val < val){
                // If element not present insert
                if(iter -> right != NULL) 
                    iter = iter -> right;
                else
                    iter -> right = new TreeNode(val);
            }
            
            // If target is smaller
            else{
                // If element not present insert
                if(iter -> left != NULL)
                    iter = iter -> left;
                else
                    iter -> left = new TreeNode(val); 
            }
        }
        
        return root;
    }
};