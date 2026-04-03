class NodeValue{
public:
    int leftMax, rightMax, sum;
    NodeValue(int lM,int rM,int s){
        leftMax=lM;
        rightMax=rM;
        sum=s;
    }
};

class Solution {
public:
    int ans = 0;

    NodeValue mS(TreeNode* root){
        if (root==NULL) return NodeValue(INT_MAX,INT_MIN,0);

        NodeValue left=mS(root->left);
        NodeValue right=mS(root->right);

        if (left.rightMax<root->val && right.leftMax>root->val){
            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return NodeValue(
                min(root->val,left.leftMax),
                max(root->val,right.rightMax),
                currSum
            );
        }

        return NodeValue(INT_MIN,INT_MAX,0);
    }

    int maxSumBST(TreeNode* root) {
        mS(root);
        return ans;
    }
};
