class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxCount = 0; // Max frequency of a single character in the window
        int left = 0, result = 0;
        vector<int> count(26, 0);

        for (int right = 0; right < s.size(); ++right) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            // If more than k chars need replacement, shrink window
            if ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};
