class Solution {
public:
//Shreya
    bool isScramble(string s1, string s2) {
          unordered_map<string, bool> memo;
        return helper(s1, s2, memo);
    }

private:
    bool helper(string s1, string s2, unordered_map<string, bool>& memo) {
        if (s1 == s2) return true;

        string key = s1 + "_" + s2;
        if (memo.find(key) != memo.end()) return memo[key];

        // If characters don't match in frequency, return false
        string sorted_s1 = s1, sorted_s2 = s2;
        sort(sorted_s1.begin(), sorted_s1.end());
        sort(sorted_s2.begin(), sorted_s2.end());
        if (sorted_s1 != sorted_s2) return memo[key] = false;

        int n = s1.length();
        for (int i = 1; i < n; ++i) {
            // Without swap
            if (helper(s1.substr(0, i), s2.substr(0, i), memo) &&
                helper(s1.substr(i), s2.substr(i), memo))
                return memo[key] = true;

            // With swap
            if (helper(s1.substr(0, i), s2.substr(n - i), memo) &&
                helper(s1.substr(i), s2.substr(0, n - i), memo))
                return memo[key] = true;
        }

        return memo[key] = false;
    }
};