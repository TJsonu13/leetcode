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
int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        solve(root,0);
        return ans;
    }
    int solve(TreeNode* root, int sum)
    {
        if(!root)
        return 0;
        int left = max(0,solve(root->left,sum));
        int right = max(0,solve(root->right, sum));
        ans = max(ans,left+right+root->val);
        return root->val+max(left,right);
    }
};