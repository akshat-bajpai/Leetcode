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
    bool isMirror(TreeNode* a, TreeNode* b){
        if (a==NULL || b==NULL) return a==b;
        if (a->val==b->val && isMirror(a->right,b->left) && isMirror(a->left, b->right) ) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return false;
        if (isMirror(root->left,root->right)) return true;
        return false;
    }
};
