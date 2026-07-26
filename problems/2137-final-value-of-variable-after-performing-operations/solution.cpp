class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X=0;
        for (int i=0;i<operations.size();i++){
            string op=operations[i];
            for (int j=0;j<op.size();j++){
                if (op[j]=='+'){
                    X++;
                    break;
                }else if (op[j]=='-'){
                    X--;
                    break;
                }
            }
        }
        return X;
    }
};
