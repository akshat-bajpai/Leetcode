class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        set<int>st;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                for (int k=0;k<n;k++){
                    if (i==j || j==k || k==i) continue;
                    if (digits[k]%2==1) continue;
                    if (digits[i]==0) continue;
                    st.insert(100*digits[i]+10*digits[j]+digits[k]);
                }
            }
        }
        return st.size();
    }
};
