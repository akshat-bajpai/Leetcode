class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;
        int n=s.size();
        vector<vector<string>> store(numRows,vector<string>(n,""));
        bool down=true;
        int row=0,col=0;
        for (int i=0;i<n;i++){
            store[row][col]=s[i];
            if (down){
                row++;
                if (row==numRows){
                    row=row-2;
                    col++;
                    down=false;
                }
            }else{
                row--;
                col++;
                if (row==-1){
                    row=row+2;
                    down=true;
                }
            }
        }
        string ans="";
        for (int i=0;i<numRows;i++){
            for (int j=0;j<n;j++){
                ans+=store[i][j];
            }
        }
        return ans;
    }
};
