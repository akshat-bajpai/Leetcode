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
    bool isBalanced(TreeNode* root) {
        return (dHeight(root)!=-1);
    }

    int dHeight(TreeNode* root){
        if (root==NULL) return 0;
        int lh=dHeight(root->left);
        int rh=dHeight(root->right);
        if (lh==-1 || rh==-1) return -1;
        if (abs(lh-rh)>1) return -1;
        return (max(lh,rh))+1;
    }
};
