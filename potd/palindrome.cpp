#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper function to compute the LCS
    int lcs(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int idx1 = 1; idx1 <= n; idx1++) {
            for (int idx2 = 1; idx2 <= m; idx2++) {
                if (s[idx1 - 1] == t[idx2 - 1])
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                else
                    dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
            }
        }
        return dp[n][m];
    }

    // Main function to find the minimum number of insertions to make the string a palindrome
    int countMin(string s) {
        // Reverse the string to find the LCS with the original string
        string t = s;
        reverse(t.begin(), t.end());
        int res = lcs(s, t);
        // The minimum number of insertions is the length of the string minus the LCS length
        return s.size() - res;
    }
};

int main() {
    Solution solution;
    string s = "abcda";
    cout << "Minimum insertions to make the string a palindrome: " << solution.countMin(s) << endl;
    return 0;
}
