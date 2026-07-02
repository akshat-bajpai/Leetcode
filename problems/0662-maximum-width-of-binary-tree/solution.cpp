class Solution {
public:
    int widthOfBinaryTree(TreeNode* root){
        long long width=0;
        queue<pair<TreeNode*, long long>> q;
        if (root) q.push({root,0});
        while (!q.empty()){
            int n=q.size();
            long long first=q.front().second;
            long long last;
            for (int i=0;i<n;i++){
                auto p=q.front();
                q.pop();
                TreeNode* node=p.first;
                long long index=p.second-first;
                last=index;
                if (node->left){
                    q.push({node->left,index*2+1});
                }
                if (node->right){
                    q.push({node->right,index*2+2});
                }
            }
            width=max(width,last+1);
        }
        return width;
    }
};
