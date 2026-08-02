class Solution {
public:
    string binary(int n){
        string s="";
        while(n){
            s=char('0'+n%2)+s;
            n/=2;
        }
        return s;
    }
    string convertDateToBinary(string date) {
        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,2));
        int day=stoi(date.substr(8,2));
        return binary(year)+"-"+binary(month)+"-"+binary(day);
    }
};
