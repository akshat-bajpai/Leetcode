class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angleOfHours;
        double angleOfMinutes;

        angleOfHours=30*(hour%12)+(minutes/60.0)*30;
        angleOfMinutes=(minutes/60.0)*360;

        double ans= abs(angleOfMinutes-angleOfHours);
        if (ans>180) return 360-ans;
        return ans;
    }
};
