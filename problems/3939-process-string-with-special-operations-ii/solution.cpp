class Solution {
public:
    char processStr(string s, long long k) {
        long long length=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='*'){
                if (length){
                    length--;
                }

            }else if (s[i]=='#'){
                length*=2;

            }else if (s[i]=='%'){
                continue;

            }else{
                length++;
            }
        }

        if (k+1>length){
            return '.';
        }

        for (int i=s.size()-1;i>=0;i--){
            if (s[i]=='*'){
                length++;
            }else if (s[i]=='#'){
                if (k+1>(length+1)/2){
                    k-=length/2;
                }
                length=(length+1)/2;
            }else if (s[i]=='%'){
                k=length-k-1;
            }else{
                if (k+1==length){
                    return s[i];
                }else{
                    length--;
                }
            }
        }
        return '.';
    }
};
