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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> st;
        if (root) st.push(root);
        while (!st.empty()){
            int s=st.size();
            vector<int> level;
            for (int i=0;i<s;i++){
                TreeNode* top=st.front();
                st.pop();
                level.push_back(top->val);
                if (top->left) st.push(top->left);
                if (top->right) st.push(top->right);
            }
            ans.push_back(level);
        }
        return ans;
    }

};
