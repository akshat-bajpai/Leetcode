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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        if (root) q.push({root,{0,0}});
        while (!q.empty()){
            pair<TreeNode*,pair<int,int>> p=q.front();
            q.pop();
            int col=p.second.first;
            int row=p.second.second;
            TreeNode* node=p.first;
            mpp[col][row].insert(node->val);
            if (node->left) q.push({node->left,{col-1,row+1}});
            if (node->right) q.push({node->right,{col+1,row+1}});
        }
        vector<vector<int>> ans;
        for (auto it : mpp){
            vector<int> thisCol;
            for (auto iter:it.second){
                for (auto a : iter.second){
                    thisCol.push_back(a);
                }
            }
            ans.push_back(thisCol);
        }
        return ans;
    }
};
