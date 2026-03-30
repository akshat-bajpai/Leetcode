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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder,i,INT_MAX);
    }

    TreeNode* helper(vector<int>& preorder, int& i, int ub){
        if (preorder.size()==i || preorder[i]>ub) return NULL;
        TreeNode* newNode=new TreeNode(preorder[i]);
        i++;
        newNode->left=helper(preorder,i,newNode->val);
        newNode->right=helper(preorder,i,ub);
        return newNode;
    }
};
