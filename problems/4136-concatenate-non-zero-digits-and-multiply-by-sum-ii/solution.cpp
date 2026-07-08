class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefCnt(n + 1, 0);
        vector<int> digits;
        for (int i = 0; i < n; i++) {
            prefCnt[i + 1] = prefCnt[i];
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                prefCnt[i + 1]++;
            }
        }
        int m = digits.size();
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        vector<long long> prefVal(m + 1, 0);
        vector<long long> prefSum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefVal[i + 1] = (prefVal[i] * 10 + digits[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digits[i];
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int L = prefCnt[l];
            int R = prefCnt[r + 1];
            int len = R - L;
            long long x =
                (prefVal[R] - prefVal[L] * pow10[len] % MOD + MOD) % MOD;
            long long sum = prefSum[R] - prefSum[L];
            ans.push_back((x * (sum % MOD)) % MOD);
        }
        return ans;
    }
};
