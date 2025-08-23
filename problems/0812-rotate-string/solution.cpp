class Solution {
public:
    bool rotateString(string s, string goal) {
        string c=s+s;
        return c.find(goal)!=string::npos && s.length()==goal.length();
    }
};
