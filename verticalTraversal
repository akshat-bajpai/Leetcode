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
    static bool comp(vector<int>a, vector<int>b){
        if (a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    void helper(TreeNode* root, map<int,vector<vector<int>>>& mp, int& mini, int& maxi, int hL, int vL){
        mini=min(mini,hL);
        maxi=max(maxi,hL);
        vector<int> temp;
        temp.push_back(root->val);
        temp.push_back(vL);
        if (mp.find(hL)==mp.end()){
            mp[hL]={temp};
        }else{
            mp[hL].push_back(temp);
        }
        
        if (root->left){
            helper(root->left,mp,mini,maxi,hL-1,vL+1);
        }

        if (root->right){
            helper(root->right,mp,mini,maxi,hL+1,vL+1);
        }

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root==NULL){
            return ans;
        }
        map<int,vector<vector<int>>> mp;
        int maxi=0;
        int mini=0;
        helper(root,mp,mini,maxi,0,0);

        for (int i=mini;i<=maxi;i++){
            vector<vector<int>> temp=mp[i];
            sort(temp.begin(),temp.end(),comp);
            vector<int>temp2;
            for (int i=0;i<temp.size();i++){
                temp2.push_back(temp[i][0]);
            }
            ans.push_back(temp2);
        }
        return ans;


    }
};
