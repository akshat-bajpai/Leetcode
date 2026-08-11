/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(cloned);
        while (!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            if (top->val==target->val) return top;
            if (top->right) q.push(top->right);
            if (top->left) q.push(top->left);
        }
        return NULL;
    }
};
