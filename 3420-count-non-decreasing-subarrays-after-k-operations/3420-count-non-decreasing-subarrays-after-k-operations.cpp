#include <vector>
#include <deque>

using namespace std;

class Solution {
    struct Block {
        long long val; // Prefix maximum governing this block
        int l, r;      // Inclusive index range [l, r]
    };

public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<Block> dq;
        long long total_ans = 0;
        long long current_cost = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; --l) {
            long long x = nums[l];
            int block_end = l;

            // Merge blocks from the front that are dominated by nums[l]
            while (!dq.empty() && dq.front().val <= x) {
                auto front_block = dq.front();
                dq.pop_front();
                current_cost += (x - front_block.val) * (front_block.r - front_block.l + 1);
                block_end = front_block.r;
            }
            dq.push_front({x, l, block_end});

            // Shrink the window from the right while cost exceeds k
            while (current_cost > k) {
                current_cost -= (dq.back().val - nums[r]);
                dq.back().r--;
                if (dq.back().l > dq.back().r) {
                    dq.pop_back();
                }
                r--;
            }

            // All subarrays starting at l and ending in [l, r] are valid
            total_ans += (r - l + 1);
        }

        return total_ans;
    }
};