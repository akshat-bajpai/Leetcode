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

    void fill(TreeNode* root, vector<string>& ans, string path){

        if(root == NULL) return;

        // append current node
        if(path.size() == 0)
            path += to_string(root->val);
        else
            path += "->" + to_string(root->val);

        // leaf node
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
            return;
        }

        fill(root->left, ans, path);
        fill(root->right, ans, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;
        fill(root, ans, "");

        return ans;
    }
};
