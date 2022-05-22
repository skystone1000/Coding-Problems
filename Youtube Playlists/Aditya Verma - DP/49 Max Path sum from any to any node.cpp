// Aditya Verma - DP Playlist - 49 Max Path sum from any to any node

/*
Flow 
    - Problem statement
    - Syntax Discussion
    - Code variation

Q) Given a tree, you need to pick any two nodes from tree, calculate the total value of
all nodes in path of those two nodes including start and end (sum of node values in path). 
Return maximum passible distance or value between such nodes

// In this problem the restriction of leaf node is removed and you can select any
// two nodes

Note: Value of tree nodes could be negative

Example
Check video
Output => int

Explanation
To understand the solution we can divide the induction step in two cases
    1) When the path goes through the current node (i.e current node is not the
        root of the resulting path that is formed)
    2) When paths top point is current node (i.e. current node is the roo of
        maximum path)

Just the only difference here is that as we have some node value to be negative and 
we need to find path values sum of node in that case, we could directly ignore the nodes
which are negative when starting(at initial/start point when sum is -ve)

*/

#include<bits/stdc++.h>
using namespace std;

// TreeNode Structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Format
int solve(TreeNode* root, int &res){
    // Base Condition (Dependant on problem)
    if(root == NULL)
        return 0;
    
    // Hypothesis
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    // Induction
    // Case 1: Not the root of diameter
    // Only line that is changed than previous question and val in ans line
    int temp = max( max(l,r) + root->val , root->val );  

    // Case 2: Root of diameter
    int ans = max(temp, root->val + l + r); // Calulate final ans dependin on min/max(temp, relation)
    int res = max(res,ans);

    // Final return
    return temp;
}

int main(){
    int res = INT_MIN;
    solve(NULL, res); // Send root of tree in place of Null
    cout<<res;
}