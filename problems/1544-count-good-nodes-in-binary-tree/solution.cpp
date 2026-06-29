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
    void dfs (TreeNode* root, int& count, int& prevValue){
        if (root==NULL) return;
        if (root->val>=prevValue){
            count++;
        }
        int temp=prevValue;
        prevValue=max(prevValue,root->val);
        dfs(root->left,count,prevValue);
        dfs(root->right,count,prevValue);
        prevValue=temp;
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        int prevValue=INT_MIN;
        dfs(root,count,prevValue);
        return count;
    }
};
