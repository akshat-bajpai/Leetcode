class Solution {
public:
    int percentageLetter(string s, char letter) {
        int d=s.size();
        int n=0;
        for (int i=0;i<d;i++){
            if (s[i]==letter) n++;
        }
        return ((n*100)/d);
    }
};
