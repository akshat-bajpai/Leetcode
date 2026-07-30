class Solution {
public:
    int minimumPushes(string word) {
        int s=word.size();
        if (s<=8) return s;
        int ans=0;
        int multi=1;
        while (s){
            s-=8;
            ans+=multi*8;
            multi++;
            if (s<=8) break;
        } 
        ans+=multi*s;
        return ans;
    }
};
