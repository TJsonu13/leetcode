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
    TreeNode* deleteNode(TreeNode* root, int &key) {
        if(!root)
        return NULL;
        if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else
        {
            if(!root->left&&!root->right)
            return NULL;
            else if(!root->right)
            return root->left;
            else if(!root->left)
            return root->right;
            else
            {
                //finding maximum from left or
                //finding minimum from right;
                TreeNode* t=root->right;
                while(t->left)
                t=t->left;
                root->val=t->val;
                root->right=deleteNode(root->right,t->val);
            }
        }
        return root;
    }
};