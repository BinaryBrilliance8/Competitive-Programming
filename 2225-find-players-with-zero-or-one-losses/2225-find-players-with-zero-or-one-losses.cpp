class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        unordered_map<int,int> mpp;

        for (int i = 0; i < matches.size(); i++) {
            int loser = matches[i][1];
            mpp[loser]++;
        }

        vector<int> notLost;
        vector<int> lostOnce;

        for (int i = 0; i < matches.size(); i++) {

            int winner = matches[i][0];
            int loser = matches[i][1];

            if (mpp.find(winner) == mpp.end()) {
                notLost.push_back(winner);
                mpp[winner] = 2;
            }

            if (mpp[loser] == 1) {
                lostOnce.push_back(loser);
            }
        }

        sort(begin(notLost), end(notLost));
        sort(begin(lostOnce), end(lostOnce));

        return {notLost, lostOnce};
    }
};