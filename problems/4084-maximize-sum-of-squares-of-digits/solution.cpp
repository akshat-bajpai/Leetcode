class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        while (sum){
            if (sum>9){
                ans+="9";
                sum-=9;
            }else{
                ans+=to_string(sum);
                sum=0;
            }
        }
        if (ans.size()>num) return "";
        while (ans.size()<num){
            ans+="0";
        }
        return ans;
    }
};
