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
    TreeNode* build(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, unordered_map<int,int>& mpp){
        if (prestart>preend) return NULL;
        TreeNode* newNode=new TreeNode(preorder[prestart]);
        int inpos=mpp[preorder[prestart]];
        int left=inpos-instart;
        newNode->left=build(preorder,prestart+1,prestart+left,inorder,instart,inpos-1,mpp);
        newNode->right=build(preorder,prestart+left+1,preend,inorder,inpos+1,inend,mpp);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        for (int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    }
};
