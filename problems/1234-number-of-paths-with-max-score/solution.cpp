class Solution {
public:
    int mod=1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<int>>score(n,vector<int>(n,-1));
        vector<vector<int>> ways(n,vector<int>(n,0));
        score[n-1][n-1]=0;
        ways[n-1][n-1]=1;
        for (int i=n-1;i>=0;i--){
            for (int j=n-1;j>=0;j--){
                if (board[i][j]=='X') continue;
                if (i==n-1 && j==n-1) continue;
                int best=-1;
                int cnt=0;
                if (i+1<n && score[i+1][j]!=-1){
                    if (score[i+1][j]>best){
                        best=score[i+1][j];
                        cnt=ways[i+1][j];
                    }else if (score[i+1][j]==best){
                        cnt=(cnt+ways[i+1][j])%mod;
                    }
                }
                if (j+1<n && score[i][j+1]!=-1){
                    if (score[i][j+1]>best){
                        best=score[i][j+1];
                        cnt=ways[i][j+1];
                    }else if (score[i][j+1]==best){
                        cnt=(cnt+ways[i][j+1])%mod;
                    }
                }
                if (i+1<n && j+1<n && score[i+1][j+1]!=-1){
                    if (score[i+1][j+1]>best){
                        best=score[i+1][j+1];
                        cnt=ways[i+1][j+1];
                    }else if (score[i+1][j+1]==best){
                        cnt=(cnt+ways[i+1][j+1])%mod;
                    }
                }
                if (best==-1) continue;
                score[i][j]=best;
                if (board[i][j]!='S' && board[i][j]!='E') score[i][j]+=board[i][j]-'0';

                ways[i][j]=cnt;
            }
        }

        if (score[0][0]==-1) return {0,0};
        return {score[0][0],ways[0][0]};

    }
};
