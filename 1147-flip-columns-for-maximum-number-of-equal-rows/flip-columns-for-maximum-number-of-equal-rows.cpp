class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<vector<int>, int> frequencyMap;
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            vector<int> originalRow = matrix[i];
            vector<int> invertedRow(m);

            // Create the inverted row
            for (int j = 0; j < m; j++) {
                invertedRow[j] = !originalRow[j];
            }

            // Use the smaller representation between original and inverted for frequency counting
            if (frequencyMap.find(originalRow) != frequencyMap.end()) {
                frequencyMap[originalRow]++;
            } else if (frequencyMap.find(invertedRow) != frequencyMap.end()) {
                frequencyMap[invertedRow]++;
            } else {
                frequencyMap[originalRow]++;
            }
        }

        // Find the maximum frequency
        int maxRows = 0;
        for (auto& entry : frequencyMap) {
            maxRows = max(maxRows, entry.second);
        }

        return maxRows;
    }
};
