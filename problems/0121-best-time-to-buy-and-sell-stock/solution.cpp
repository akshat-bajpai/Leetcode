class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int lowest=prices[0];
        for (int i=1;i<prices.size();i++){
            if (prices[i]<lowest){
                lowest=prices[i];
                continue;
            }
            maxi=max(prices[i]-lowest,maxi);
        }
        return maxi;
    }
};
