class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort (arr.begin(), arr.end());
        int mini = INT_MAX;
        vector<vector<int>> res;
        for (int i = 1; i<arr.size(); i++) {
            int diff = arr[i] - arr[i-1];
            if (diff < mini) {
                res.clear();
                mini = diff;
                res.push_back({arr[i-1], arr[i]});
            } else if (diff == mini) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};