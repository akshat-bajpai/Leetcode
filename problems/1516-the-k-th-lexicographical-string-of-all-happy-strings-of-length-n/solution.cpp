class Solution {
public:
    void generate(int n, string res,vector<string>& resArr){
        if (n==0){
            resArr.push_back(res);
            return ;
        }
        if (res.empty() || res.back()!='a') generate(n-1,res+'a',resArr);
        if (res.empty() || res.back()!='b') generate(n-1,res+'b',resArr);
        if (res.empty() || res.back()!='c') generate (n-1,res+'c',resArr);

    }
    string getHappyString(int n, int k) {
        vector<string> resArr;
        generate(n,"",resArr);
        sort(resArr.begin(),resArr.end());
        if (resArr.size()<k) return "";
        return resArr[k-1];
    }
};
