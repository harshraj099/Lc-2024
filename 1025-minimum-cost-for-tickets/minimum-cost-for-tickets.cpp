class Solution {
public:
    int f(int idx, int valid, vector<int>& days, vector<int>& costs, int n, vector<vector<int>>& dp) {
        if (idx >= n) return 0;

        // ✅ Use valid as the second memoization parameter
        if (dp[idx][valid] != -1) return dp[idx][valid];

        int minCost = INT_MAX;
        if (valid >= days[idx]) {
            // Skip the current day as it's still covered by a previous ticket
            minCost = f(idx + 1, valid, days, costs, n, dp);
        } else {
            // Buy a new ticket
            minCost = min({
                costs[0] + f(idx + 1, days[idx], days, costs, n, dp),   // 1-day pass
                costs[1] + f(idx + 1, days[idx] + 6, days, costs, n, dp), // 7-day pass
                costs[2] + f(idx + 1, days[idx] + 29, days, costs, n, dp) // 30-day pass
            });
        }

        return dp[idx][valid] = minCost;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int maxDay = days.back() + 30; // Valid range of `valid`
        vector<vector<int>> dp(n, vector<int>(maxDay, -1)); // ✅ Increased range

        return f(0, 0, days, costs, n, dp);
    }
};
