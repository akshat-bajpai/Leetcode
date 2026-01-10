class Solution {
    static bool comp(vector<int>&a,vector<int>&b){
        if (a[1]>=b[1]) return true;
        return false;
    }

  public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(),boxTypes.end(),comp);

        int c=0;
        int sum=0;

        for(int i=0;i<boxTypes.size();i++){

            if (boxTypes[i][0]+c<=truckSize){
                sum+=boxTypes[i][0]*boxTypes[i][1];
                c+=boxTypes[i][0];
            }else{
                sum+=(truckSize-c)*boxTypes[i][1];
                break;
            }
        }

        return sum;
    }
};
