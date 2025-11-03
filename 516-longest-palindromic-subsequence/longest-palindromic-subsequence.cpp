class Solution {
public:
   int f(int i, int j, string& s, vector<vector<int>>& d) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (d[i][j] != -1) return d[i][j];

        if (s[i] == s[j]) {
            d[i][j] = 2 + f(i + 1, j - 1, s, d);
        } else {
            d[i][j] = max(f(i + 1, j, s, d), f(i, j - 1, s, d));
        }
        return d[i][j];
    }
    int longestPalindromeSubseq(string s) {
       int n = s.size();
        if (n == 0) return 0;
        vector<vector<int>> d(n, vector<int>(n, -1));
        return f(0, n - 1, s, d);
    }
};