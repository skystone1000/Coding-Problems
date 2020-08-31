#include<iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    depth(root, &diameter);
    return diameter;
}

int depth(TreeNode *root, int *diameter) {
    if (!root) {
        return 0;
    }
    auto left = depth(root->left, diameter);
    auto right = depth(root->right, diameter);
    *diameter = max(*diameter, left + right);
    return 1 + max(left, right);
}

int main() 
{ 
  
  /* Constructed binary tree is  
            1 
          /   \ 
        2      3 
      /  \ 
    4     5 
  */
  struct TreeNode *root = TreeNode(1); 
  root->left        = TreeNode(2); 
  root->right       = TreeNode(3); 
  root->left->left  = TreeNode(4); 
  root->left->right = TreeNode(5); 
  
  printf("Diameter of the given binary tree is %d\n", diameter(root)); 
  
  return 0; 
} 