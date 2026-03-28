/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for (int i=0;i<n;i++){
                TreeNode* top=q.front();
                if (top==NULL) ans.push_back("null");
                else ans.push_back(to_string(top->val));
                q.pop();
                if (top){
                    q.push(top->left);
                    q.push(top->right);
                }
            }
        }
        while (!ans.empty() && ans.back()== "null"){
            ans.pop_back();
        }
        string answer="[";
        for (int i=0;i<ans.size();i++){
            if (i==0){
                answer+=ans[i];
            }else{
                answer+=",";
                answer+=ans[i];
            }
        }
        answer+="]";
        return answer;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return NULL;
        data = data.substr(1, data.size() - 2);
        vector<string> nodes;
        string temp = "";
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        nodes.push_back(temp);
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();
            if (i < nodes.size() && nodes[i] != "null") {
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;
            if (i < nodes.size() && nodes[i] != "null") {
                curr->right = new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
