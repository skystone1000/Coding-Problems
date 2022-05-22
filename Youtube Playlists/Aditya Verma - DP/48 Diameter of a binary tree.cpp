// Aditya Verma - DP Playlist - 48 Diameter of a binary tree

/*
Flow 
    - Problem statement
    - Syntax Discussion
    - Code variation

Q) Given a tree, you need to pick any two leaf nodes, calculate the total(count) number
of nodes in path of those two leaf nodes(including and between). Return maximum passible
distance or count between such leaf nodes

Example
Check video
Output => int

Explanation
To understand the solution we can divide the induction step in two cases
    1) When the path goes through the current node (i.e current node is not the
        root of the resulting path that is formed)
    2) When paths top point is current node (i.e. current node is the roo of
        maximum path)

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
    int temp = 1 + max(l,r); // To return for above recursive call 

    // Case 2: Root of diameter
    int ans = max(temp, 1 + l + r); // Calulate final ans dependin on min/max(temp, relation)
    int res = max(res,ans);

    // Final return
    return temp;
}

int main(){
    int res = INT_MIN;
    solve(NULL, res); // Send root of tree in place of Null
    cout<<res;
}