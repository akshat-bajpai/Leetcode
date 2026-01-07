class Solution {
public:
    int hammingDistance(int start, int goal) {
        int x=start^goal;
        int c=0;

        if (x==0) return 0;

        while ((x&(x-1))!=0){
            c++;
            x=x&(x-1);
        }

        return c+1;
    }
};
