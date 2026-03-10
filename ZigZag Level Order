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
        int toggle=0;
        vector<vector<int>> ans;
        if (root==NULL) return ans;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            int n=q.size();

            vector<int> temp(n);
            if (toggle==0){
                for (int i=0;i<n;i++){
                    temp[i]=q.front()->val;
                    if (q.front()->left) q.push(q.front()->left);
                    if (q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
            }else{
                for (int i=n-1;i>=0;i--){
                    temp[i]=q.front()->val;
                    if (q.front()->left) q.push(q.front()->left);
                    if (q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
            }
            toggle=(toggle+1)%2;
            ans.push_back(temp);
        }
        return ans;
    }
};
