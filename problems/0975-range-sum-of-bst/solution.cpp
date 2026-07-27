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
    int helper(TreeNode* root, int low, int high){
        if (root==NULL) return 0;
        int l=helper(root->left,low,high);
        int r=helper(root->right,low,high);
        return (root->val>=low && root->val<=high)?root->val+l+r:l+r;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return helper(root,low,high);

    }
};
