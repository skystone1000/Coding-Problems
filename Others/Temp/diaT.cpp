// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() :val(0),left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x,TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void appendTr(TreeNode* head,char child, int value){
    TreeNode currNode(value);
    if(child == 'L'){
        head->left = &currNode;
    }else{
        head->right = &currNode;
    }
}

bool insert(TreeNode* head,int par, char child, int value){
    if(head == NULL)
        return false;
    if(head->val == par)
        appendTr(head,child,value);
        return true;
    
    bool res1 = insert(head->left, par , child, value);
    
    if(res1) return true;
    
    bool res2 = insert(head->right, par, child, value);
    return res2;
}


int depth(TreeNode *root,int *diameter) {
    if(!root) {
        return 0;
    }
    auto left = depth(root->left,diameter);
    auto right = depth(root->right, diameter);
    *diameter = max(*diameter, left+right);
    return 1 + max(left, right);
}

int dia(TreeNode* root){
    int diameter = 0;
    depth(root, &diameter);
    return diameter;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin>>n;
	string tempStr;
	int rootVal;
	cin>>tempStr>>rootVal;
	TreeNode dummyNode(rootVal);
	TreeNode* head = &dummyNode;
	TreeNode* itr = head;
	cout<<"Starting"<<endl;
	for(int i=0;i<n-1;i++){
	    int par,value;
	    char child;
	    cin>>par;
        cin>>child;
        cin>>value;
	    insert(head,par,child,value);
	   cout<<"inp = "<<i<<endl;
	}
	int ans = dia(head);
	cout<<ans<<endl;
}
