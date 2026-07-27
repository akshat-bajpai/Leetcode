class Solution {
public:
    void inorder(TreeNode* root, vector<int>& order) {
        if (root==NULL) return;
        inorder(root->left, order);
        order.push_back(root->val);
        inorder(root->right, order);
    }
    void fill(TreeNode* root, vector<int>& order, int &idx) {
        if (root==NULL) return;
        fill(root->left, order, idx);
        root->val = order[idx++];
        fill(root->right, order, idx);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> order;
        inorder(root, order);
        int n = order.size();
        for (int i = n - 2; i >= 0; i--) {
            order[i] += order[i + 1];
        }
        int idx = 0;
        fill(root, order, idx);
        return root;
    }
};
