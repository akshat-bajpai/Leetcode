class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        int maxi=candies[0];
        for (int i=1;i<candies.size();i++){
            maxi=max(maxi,candies[i]);
        }
        vector<bool> ans(n,false);
        for (int i=0;i<candies.size();i++){
            if (candies[i]+extraCandies>=maxi) ans[i]=true;
        }
        return ans;
    }
};
