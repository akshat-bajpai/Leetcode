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
    TreeNode* insertInBST(vector<int>& arr, int start, int end){
        if (start>end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode* newNode=new TreeNode(arr[mid]);
        newNode->left=insertInBST(arr,start,mid-1);
        newNode->right=insertInBST(arr,mid+1,end);
        return newNode;
    }
    void inorder(TreeNode* root, vector<int>& arr){
        if (root==NULL) return;
        if (root->left) inorder(root->left,arr);
        arr.push_back(root->val);
        if (root->right) inorder(root->right,arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        return insertInBST(arr,0,arr.size()-1);
    }
};
