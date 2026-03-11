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
    bool helpFindingPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& ans){
        if (root==NULL) return false;
        
        ans.push_back(root);
        if (root==p) return true;
        if (helpFindingPath(root->left,p,ans) || helpFindingPath(root->right,p,ans)){
            return true;
        }
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p;
        vector<TreeNode*> path_q;
        helpFindingPath(root,p,path_p);
        helpFindingPath(root,q,path_q);
        TreeNode* ans=NULL;
        
        for (int i=0;i<min(path_p.size(),path_q.size());i++){
            if (path_p[i]==path_q[i]){
                ans=path_p[i];
            }
            else break;
        }
        return ans;
        
    }
};
