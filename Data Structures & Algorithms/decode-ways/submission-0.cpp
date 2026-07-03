class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        int prev2 = 1; // dp[i-2]
        int prev1 = 1; // dp[i-1]

        for (int i = 2; i <= n; i++) {
            char cur = s[i - 1];
            char prevChar = s[i - 2];
            int cur_dp = 0;

            // single digit decode
            if (cur != '0') {
                cur_dp += prev1;
            }

            // two digit decode
            int twoDigit = (prevChar - '0') * 10 + (cur - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                cur_dp += prev2;
            }

            prev2 = prev1;
            prev1 = cur_dp;
        }

        return prev1;
    }
};