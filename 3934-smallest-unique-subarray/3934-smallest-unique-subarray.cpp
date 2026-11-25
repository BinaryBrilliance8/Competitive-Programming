#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const uint64_t MOD1 = 1000000007ULL;
        const uint64_t MOD2 = 1000000009ULL;
        const uint64_t BASE1 = 100003ULL;
        const uint64_t BASE2 = 100019ULL;

        vector<uint64_t> h1(n + 1, 0), h2(n + 1, 0);
        vector<uint64_t> p1(n + 1, 1), p2(n + 1, 1);

        // Precompute prefix hashes and powers
        for (int i = 0; i < n; ++i) {
            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2;
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }

        auto hasUnique = [&](int len) -> bool {
            int count = n - len + 1;
            vector<uint64_t> hashes(count);

            for (int i = 0; i < count; ++i) {
                uint64_t v1 = (h1[i + len] + MOD1 - (h1[i] * p1[len]) % MOD1) % MOD1;
                uint64_t v2 = (h2[i + len] + MOD2 - (h2[i] * p2[len]) % MOD2) % MOD2;
                hashes[i] = (v1 << 32) | v2;
            }

            // Sort hashes to check for any element that appears exactly once
            sort(hashes.begin(), hashes.end());
            for (int i = 0; i < count; ++i) {
                bool sameAsLeft = (i > 0 && hashes[i] == hashes[i - 1]);
                bool sameAsRight = (i + 1 < count && hashes[i] == hashes[i + 1]);
                if (!sameAsLeft && !sameAsRight) {
                    return true;
                }
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};