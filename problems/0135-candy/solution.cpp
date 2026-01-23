class Solution {
public:
    int candy(vector<int>& ratings) {
        int mini=ratings.size();
        vector<int> l(ratings.size(),0);
        vector<int> r(ratings.size(),0);

        l[0]=1;
        int last=1;
        for (int i=1;i<ratings.size();i++){
            if (ratings[i]>ratings[i-1]){
                l[i]=last+1;
                last=l[i];
            }else{
                l[i]=1;
                last=l[i];
            }
        }

        last=1;
        r[ratings.size()-1]=1;
        int n=ratings.size();
        for (int i=n-2;i>=0;i--){
            if (ratings[i]>ratings[i+1]){
                r[i]=last+1;
                last=r[i];
            }else{
                r[i]=1;
                last=r[i];
            }
        }

        int sum=0;

        for (int i=0;i<ratings.size();i++){
            l[i]=max(l[i],r[i]);
            sum+=l[i];
        }

        return sum;


    }
};
