class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int largestOverlap=0;
        for (int iStart=0;iStart<n;iStart++){
            for (int jStart=0;jStart<n;jStart++){
                int c=0;
                for (int i=iStart;i<n;i++){
                    for (int j=jStart;j<n;j++){
                        if (img1[i][j]==1 && img2[i-iStart][j-jStart]==1) c++;
                    }
                }
                largestOverlap=max(c,largestOverlap);
            }
        }
        for (int iStart=0;iStart<n;iStart++){
            for (int jStart=0;jStart<n;jStart++){
                int c=0;
                for (int i=iStart;i<n;i++){
                    for (int j=jStart;j<n;j++){
                        if (img1[i-iStart][j-jStart]==1 && img2[i][j]==1) c++;
                    }
                }
                largestOverlap=max(c,largestOverlap);
            }
        }
        for (int iStart=0;iStart<n;iStart++){
            for (int jStart=0;jStart<n;jStart++){
                int c=0;
                for (int i=0;i<n-iStart;i++){
                    for (int j=jStart;j<n;j++){
                        if (img1[i][j]==1 && img2[i+iStart][j-jStart]==1) c++;
                    }
                }
                largestOverlap=max(c,largestOverlap);
            }
        }
        for (int iStart=0;iStart<n;iStart++){
            for (int jStart=0;jStart<n;jStart++){
                int c=0;
                for (int i=iStart;i<n;i++){
                    for (int j=0;j<n-jStart;j++){
                        if (img1[i][j]==1 && img2[i-iStart][j+jStart]==1) c++;
                    }
                }
                largestOverlap=max(c,largestOverlap);
            }
        }

        return largestOverlap;
    }
};
