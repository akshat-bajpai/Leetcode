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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        stack<TreeNode*> st;
        vector<int> postOrder;
        while (!st.empty() || curr){
            if (curr){
                st.push(curr);
                curr=curr->left;
            }else{
                TreeNode* temp=st.top()->right;
                if (temp==NULL){
                    TreeNode* top=st.top();
                    postOrder.push_back(st.top()->val);
                    st.pop();
                    while (!st.empty() && st.top()->right==top){
                        top=st.top();
                        postOrder.push_back(top->val);
                        st.pop();
                    }
                }else{
                    curr=temp;
                }
            }
        }
        return postOrder;
    }
};
