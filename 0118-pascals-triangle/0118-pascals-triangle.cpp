class Solution {
public:
    vector<int> helper(int n) {
        long long ans = 1;
        vector<int> res;

        res.push_back(ans);

        for (int col = 1; col < n; col++) {
            ans = ans * (n - col);
            ans = ans / col;
            res.push_back(ans);
        }

        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 1; i <= numRows; i++) {
            vector<int> temp = helper(i);
            res.push_back(temp);
        }

        return res;
    }
};