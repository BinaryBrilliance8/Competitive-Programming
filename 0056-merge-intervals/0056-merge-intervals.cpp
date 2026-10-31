class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> interval = intervals[i];
            if (interval[0] <= prev[1]) {
                prev[1] = max(prev[1], interval[1]);
            } else {
                merged.push_back(prev);
                prev = interval;
            }
        }

        merged.push_back(prev);
        return merged;


        // sort (intervals.begin(), intervals.end());
        // vector<vector<int>> ans;
        // for (int i = 0; i < intervals.size(); i++) {
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];
        //     if (!ans.empty() && end <= ans.back()[1]) {
        //         continue;
        //     } 
        //     for (int j = i + 1; j < intervals.size(); j++) {
        //         if (intervals[j][0] <= end) {
        //             end = max(end, intervals[j][1]);
        //         } else {
        //             break;
        //         }
        //     }
        //     ans.push_back({start, end});
        // }     
        // return ans;

        int n = intervals.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (res.empty() || intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        } 
        return res;
    }
};