class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int totWaviness=0;
        for (int num=num1;num<=num2;num++){
            if (num<100) continue;
            string s=to_string(num);
            int x=0;
            for (int i=1;i<s.size()-1;i++){
                if ((s[i]>s[i-1] && s[i]>s[i+1]) || (s[i]<s[i-1] && s[i]<s[i+1])){
                    x++;
                }
            }
            totWaviness+=x;
        }
        return totWaviness;
    }
};
