class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i][buy]=maximum profit starting at ith index and buy constraint=buy (0=can not buy, 1=can buy)
        int n=prices.size();
        vector<int> next(2),cur(2);
        next[0]=0;
        next[1]=0;
        for (int i=n-1;i>=0;i--){
            for (int j=0;j<2;j++){
                if (j==1){
                    cur[j]=max(next[1],next[0]-prices[i]);
                }else{
                    cur[j]=max(next[0],next[1]+prices[i]);
                }
            }
            next=cur;
        }
        return next[1];
    }
};
