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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        bool oddLevel=false;
        vector<int> prev;
        while (!q.empty()){
            int sz=q.size();
            vector<int> temp;
            for (int i=0;i<sz;i++){
                if (!oddLevel){
                    TreeNode* top=q.front();
                    q.pop();
                    if (top->left){
                        q.push(top->left);
                        temp.push_back(top->left->val);
                    }
                    if (top->right){
                        q.push(top->right);
                        temp.push_back(top->right->val);
                    }
                }else{
                    TreeNode* top=q.front();
                    q.pop();
                    top->val=prev.back();
                    prev.pop_back();
                    if (top->left){
                        q.push(top->left);
                    }
                    if (top->right){
                        q.push(top->right);
                    }
                }
            }
            oddLevel=!oddLevel;
            prev=temp;
        }
        return root;
    }
};
