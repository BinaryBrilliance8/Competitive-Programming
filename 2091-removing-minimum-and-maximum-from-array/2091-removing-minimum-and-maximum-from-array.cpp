class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find positions of minimum and maximum
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        // Which target is more towards the left/right?
        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // CASE 1: Remove both from the front
        int front = right + 1;

        // CASE 2: Remove both from the back
        int back = n - left;

        // CASE 3: Remove left target from FRONT
        //         and right target from BACK
        int both = (left + 1) + (n - right);

        return min({front, back, both});
    }
};