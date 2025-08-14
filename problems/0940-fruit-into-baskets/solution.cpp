class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int l=0;
        int r=0;
        int maxi=0;

        map<int,int> mpp;

        while (r<fruits.size()){
            if (mpp.size()<2){
                if (mpp.find(fruits[r])==mpp.end()){
                    mpp[fruits[r]]=1;
                }else{
                    mpp[fruits[r]]++;
                }
            }else{
                if (mpp.find(fruits[r])!=mpp.end()){
                    mpp[fruits[r]]++;
                }else{
                    int type=fruits[l];
                    while (l<=r){
                        type=fruits[l];
                        mpp[type]--;
                        if (mpp[type]==0){
                            mpp.erase(type);
                            l++;
                            break;
                        }
                        l++;
                    }
                    mpp[fruits[r]]=1;
                }
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
