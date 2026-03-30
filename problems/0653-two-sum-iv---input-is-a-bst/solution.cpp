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
class BSTIterator{
private:
    stack<TreeNode*> st;
    bool reverse=true;

public :
    BSTIterator(TreeNode* root,bool r){
        reverse=r;
        helper(root);

    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* ans=st.top();
        st.pop();
        if (reverse==true){
            helper(ans->left);
        }else{
            helper(ans->right);
        }
        return ans->val;
    }

    void helper(TreeNode* root){
        while (root!=NULL){
            st.push(root);
            if (reverse==true){
                root=root->right;
            }else{
                root=root->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i=l.next();
        int j=r.next();

        while (i<j){
            if (i+j==k) return true;
            else if (i+j>k) j=r.next();
            else i=l.next();
        }
        return false;

    }
};
