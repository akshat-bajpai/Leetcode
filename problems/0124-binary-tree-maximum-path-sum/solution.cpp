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
    int maxSum=INT_MIN;
    int helper(TreeNode* root){
        if (root==NULL) return 0;
        int lMax=max(0,helper(root->left));
        int rMax=max(0,helper(root->right));
        maxSum=max(maxSum,root->val+lMax+rMax);
        return max(lMax,rMax)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
