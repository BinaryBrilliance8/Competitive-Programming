class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int mx = *max_element(candies.begin(), candies.end());

        for (int i = 0; i < candies.size(); i++) {
            ans.push_back(candies[i] + extraCandies >= mx);
        }

        return ans;
    }
};