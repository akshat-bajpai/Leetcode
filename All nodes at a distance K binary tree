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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (root==NULL) return ans;
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for (int i=0;i<n;i++){
                if (q.front()->left){
                    parent[q.front()->left]=q.front();
                    q.push(q.front()->left);
                }
                if (q.front()->right){
                    parent[q.front()->right]=q.front();
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }

        map<TreeNode*, bool> visited;

        q.push(target);
        visited[target]=true;
        int current=0;
        while(!q.empty()){
            int n=q.size();
            if (current==k) break;
            current++;
            for (int i=0;i<n;i++){
                if (q.front()->left && !visited[q.front()->left]){
                    q.push(q.front()->left);
                    visited[q.front()->left]=true;
                }
                if (q.front()->right && !visited[q.front()->right]){
                    q.push(q.front()->right);
                    visited[q.front()->right]=true;
                }
                if (parent[q.front()] && !visited[parent[q.front()]]){
                    q.push(parent[q.front()]);
                    visited[parent[q.front()]]=true;
                }
                q.pop();
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
