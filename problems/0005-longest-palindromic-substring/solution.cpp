// f(i,j)->
//     if (i>j) return false;
//     if (i==j) return true
//     if (j=i+1) return s[i]==s[j]
//     if (s[i]==s[j]) return f(i+1,j-1)
//     return false


class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> isPal(n,vector<bool>(n,false));
        for (int i=n-1;i>=0;i--){
            for (int j=i;j<n;j++){
                if (s[i]==s[j]){
                    if (j<=i+1) isPal[i][j]=true;
                    else{
                        isPal[i][j]=isPal[i+1][j-1];
                    }
                }
            }
        }
        int sIndex=0;
        int lIndex=0;
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                if (isPal[i][j]){
                    if (j-i>lIndex-sIndex){
                        sIndex=i;
                        lIndex=j;
                    }
                }
            }
        }
        return s.substr(sIndex,lIndex-sIndex+1);

    }
};
