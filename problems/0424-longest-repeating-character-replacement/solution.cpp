class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxf=0;
        int maxlen=0;
        map<char,int>mpp;

        while (r<s.size()){
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);

            if ((r-l+1)-maxf>k){
                mpp[s[l]]--;
                l++;
            }

            maxlen=max((r-l+1),maxlen);
            r++;
        }
        return maxlen;
    }
};
