#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 2; // Any subarray of length 2 always satisfies a * b == gcd(a, b) * lcm(a, b)
        const int MAX_LIMIT = 25200; // max LCM (2520) * max GCD (10)

        for (int i = 0; i < n; ++i) {
            int prod = 1;
            int g = 0;
            int l = 1;

            for (int j = i; j < n; ++j) {
                prod *= nums[j];
                if (prod > MAX_LIMIT) break;

                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if (prod == g * l) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};