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
    int lheight(TreeNode* root){
        int h=0;
        while (root){
            root=root->left;
            h++;
        }
        return h;
    }
    int rHeight(TreeNode* root){
        int h=0;
        while (root){
            root=root->right;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        int lh=lheight(root);
        int rh=rHeight(root);
        if (lh==rh) return pow(2,lh)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};
