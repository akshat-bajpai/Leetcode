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
    int count=0;
    vector<int> helper(TreeNode* root){
        if (root==NULL) return {0,0};
        auto left=helper(root->left);
        auto right=helper(root->right);
        int numCounts=left[1]+right[1]+1;
        int sum=root->val+left[0]+right[0];
        if (sum/numCounts==root->val) count++;
        return {sum,numCounts};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return count;
    }
};
