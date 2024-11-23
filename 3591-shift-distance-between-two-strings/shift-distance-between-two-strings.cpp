class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;

        for (int i = 0; i < s.size(); i++) {
            char ini = s[i];
            char aft = t[i];
            if (ini == aft) continue;

            int iniIndex = ini - 'a';
            int aftIndex = aft - 'a';

            // Direct forward cost
            long long forwardCost = 0;
            for (int j = iniIndex; j != aftIndex; j = (j + 1) % 26) {
                forwardCost += nextCost[j];
            }

            // Direct backward cost
            long long backwardCost = 0;
            for (int j = iniIndex; j != aftIndex; j = (j - 1 + 26) % 26) {
                backwardCost += previousCost[j];
            }

            // Minimum of forward and backward costs
            ans += min(forwardCost, backwardCost);
        }

        return ans;
    }
};
