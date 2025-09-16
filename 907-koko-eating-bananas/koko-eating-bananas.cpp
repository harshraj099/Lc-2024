class Solution {
public:
    long long f(int no, vector<int>& piles) {
        long long time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += (piles[i] + no - 1) / no;  // cleaner ceiling division
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long time = f(mid, piles);
            if (time == h) {
                ans = mid;
                high = mid - 1;
            }
           else if (time < h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
