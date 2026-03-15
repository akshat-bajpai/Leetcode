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
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int,int>& hash){
        if (inStart>inEnd || postStart> postEnd) return NULL;

        TreeNode* root=new TreeNode(postorder[postEnd]);
        int inPosition=hash[postorder[postEnd]];
        root->left=buildTree(inorder,inStart,inPosition-1,postorder,postStart,postStart+inPosition-inStart-1,hash);
        root->right=buildTree(inorder,inPosition+1,inEnd,postorder,postStart+inPosition-inStart,postEnd-1,hash);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> hash;

        for (int i=0;i<inorder.size();i++){
            hash[inorder[i]]=i;
        }

        return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hash);
    }
};
