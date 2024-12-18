class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<int, int> m;
        priority_queue<pair<int, int>> pq;

        // Count frequencies of each character
        for (char c : s) {
            m[c - 'a']++;
        }

        // Push characters into the priority queue
        for (auto it : m) {
            pq.push({it.first, it.second});
        }

        string res = "";

        while (!pq.empty()) {
            auto [topChar, topFreq] = pq.top(); // Get the most frequent character
            pq.pop();

            char ch = topChar + 'a'; // Convert to character

            // Add the character to the result up to repeatLimit times or its frequency
            int addCount = min(repeatLimit, topFreq);
            res.append(addCount, ch);
            topFreq -= addCount;

            // If the character's frequency is greater than 0, handle subsequent characters
            if (topFreq > 0) {
                if (pq.empty()) {
                    // If there's no other character to interleave, stop
                    break;
                }

                // Get the second most frequent character
                auto [secondChar, secondFreq] = pq.top();
                pq.pop();

                char ch2 = secondChar + 'a'; // Convert to character

                // Add the second most frequent character to interleave
                res.push_back(ch2);
                secondFreq--;

                // Push back remaining characters into the priority queue
                if (secondFreq > 0) {
                    pq.push({secondChar, secondFreq});
                }

                pq.push({topChar, topFreq});
            }
        }

        return res;
    }
};
