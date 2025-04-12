
class Solution {
public:
    vector<long long> factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

    static long long create(int num, int n) {
        long long res = num;
        long long pro = pow(10, n - 1);
        n /= 2;
        while (num > 0 && n > 0) {
            res += (num % 10) * pro;
            pro /= 10;
            num /= 10;
            n--;
        }
        return res;
    }

    static long long permutation(long long n, const vector<long long>& fact) {
        int arr[11] = {0};
        string s = to_string(n);
        for (char c : s) {
            arr[c - '0']++;
        }

        long long totalFreq = fact[s.size()];
        long long res = 1;
        for (int i = 0; i < 11; ++i) {
            res *= fact[arr[i]];
        }

        totalFreq /= res;
        if (arr[0] == 0) {
            return totalFreq;
        }

        res = 1;
        arr[0]--;
        long long total = fact[s.size() - 1];
        for (int i = 0; i < 11; ++i) {
            res *= fact[arr[i]];
        }
        total /= res;

        return totalFreq - total;
    }

    static bool palindrome(long long num, unordered_set<string>& mh) {
        string s = to_string(num);
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        sort(s.begin(), s.end());
        if (mh.count(s)) return false;

        mh.insert(s);
        return true;
    }

    long long countGoodIntegers(int n, int k) {
        unordered_set<string> mh;
        int m = (n + 1) / 2;
        long long till = pow(10, m);
        long long ans = 0;

        for (long long i = 0; i < till; ++i) {
            long long x = create(i, n);
            if (x % k == 0 && palindrome(x, mh)) {
                ans += permutation(x, factorial);
            }
        }

        return ans;
    }
};