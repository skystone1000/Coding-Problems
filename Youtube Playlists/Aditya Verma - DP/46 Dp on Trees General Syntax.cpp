/*

Aditya Verma - DP Playlist - 47 Dp on Trees General Syntax

Recursion general syntax

int function(<---INPUT--->){
    1) Base Condition

    2) Hypothesis (DO not question how this will give you answer)
        Go on calling recursively and hit base condition and 
        it goes on building up with induction step

    3) Induction
        Calculate ans for current node by taking 
}


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
    int temp = 1 + max(l,r); // Calulate temporary value , this is for diameter
    int ans = max(temp, 1 + l + r); // Calulate final ans dependin on min/max(temp, relation)
    int res = max(res,ans);

    // Final return
    return temp;
}

int main(){
    int res = INT_MIN;
    solve(NULL, res); // Send root of tree
    cout<<res;
}