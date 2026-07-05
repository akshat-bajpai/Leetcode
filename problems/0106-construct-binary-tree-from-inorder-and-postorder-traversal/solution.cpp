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
    TreeNode* build(vector<int>& inorder,int instart, int inend, vector<int>& postorder, int poststart, int postend, map<int,int>& mpp){
        if (poststart>postend) return NULL;
        TreeNode* newNode=new TreeNode(postorder[postend]);
        int inpos=mpp[postorder[postend]];
        int offset=inend-inpos;
        newNode->right=build(inorder,inpos+1,inend,postorder,postend-offset, postend-1,mpp);
        newNode->left=build(inorder,instart,inpos-1,postorder,poststart,postend-offset-1,mpp);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for (int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }
};
