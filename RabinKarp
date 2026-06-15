#define ll unsigned long long
class Solution {
public:
    bool RabinKarp(string source, string b){
        ll m=1e9+7;
        int ss=source.size();
        int bs=b.size();
        vector<ll> power(ss);
        power[0]=1;
        for (int i=1;i<ss;i++){
            power[i]=(power[i-1]*31)%m;
        }
        vector<ll> hs(ss+1,0);
        for (int i=0;i<ss;i++){
            hs[i+1]=(hs[i]+(source[i]-'a'+1)*power[i])%m;
        }
        ll hb=0;
        for (int i=0;i<bs;i++){
            hb+=((b[i]-'a'+1)*power[i])%m;
        }

        for (int i=0;i<=ss-bs;i++){
            ll delhash=(hs[i+bs]-hs[i]+m)%m;
            if ((hb*power[i]%m)==delhash) return true;
        }

        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int count=1;
        string source=a;
        while (source.size()<b.size()){
            count++;
            source+=a;
        }
        if (source==b) return count;
        if (RabinKarp(source,b)) return count;
        source+=a;
        if (RabinKarp(source,b)) return count+1;
        return -1;
    }
};
