#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        
        // Step 1: Precompute all valid divisors for lengths 1 to N
        vector<vector<int>> divs(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (i % j == 0) {
                    divs[i].push_back(j);
                }
            }
        }
        
        // Step 2: Precompute the minimum changes to make every substring s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            // A semi-palindrome must have a length of at least 2
            for (int j = i + 1; j < n; ++j) {
                int L = j - i + 1;
                int min_changes = 1e9;
                
                for (int d : divs[L]) {
                    int current_changes = 0;
                    int count = L / d; // Characters in each group
                    
                    // Iterate through each independent group
                    for (int g = 0; g < d; ++g) {
                        // Check if the group forms a palindrome
                        for (int step = 0; step < count / 2; ++step) {
                            if (s[i + g + step * d] != s[i + g + (count - 1 - step) * d]) {
                                current_changes++;
                            }
                        }
                    }
                    min_changes = min(min_changes, current_changes);
                }
                cost[i][j] = min_changes;
            }
        }
        
        // Step 3: DP to find minimum cost to partition s into k semi-palindromes
        // dp[p][i] -> Min cost for prefix up to index i divided into p parts
        vector<vector<int>> dp(k + 1, vector<int>(n, 1e9));
        
        // Base case: 1 part
        for (int i = 1; i < n; ++i) {
            dp[1][i] = cost[0][i];
        }
        
        // Build DP table for 2 to k parts
        for (int p = 2; p <= k; ++p) {
            // Minimum index i for p parts of length at least 2 is 2*p - 1
            for (int i = 2 * p - 1; i < n; ++i) {
                // j is the end of the previous partition
                for (int j = 2 * p - 3; j <= i - 2; ++j) {
                    if (dp[p - 1][j] != 1e9) {
                        dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j + 1][i]);
                    }
                }
            }
        }
        
        return dp[k][n - 1];
    }
};