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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size()-1;
        return solve(0,size,0,size,preorder,inorder);
    }
    TreeNode* solve(int pi,int ps, int ii, int is, vector<int>&pre,vector<int>&in)
    {
        if(pi>ps||ii>is)
        return nullptr;
        int ind = find(in.begin(),in.end(),pre[pi])-in.begin();
        TreeNode* root = new TreeNode(pre[pi]);
        root->left = solve(pi+1,pi+ind-ii,ii,ind-1,pre,in);
        root->right = solve(pi+ind-ii+1,ps,ind+1,is,pre,in);
        return root;
    }
};