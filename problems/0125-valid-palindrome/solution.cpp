class Solution {
public:
    bool isPalindrome(string s) {
        string clean="";
        for (char c:s){
            if (isalnum(c)){
                clean+=tolower(c);
            }
        }
        if (clean=="") return true;
        for (int i=0;i<=clean.length()/2;i++){
            if (clean[i]!=clean[clean.length()-i-1]) return false;
        }
        return true;
        
    }
};
