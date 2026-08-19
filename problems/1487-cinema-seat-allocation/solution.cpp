class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        int ans=2*n;
        int i=0;
        while (i<reservedSeats.size()){
            int row=reservedSeats[i][0];
            vector<int> temp(11,0);
            while (i<reservedSeats.size() && reservedSeats[i][0]==row){
                temp[reservedSeats[i][1]]=1;
                i++;
            }
            bool left=false;
            if (temp[2]==1 || temp[3]==1 || temp[4]==1 || temp[5]==1) left=true;
            bool middle=false;
            if (temp[4]==1 || temp[5]==1 || temp[6]==1 || temp[7]==1) middle=true;
            bool right=false;
            if (temp[6]==1 || temp[7]==1 || temp[8]==1 || temp[9]==1) right=true;
            if (!left && !right) continue;
            else if (!left && !middle)ans--;
            else if (!middle && !right) ans--;
            else if (!left || !middle || !right) ans--;
            else ans-=2;
        }
        return ans;
    }
};
