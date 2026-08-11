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
    int helper(TreeNode* root, TreeNode* parent, TreeNode* grandParent){
        if (root==NULL) return 0 ;
        int l=0,r=0;
        if (root->left){
            l=helper(root->left,root,parent);
        }
        if (root->right){
            r=helper(root->right,root,parent);
        }
        int sum=l+r;
        if (grandParent && grandParent->val%2==0) sum+=root->val;
        return sum;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root,NULL,NULL);
    }
};
