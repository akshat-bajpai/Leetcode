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
    void dfsParentMarking(TreeNode* root, TreeNode* parent, map<TreeNode*, TreeNode*>& mpp){
        if (root==NULL) return;
        mpp[root]=parent;
        dfsParentMarking(root->left,root,mpp);
        dfsParentMarking(root->right,root,mpp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root==NULL) return {};
        map<TreeNode*,TreeNode*> parent;
        dfsParentMarking(root,NULL,parent);

        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({target,nullptr});
        int dist=0;
        vector<int> ans;
        while(!q.empty()){
            int n=q.size();
            for (int i=0;i<n;i++){
                if (dist==k){
                    TreeNode* top=q.front().first;
                    q.pop();
                    ans.push_back(top->val);
                }else{
                    TreeNode* top=q.front().first;
                    TreeNode* papa=q.front().second;
                    q.pop();
                    if (top->left && top->left!=papa) q.push({top->left,top});
                    if (top->right && top->right!=papa) q.push({top->right,top});
                    if (parent[top] && parent[top]!=papa) q.push({parent[top],top});
                }
            }
            dist++;
        }
        return ans;
        
    }
};
