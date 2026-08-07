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
    TreeNode* build(vector<int>& nums, int startIndex, int endIndex){
        if (startIndex>endIndex) return NULL;
        int maxiIndex=startIndex;
        for (int i=startIndex;i<=endIndex;i++){
            if (nums[i]>nums[maxiIndex]) maxiIndex=i;
        }
        TreeNode* newNode=new TreeNode(nums[maxiIndex]);
        newNode->left=build(nums,startIndex,maxiIndex-1);
        newNode->right=build(nums,maxiIndex+1,endIndex);
        return newNode;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
};
