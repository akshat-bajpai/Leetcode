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
    void recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;
        TreeNode* place1=NULL;
        TreeNode* place2=NULL;
        TreeNode* place3=NULL;

        TreeNode* cur=root;

        while (cur){
            if (cur->left==NULL){
                if (cur->val<(prev==NULL?INT_MIN : prev->val)){
                    if (place2==NULL){
                        place1=prev;
                        place2=cur;
                    }else{
                        place3=cur;
                    }
                }
                prev=cur;
                cur=cur->right;
            }else{
                TreeNode* temp=cur->left;
                while (temp->right && temp->right!=cur){
                    temp=temp->right;
                }
                if(temp->right==cur){
                    temp->right=NULL;

                    if (cur->val<(prev==NULL?INT_MIN : prev->val)){
                        if (place2==NULL){
                            place1=prev;
                            place2=cur;
                        }else{
                            place3=cur;
                        }
                    }
                    prev=cur;
                    cur=cur->right;
                }else{
                    temp->right=cur;
                    cur=cur->left;
                }
            }
        }
        if (place3==NULL){
            int temp=place1->val;
            place1->val=place2->val;
            place2->val=temp;
        }else{
            int temp=place1->val;
            place1->val=place3->val;
            place3->val=temp;
        }
    }
};
