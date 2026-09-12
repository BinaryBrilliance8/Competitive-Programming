class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> pos[101];

        // Store positions of every value
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = 0;

        // Check every possible value
        for (int x = 1; x <= 100; x++) {
            if (pos[x].size() != 3)
                continue;

            int i1 = pos[x][0];
            int i2 = pos[x][1];
            int i3 = pos[x][2];

            if (i2 - i1 == i3 - i2)
                ans++;
        }

        return ans;
    }
};