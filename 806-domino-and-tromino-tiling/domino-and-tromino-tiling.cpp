class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp; // Memoization table

    int numTilings(int n) {
        dp.assign(n + 1, vector<int>(2, -1)); // Initialize DP table
        return solve(0, n, false);
    }

    long solve(int i, int n, bool previousGap) {
        if (i > n) return 0;                 // Out of bounds → Invalid tiling
        if (i == n) return !previousGap;     // Valid tiling when no gap remains

        if (dp[i][previousGap] != -1) return dp[i][previousGap]; // Memoization check

        if (previousGap) {  // If previous column had a gap
            return dp[i][previousGap] = (solve(i + 1, n, false) + solve(i + 1, n, true)) % MOD;
        }

        return dp[i][previousGap] = (solve(i + 1, n, false) + solve(i + 2, n, false) + 2L * solve(i + 2, n, true)) % MOD;
    }
};
