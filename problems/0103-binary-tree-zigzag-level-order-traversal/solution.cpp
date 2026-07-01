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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        queue<TreeNode*> q;
        bool forward=false;
        if (root) q.push(root);
        while (!q.empty()){
            int n=q.size();
            vector<int> level(n);
            if (forward){
                for (int i=n-1;i>=0;i--){
                    level[i]=q.front()->val;
                    if (q.front()->left) q.push(q.front()->left);
                    if (q.front()->right) q.push(q.front()->right);
                    q.pop();
                    forward=false;
                }
            }else{
                for (int i=0;i<n;i++){
                    level[i]=q.front()->val;
                    if (q.front()->left) q.push(q.front()->left);
                    if (q.front()->right) q.push(q.front()->right);
                    q.pop();
                    forward=true;
                }
            }
            zigzag.push_back(level);
        }
        return zigzag;
    }
};
