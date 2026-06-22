class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=n*n;
        int xr=0;
        for (int i=0;i<m;i++){
            xr=xr^grid[i/n][i%n];
            xr=xr^(i+1);
        }
        int bitNo=0;
        while (true){
            if ((xr & (1<<bitNo))!=0){
                break;
            }
            bitNo++;
        }
        int ones=0;
        int zeroes=0;

        for (int i=0;i<m;i++){
            if ((grid[i/n][i%n] & (1<<bitNo))!=0){
                ones=ones^grid[i/n][i%n];
            }else{
                zeroes=zeroes^grid[i/n][i%n];
            }
        }

        for (int i=1;i<=m;i++){
            if ((i & (1<<bitNo))!=0){
                ones=ones^i;
            }else{
                zeroes=zeroes^i;
            }
        }

        for (int i=0;i<m;i++){
            if (grid[i/n][i%n]==ones){
                return {ones,zeroes};
            }
        }

        return {zeroes,ones};
        
    }
};
