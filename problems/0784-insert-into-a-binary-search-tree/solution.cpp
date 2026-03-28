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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* og=root;
        if (root==NULL){
            return new TreeNode(val);
        }
        TreeNode* prev=NULL;
        while (root!=NULL){
            if (root->val>val){
                prev=root;
                root=root->left;
            }else{
                prev=root;
                root=root->right;
            }
        }
        if (val>prev->val){
            prev->right=new TreeNode(val);
        }else{
            prev->left=new TreeNode(val);
        }
        return og;
    }
};
