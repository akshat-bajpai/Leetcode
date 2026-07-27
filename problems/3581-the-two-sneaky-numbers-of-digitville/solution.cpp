class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        int m = n - 2;
        int sum = 0, sumSq = 0;
        for (int x : nums) {
            sum += x;
            sumSq +=x * x;
        }
        int trueSum = m * (m - 1) / 2;
        int trueSumSq = m * (m - 1) * (2 * m - 1) / 6;

        int S = sum - trueSum;
        int Q = sumSq - trueSumSq;

        int ab = (S * S - Q) / 2;
        int d = sqrt(S * S - 4 * ab);

        return {((S + d) / 2),((S - d) / 2)};
    }
};
